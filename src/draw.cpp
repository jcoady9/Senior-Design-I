#include <unistd.h>
#include "../include/draw.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"
#include "../include/drawLine.h"
#include "../include/drawImageSimulator.h"
#include "../include/drawImageInterface.h"
#include <stdio.h>
#include <stdlib.h>


const char * TfileName = "coordinates.txt";//test
const char * RfileName = "/dev/ttyUSB0";//real

/*
**Accepts first vertex and accesses it's other vertex via the Line's next vertex functionality.
*/
void Draw(Vertex* v, int mode)
{
	// open serial device for both reading and writing
	FILE *comm = fopen(RfileName, "r+");

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
			}
		}
    	}

	Vertex* temp = v;
	int points1[2];
	int points2[2];
	temp->getPoint(points1);//current vertex
	temp->getLine(0)->getVertex()->getPoint(points2); //next vertex
	temp->setVisited(1);

	if(mode == 1){//simulated
		drawImageSimulator sim;	
		sim.drawPic(temp);//for simulated robots
	}else if(mode == 2){//actual robot
		
		//Send the vertices coordinates to the robot through its port file
		sendCoordinates(points1[0], points1[1], points2[0], points2[1], comm);
		//hold until the last line has been drawn
		bool done  = false; 
		int c = 0;  //make sure robot is not stuck on same point for too long
		while(!done && c<100){
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
				printf("Wrong Checksum. Resending...\n");//ack wasrecieved but checksum was wrong
				sendCoordinates(points1[0], points1[1], points2[0], points2[1], comm);//resend
				done = false;
			}else if(c==99){
				//printf("Communcation time out. Resending...\n");//waited too long for ack
				c=0; 
				sendCoordinates(points1[0], points1[1], points2[0], points2[1], comm);//resend
				done = false;
			}/**/
		}
	}
	//current vertex's line array has been completed, therefore this vertex is complete	
	temp->getLine(0)->getVertex()->setVisited(2);
	temp->setVisited(2);
	fclose(comm);
}
