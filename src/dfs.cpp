#include <unistd.h>
#include "../include/dfs.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"
#include <stdio.h>
#include <stdlib.h> 


//Accepts first vertex and accesses all other via the Line's next vertex functionality.
void DFS_Visit(Vertex* v)//visit all other vertices associated with current vertex
{
	Vertex* temp = v;
	//run for each line in the current vertex's line array
	for(int i = 0; i < temp->getNum_Lines(); i++)
	{ 	int points1[2];
		int points2[2];
		temp->getPoint(points1);//current vertex
		temp->getLine(i)->getVertex()->getPoint(points2); //next vertex

		if(temp->getLine(i)->getVertex()->getVisited() == 0)
		{
			//Send the vertices coordinates to the robot through its port file
			sendCoordinates(points1[0], points1[1], points2[0], points2[1]);

			temp->setVisited(1);//vertex is being processed, used for debugging
			
			//hold until the last line has been drawn
			bool done  = false;  
			while(!done){
				usleep(1500);//check if drawing is done every 1.5secs	
				int response = -5;
				response = receiveACK();
				if(response == 0){
					done = true; 
				}if(response == -2){
					 exit(0);
				}
				
			}
			DFS_Visit(temp->getLine(i)->getVertex());
		}
		
	}
	temp->setVisited(2);//current vertex's line array has been completed, therefore this vertex is complete	
}




