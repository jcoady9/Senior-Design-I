#include <unistd.h>
#include "../include/dfs.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"
#include <stdio.h>
#include <stdlib.h> 


//Accepts first vertex and accesses all other via the Line's next vertex functionality.
void DFS_Visit(Vertex* v)//visit all other vertices associated with current vertex
{/*
	printf("OOPSIES");
	
	Vertex* temp = v;
	//run for each line in the current vertex's line array
		int points1[2];
		int points2[2];
		temp->getPoint(points1);//current vertex
		temp->getLine(0)->getVertex()->getPoint(points2); //next vertex

//CoodinateSend(points1[0], points1[1], points2[0], points2[1]);
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
					printf("Wrong Checksum. Resending...");
					sendCoordinates(points1[0], points1[1], points2[0], points2[1]);
					done = false;
				}
				
			}
	temp->setVisited(2);//current vertex's line array has been completed, therefore this vertex is complete	
}


void CoodinateSend(int x1, int y1, int x2, int y2){
Send the vertices coordinates to the robot through its port file
			sendCoordinates(x1, y1, x2, y2);

			//temp->setVisited(1);//vertex is being processed, used for debugging
			
			//hold until the last line has been drawn
			bool done  = false;  
			while(!done){
				usleep(10);//check if drawing is done every 10ms	
				int response = -5;
				response = receiveACK();
				if(response == 0){
					done = true; 
				}else if(response == -2){
					 exit(0);
				}else{
					CoodinateSend(x1, y1, x2, y2);
				}
				
			}*/

}



