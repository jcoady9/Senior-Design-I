#include "../include/RobotComm.h"
#include <iostream>
#include <fcntl.h> 
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

const char * filename = "testoutput.txt";
int checkSum;
 
/*
**method for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an error occurs
*/
void sendCoordinates(int x1, int y1, int x2, int y2){
    FILE *file;
    file = fopen(filename,"w");  //Opening device file(/dev/ttyUSB0)

    if(!file){
	cout << "Couldn't open file: Switching ports..." << "\n"; 
	filename = "/dev/ttyUSB1";
	file = fopen(filename,"w");  //Opening device file(/dev/ttyUSB0or1) 

	if(!file){
		cout << "Couldn't open file: Switching ports..." << "\n";
		filename = "dev/ttyS0"; 
		file = fopen(filename,"w");  //Opening device file(/dev/ttyUSB0or1) 	
		if(!file){
			cout << "Please make sure robot is connected." << "\n";
		}
	}

    } 
	
	fprintf(file, "%d,%d,%d,%d\n",x1,y1,x2,y2); //Writing to the file. Seperate coordinates using commas
	cout << "Points sent: " << x1 << "," << y1 << "," << x2 << "," << y2 << "\n";
	checkSum = x1+y1+y2+x2; 
	fprintf(file, "DONE(%d)\n",checkSum);
	fflush(file);//send the message 
	fclose(file);
}
 

/*
**Method for checking if robot is finished drawing last line 
**returns -1 if no acknowledgement from robot is recieved
*/
int receiveACK(){

    string lastLine; 
    char data[256]; //a data buffer to store file information      

    ifstream filestream;     
    filestream.open(filename); 
     
    if (!filestream){         // return error message if couldn't open file 
	cout << "Couldn't open file: Robot has disconnected." << "\n"; 
        return -2;
    } 

    filestream.seekg (0, ios::end);            // go to end of file 
    int fsize = filestream.tellg();        // find filesize 
    filestream.seekg(fsize-min(fsize,256),ios::beg);    // seek back from end a short ways 
    
    data[0]=0; // read in each line of the file until we're done 
    do{ 
        if(!isspace(data[0]) && data[0] != 0) {
            lastLine = data; 
	}
         
    }while (filestream.getline(data, 256)); 

    //End of file reached, close stream
    filestream.close(); 

	//convert checkSum to a string so it can be checked
	ostringstream convert; 
	convert << checkSum; 
	string checkint = convert.str();
	string check = "DONE(";
	check.append(checkint); 
	check.append(")");

	cout << "Acknowledgement = " << lastLine << "\n"; 
	std::size_t pos = lastLine.find("DONE");

    //Check to see if the lat line is "DONE(checksum)"
    //if it is not, then the Robot arm is not finished drawing

    if(pos == std::string::npos){//DONE not written yet
	return -1;
    }
    else if(lastLine == check){
	 return 0;
    }else{
	return -3; //checksum did not match
    }
    
}

/*
**Method prototype for checking if coordinates were recieved properly through a serialStream. 
**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int receiveACKSerial(){

	char data[32]; 
	int file = open(filename, O_RDONLY);

	if(file < 0){
		cout << "Error closing file"  << "\n"; 
		return -2; 
	}

	int e = read(file, data, 32);
	if(e<0){
		cout << "Error reading file"  << "\n"; 
		return -2; 
	}
	string  ack = data; 
	//cout << "Acknowledgement received: "<< ack  << "\n"; 
	if(close(file) < 0){
		cout << "Error closing file"  << "\n"; 
		return -2; 
	}
	//convert checkSum to a string so it can be checked
	ostringstream convert; 
	convert << checkSum; 
	string checkint = convert.str();
	string check = "DONE(";
	check.append(checkint); 
	check.append(")\n");

	std::size_t pos = ack.find(check);
	

	if(pos == std::string::npos){
		std::size_t pos2 = ack.find("DONE(");
		if(pos2 == std::string::npos){
			return -1;//DONE not written yet
		}else{
			return -3; 
		}
		
   	}else if(pos != std::string::npos){//Done is written, check for checksum
			cout << "Points recieved!!"  << "\n"; 
			return 0; //ack recieved
	}else{
		return -3; //checksum did not match
	}
	
	return -2;//if this is reached, then there was an error in the program. 

}

