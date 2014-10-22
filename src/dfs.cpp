#include <unistd.h>
#include "../include/dfs.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"



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
			//TODO: Call the draw line method
			sendCoordinates(points1[0], points1[1], points2[0], points2[1]);
			//sleep(50);
			//receiveACK();

			temp->setVisited(1);//vertex is being processed, used for debugging
			DFS_Visit(temp->getLine(i)->getVertex());
		}
		
	}
	temp->setVisited(2);//current vertex's line array has been completed, therefore this vertex is complete	
}




