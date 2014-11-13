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
	Vertex* v3 = new Vertex(100.0 , 55.0);
	Vertex* v4 = new Vertex(62.0 , 17.0);
	Vertex* v5 = new Vertex(72.0 , 89.0);

	Line* l1 = new Line(v2);
	Line* l2 = new Line(v4);
	Line* l3 = new Line(v4);

	v1->addLine(l1);
	v3->addLine(l2);
	v5->addLine(l3);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values before Draw: \n");
	printf("-----------------------------------------------\n");

	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());
	printf("V3: %i\n", v3->getVisited());	
	printf("V4: %i\n", v4->getVisited());
	printf("V5: %i\n", v5->getVisited());		

	//Run Draw for robot
	Draw(v1,2);
	Draw(v3,2);
	Draw(v5,2);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values after Draw: \n");
	printf("-----------------------------------------------\n");
	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());	
	printf("V3: %i\n", v3->getVisited());	
	printf("V4: %i\n", v4->getVisited());
	printf("V5: %i\n", v5->getVisited());			

	printf("-----------------------------------------------\n");
	printf("\t\tEnd of tests.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
