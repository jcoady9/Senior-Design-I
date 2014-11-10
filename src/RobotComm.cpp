#include "../include/RobotComm.h"
#include <iostream>
#include <fcntl.h> 
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

const char * filenametest = "test.txt";//simulation
const char * filename = "/dev/ttyUSB0";//real
int checkSum;

/*
**method for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an error occurs
*/
void sendCoordinates(int x1, int y1, int x2, int y2, FILE * file){
    
  /* FILE *file;
   file = fopen(filename,"r+");  //Opening device file(/dev/ttyUSB0)

   if(!file){
	cout << "Couldn't open file: Switching ports..." << "\n"; 
	filename = "/dev/ttyUSB1";
	file = fopen(filename,"r+");  //Opening device file(/dev/ttyUSB0or1) 

	if(!file){
		cout << "Couldn't open file: Switching ports..." << "\n";
		filename = "dev/ttyS0"; 
		file = fopen(filename,"r+");  //Opening device file(/dev/ttyUSB0or1) 	
		if(!file){
			cout << "Please make sure robot is connected." << "\n";
		}
	}

    } */ 
	
	fprintf(file, "%d,%d,%d,%d\n",x1,y1,x2,y2); //Writing to the file. Seperate coordinates using commas
	cout << "Points sent: " << x1 << "," << y1 << "," << x2 << "," << y2 << "\n";
	checkSum = x1+y1+y2+x2; 
	fprintf(file, "DONE(%i)\n",checkSum);
	fflush(file);//send the message 
	
}


/*
**Method prototype for checking if coordinates were recieved properly through a serialStream. 
**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int receiveACKSerial(FILE * file){

	char data[32];  

	while(fgets(data, 32, file) != NULL){
		
	}
	/*int file = open(filename, O_RDONLY);

	if(file < 0){
		cout << "Error opening file"  << "\n"; 
		return -2; 
	}


	int e = read(file, data, 32);
	if(e<0){
		cout << "Error reading file"  << "\n"; 
		return -2; 
	}
	string  ack = data; 

	cout << "Acknowledgement received: "<< ack  << "\n"; //see what information is being sent from the robot
	if(close(file) < 0){
		cout << "Error closing file"  << "\n"; 
		return -2; 
	}
*/
	string  ack = data; 
	cout << "Acknowledgement received: "<< ack  << "\n"; //see what information is being sent from the robot
	
	//convert checkSum to a string so it can be checked
	ostringstream convert; 
	convert << checkSum; 
	string checkint = convert.str();
	string check = "DONE(";
	check.append(checkint); 
	check.append(")");

	
	//locate DONE(checksum) in the out put from robot
	std::size_t pos = ack.find(check);
	

	if(pos == std::string::npos){//DONE(checksum) not found
		std::size_t pos2 = ack.find("DONE(");
		if(pos2 == std::string::npos){
			return -1;//DONE has not written yet
		}else{
			return -3; //DONE was written, with the wrong checksum
		}
		
   	}else if(pos != std::string::npos){
			cout << "Points recieved!!"  << "\n"; 
			return 0; //ack recieved
	}else{
		return -2;//if this is reached, then there was an error in the program. 
	}
}



