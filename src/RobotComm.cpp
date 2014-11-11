#include "../include/RobotComm.h"
#include <iostream>
#include <fcntl.h> 
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

int checkSum;

/*
**method for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an error occurs
*/
void sendCoordinates(int x1, int y1, int x2, int y2, FILE * file){
    
	checkSum = x1+y1+y2+x2; 
	//Writing to the file. Seperate coordinates using commas
	fprintf(file, "%d,%d,%d,%d,%d\n",x1,y1,x2,y2, checkSum); 
	cout << "Points sent: " << x1 << "," << y1 << "," << x2 << "," << y2 << "\n";
	//fprintf(file, "y");
	fflush(file);//send the message 
	
}


/*
**Method prototype for checking if coordinates were recieved properly through a serialStream. 
**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int receiveACKSerial(FILE * file){

	char data[32];  

	fgets(data, 32, file);

	string  ack = data; 
	cout << "Acknowledgement received: "<< ack  << "\n"; //see what information is being sent from the robot
	
	//check response for acknowlesgements
	std::size_t pos1 = ack.find("y");
	std::size_t pos2 = ack.find("n");

	if(pos1 != std::string::npos){//Correct checksum recieved and line drawn
		cout << "Points recieved!!"  << "\n"; 
		return 0; //ack recieved 
	}else if(pos2 != std::string::npos){
		return -3; //checksums did not match
	}else{
		return -1; //nothing was written, keep waiting
	}
	return -2;//if this is reached, then there was an error in the program. 
}



