#include <unistd.h>
#include "../include/draw.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"
#include "../include/drawLine.h"
#include <stdio.h>
#include <stdlib.h>


const char * fileName = "/dev/ttyUSB0";//real

/*
**Accepts first vertex and accesses it's other vertex via the Line's next vertex functionality.
*/
void Draw(Vertex* v)//visit all other vertices associated with current vertex
{
	// open serial device for both reading and writing
	/**/FILE *comm = fopen(fileName1, "r+");

	if(!comm){
	printf("Couldn't open file: Switching ports...\n"); 
	fileName = "/dev/ttyUSB1";
	comm = fopen(fileName1,"r+");  //Opening device file(/dev/ttyUSB0or1) 

	if(!comm){
		printf("Couldn't open file: Switching ports...\n");
		fileName = "dev/ttyS0"; 
		comm = fopen(fileName1,"r+");  //Opening device file(/dev/ttyUSB0or1) 	
		if(!comm){
			printf("Please make sure robot is connected.\n");
		}
	}
    	}

	Vertex* temp = v;
	int points1[2];
	int points2[2];
	temp->getPoint(points1);//current vertex
	temp->getLine(0)->getVertex()->getPoint(points2); //next vertex

	//Send the vertices coordinates to the robot through its port file
	sendCoordinates(points1[0], points1[1], points2[0], points2[1], comm);//for file writing
	//drawPic();//for simulated robots

	temp->setVisited(1);//vertex is being processed, used for debugging

	//hold until the last line has been drawn
	bool done  = false; 
	int c = 0;  
	while(!done){
		usleep(45000);//check if drawing is done every 1 second	
		int response = -5;
		c++;
		response = receiveACKSerial(comm);
		if(response == 0){
			done = true; //right checksum has been recievedcomm
		}else if(response == -2){
			exit(0);//fatal error happened in communication
		}else if(response == -3){
			printf("Wrong Checksum. Resending...\n");//DONE was recieved but checksum was wrong
			sendCoordinates(points1[0], points1[1], points2[0], points2[1], comm);//resend
			done = false;
		}
	}

	//current vertex's line array has been completed, therefore this vertex is complete	
	temp->getLine(0)->getVertex()->setVisited(2);
	temp->setVisited(2);
	fclose(comm);
}
