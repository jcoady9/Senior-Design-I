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
	//checkSum = -1;

}
RobotComm::~RobotComm(){
}

/*
**method for sending coordinates to the robocontroller
**x1 and y1 are the current vertex's coordinates
**x2 and y2 are the next vertex's coordinates. 
returns -1 if an error occurs
*/
void RobotComm::sendCoordinates(string coords, FILE * file){
    
	/*checkSum = x1+y1+y2+x2; 
	//Writing to the file. Seperate coordinates using commas
	fprintf(file, "%d,%d,%d,%d,%d,\n",x1,y1,x2,y2, checkSum);
	cout << "Points sent: " << x1 << "," << y1 << "," << x2 << "," << y2 << "," << checkSum<< "\n";
	fflush(file);//send the message */ 
	fprintf(file, "%s", coords.c_str());
	cout << "Points sent: " << coords << "\n";
	fflush(file);
	
}


/*
**Method prototype for checking if coordinates were recieved properly through a serialStream. 
**returns -1 if coordinates did not match, -2 if robot disconnected, -3 if wrong coordinates
*/
int RobotComm::receiveACKSerial(FILE * file){

	char data[32];
	for(int i = 0; i < 32; i++){
		data[i] = '0'; 
	}data[31] = '\n';  
	fgets(data, 31, file);
	string  ack = data; 
	//cout << "Ack = "  << ack <<  "\n"; 

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
	
	/*Vertex * v = new Vertex(0,0);
	int points1[2], points2[2];

	v = l->getCurrentVertex();
	v->getPoints(points1);
	v->setVisited(1);

	v = l->getNextVertex();
	v->getPoints(points2);
	v->setVisited(1);*/
		
	//Send the vertices coordinates to the robot through its port file
	sendCoordinates(coords, comm);
	//hold until the last line has been drawn
	bool done  = false; 
	int c = 0;  //make sure robot is not stuck on same point for too long
	while(!done && c<200){
		usleep(5000);//check if drawing is done every 0.5 seconds	
		int response = -5;
		c++;
		response = receiveACKSerial(comm);
		if(response == 0){
			done = true; //right checksum has been recieved
		}else if(response == -2){
			printf("Robot has timed out\n");
			exit(0);//fatal error happened in communication
		}else if(response == -3){
			printf("Wrong Checksum. Resending...\n");//ack wasrecieved but checksum was wrong`
			c = 0;
			sendCoordinates(coords, comm);//resend
			done = false;
		}else if(c==199){
			printf("Communcation time out. Resending...\n");//waited too long for ack
			c = 0; 
			sendCoordinates(coords, comm);//resend
			done = false;
		}

	}

	//current vertex's line array has been completed, therefore this vertex is 
	//l->getCurrentVertex()->setVisited(2);	
	//l->getNextVertex()->setVisited(2);
}

void RobotComm::RobotCommunication(commandInterface* c){
// open serial device for both reading and writing
	FILE *comm;

	comm = fopen(RfileName, "r+");
cout << "Command is:" << c->toString() << "\n";
	if(!comm){
		printf("Couldn't open file: Switching ports...\n"); 
		RfileName = "/dev/ttyUSB1";
		comm = fopen(RfileName,"r+");  //Opening device file(/dev/ttyUSB0or1) 

		if(!comm){
			printf("Couldn't open file: Switching ports...\n");
			RfileName = "dev/ttyS0"; 
			comm = fopen(RfileName,"r+");  //Opening device file(/dev/ttyUSB0or1) 	
			if(!comm){
				printf("Please make sure robot is connected.\n");
				exit(-1);
			}
		}
    	}
	
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

