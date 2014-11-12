#include <stdio.h>

#include "../include/draw.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/RobotComm.h"

int main()
{	printf("-----------------------------------------------\n");
	printf("\tTesting the Drawing Algorithm...\n");
	printf("-----------------------------------------------\n");
	

	Vertex* v1 = new Vertex(1.0 , 10.0);
	Vertex* v2 = new Vertex(20.0 , 1.0);

	Line* l1 = new Line(v2);

	v1->addLine(l1);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values before Draw: \n");
	printf("-----------------------------------------------\n");

	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());	

	//Run Draw
	Draw(v1);
	
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
