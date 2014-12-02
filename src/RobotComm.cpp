//RobotComm.cpp

#include "../include/RobotComm.h"
#include "../include/commandInterface.h"
#include <stdlib.h>
#include <iostream>
#include <fcntl.h> 
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

//constructor
RobotComm::RobotComm(){
	TfileName = "coordinates.txt";//test file
	RfileName = "/dev/ttyUSB0";//robot file

}
//destructor
RobotComm::~RobotComm(){
}

/*
	**method for sending coordinates to the robocontroller
	**@params string representing the coordinates command 
	**@params file in which information is written to (port file)
	**@return -1 if an error occurs
*/
void RobotComm::sendCoordinates(string coords, FILE * file){

	fprintf(file, "%s", coords.c_str());
	fflush(file);
	
}


/*
	**Method prototype for checking if coordinates were recieved properly through a serialStream. 
	**@return -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int RobotComm::receiveACKSerial(FILE * file){

	char data[32];
	for(int i = 0; i < 32; i++){
		data[i] = '0'; 
	}data[31] = '\n';  
	fgets(data, 31, file);
	string  ack = data; 

	//check response for acknowledgements
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

/*
**
*/
void RobotComm::drawLineWork(string coords, FILE * comm)
{	
	//Send the vertices coordinates to the robot through its port file
	cout << "Points sent: " << coords.substr(1).c_str() << "\n";
	sendCoordinates(coords, comm);

	//hold until the last line has been drawn
	bool done  = false; 
	int c = 0;  //make sure robot is not stuck on same point for too long
	while(!done && c<500){
		usleep(10000);//check if drawing is done every 0.5 seconds	
		int response = -5;
		c++;
		response = receiveACKSerial(comm);
		if(response == 0){//right checksum has been recieved
			done = true; 
		}else if(response == -2){//fatal error happened in communication
			printf("Robot has timed out\n");
			exit(0);
		}else if(response == -3){//ack was recieved but checksum was wrong`
			printf("Wrong Checksum. Resending...\n");
			c = 0;
			sendCoordinates(coords, comm);//resend
			done = false;
		}else if(c==499){//waited too long for ack
			//printf("Communcation time out. Resending...\n");
			c = 0; 
			sendCoordinates(coords, comm);//resend
			done = false;
		}

	}

}
/**
	**@param the commade which you wish to send to Robot
	**Open the serial port file and write the appropiate command to it
**/
void RobotComm::RobotCommunication(commandInterface* c){
	// open serial device for both reading and writing
	FILE *comm;

	comm = fopen(RfileName, "r+");

	if(!comm){
		printf("Couldn't open file: Switching ports...\n"); 
		RfileName = "/dev/ttyUSB1";
		comm = fopen(RfileName,"r+");  //Opening device file(/dev/ttyUSB1) 

		if(!comm){
			printf("Couldn't open file: Switching ports...\n");
			RfileName = "dev/ttyS0"; 
			comm = fopen(RfileName,"r+");  //Opening device file(/dev/ttys0) 	
			if(!comm){
				printf("Please make sure robot is connected.\n");
				exit(-1);
			}
		}
    	}
	
	//process command and write appropriate information to port file
	if(c->toString().compare("r") == 0 || c->toString().compare("q") == 0){
		//send the relax or quit command to the robot.		
		fprintf(comm, "%s", c->toString().c_str());
		fflush(comm);
	}else{
		//Send a line to the robot
		drawLineWork(c->toString(), comm);
	}
	fclose(comm);

}

