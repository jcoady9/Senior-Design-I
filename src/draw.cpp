#include <unistd.h>
#include "../include/draw.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"
#include <stdio.h>
#include <stdlib.h>

/*
**Accepts first vertex and accesses it's other vertex via the Line's next vertex functionality.
*/
void Draw(Vertex* v)//visit all other vertices associated with current vertex
{
	Vertex* temp = v;
	//run for each line in the current vertex's line array
	int points1[2];
	int points2[2];
	temp->getPoint(points1);//current vertex
	temp->getLine(0)->getVertex()->getPoint(points2); //next vertex

	//Send the vertices coordinates to the robot through its port file
	sendCoordinates(points1[0], points1[1], points2[0], points2[1]);

	temp->setVisited(1);//vertex is being processed, used for debugging

	//hold until the last line has been drawn
	bool done  = false;  
	while(!done){
		usleep(1000);//check if drawing is done every 10ms	
			int response = -5;
			response = receiveACKSerial();
		if(response == 0){
			done = true; 
		}else if(response == -2){
			exit(0);
		}else if(response == -3){
			printf("Wrong Checksum. Resending...\n");
			sendCoordinates(points1[0], points1[1], points2[0], points2[1]);
			done = false;
		}
	}

	//current vertex's line array has been completed, therefore this vertex is complete	
	temp->getLine(0)->getVertex()->setVisited(2);
	temp->setVisited(2);
}
