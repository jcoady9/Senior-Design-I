#include "../include/RobotComm.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const char * filename = "/dev/ttyUSB0";
/*
**method for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an
*/
void sendCoordinates(int x1, int y1, int x2, int y2){
    FILE *file;
    file = fopen(filename,"a");  //Opening device file(/dev/ttyUSB0)

    if(!file){
	cout << "Couldn't open file: Switching ports..." << "\n"; 
	filename = "/dev/ttyUSB1";
	file = fopen(filename,"a");  //Opening device file(/dev/ttyUSB0or1) 

	if(!file){
		cout << "Couldn't open file: Switching ports..." << "\n";
		filename = "dev/ttyS0"; 
		file = fopen(filename,"a");  //Opening device file(/dev/ttyUSB0or1) 	
		if(!file){
			cout << "Please make sure robot is connected." << "\n";
		}
	}

    } 
	fprintf(file,"%d,%d,%d,%d\n",x1,y1,x2,y2); //Writing to the file. Seperate coordinates using commas
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

    //Check to see if the lat line is "DONE"
    //if it is not, then the Robot arm is not finished drawing
    if(lastLine== "DONE"){
	 return 0;
    }else{
	return -1; 
    }
    
}
