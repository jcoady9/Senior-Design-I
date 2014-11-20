#include <stdio.h>
#include "../include/Line.h"
#include "../include/vertex.h"
#include "../include/RobotComm.h"

int main()
{	printf("-----------------------------------------------\n");
	printf("\tTesting the Drawing Algorithm...\n");
	printf("-----------------------------------------------\n");
	

	Vertex* v1 = new Vertex(355 , 730);//top right 
	Vertex* v2 = new Vertex(765 , 230);//center
	
	Line *line = new Line(v1,v2);
	
	RobotComm robot;

	printf("-----------------------------------------------\n");
	printf("\tVisited values before Draw: \n");
	printf("-----------------------------------------------\n");

	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());
	
	//Run Draw for robot
	robot.RobotCommunication(line);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values after Draw: \n");
	printf("-----------------------------------------------\n");
	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());		

	printf("-----------------------------------------------\n");
	printf("\t\tEnd of tests.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
