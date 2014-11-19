#include <stdio.h>

#include "../include/draw.h"
#include "../include/vertex.h"
#include "../include/RobotComm.h"

int main()
{	printf("-----------------------------------------------\n");
	printf("\tTesting the Drawing Algorithm...\n");
	printf("-----------------------------------------------\n");
	

	Vertex* v1 = new Vertex(475 , 730);//top right 
	Vertex* v2 = new Vertex(765 , 230);//center

	
	v1->setNextVertex(v2);

	printf("-----------------------------------------------\n");
	printf("\tVisited values before Draw: \n");
	printf("-----------------------------------------------\n");

	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());
	//printf("V3: %i\n", v3->getVisited());	
	

	//Run Draw for robot
	Draw(v1,2);
	//Draw(v3,2);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values after Draw: \n");
	printf("-----------------------------------------------\n");
	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());	
	//printf("V3: %i\n", v3->getVisited());			

	printf("-----------------------------------------------\n");
	printf("\t\tEnd of tests.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
