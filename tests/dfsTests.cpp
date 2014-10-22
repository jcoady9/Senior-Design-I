#include <stdio.h>

#include "../include/dfs.h"
#include "../include/vertex.h"
#include "../include/line.h"

int main()
{	printf("-----------------------------------------------\n");
	printf("\tTesting the DFS modified Algorithm...\n");
	printf("-----------------------------------------------\n");
	

	Vertex* v1 = new Vertex(0.0 , 0.0);
	Vertex* v2 = new Vertex(0.0 , 1.0);
	Vertex* v3 = new Vertex(1.0, 0.0);
	Vertex* v4 = new Vertex(1.0, 1.0);
	Vertex* v5 = new Vertex(10.0, 1.0);
	Vertex* v6 = new Vertex(12.0, 1.0);

	Line* l1 = new Line(v2);
	Line* l2 = new Line(v3);
	Line* l3 = new Line(v1);
	Line* l4 = new Line(v4);
	Line* l5 = new Line(v5);
	Line* l6 = new Line(v6);

	v1->addLine(l1);
	v2->addLine(l2);
	v3->addLine(l3);
	v3->addLine(l4);
	v3->addLine(l5);
	v3->addLine(l6);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values before DFS: \n");
	printf("-----------------------------------------------\n");

	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());	
	printf("V3: %i\n", v3->getVisited());	
	printf("V4 (second line from v3): %i\n", v4->getVisited());	
	printf("V5 (third line from v3): %i\n", v5->getVisited());	
	printf("V6 (fourth line from v3): %i\n", v6->getVisited());	

	//Run DFS
	DFS_Visit(v1);
	
	printf("-----------------------------------------------\n");
	printf("\tVisited values after DFS: \n");
	printf("-----------------------------------------------\n");
	printf("V1: %i\n", v1->getVisited());	
	printf("V2: %i\n", v2->getVisited());	
	printf("V3: %i\n", v3->getVisited());	
	printf("V4 (second line from v3): %i\n", v4->getVisited());	
	printf("V5 (third line from v3): %i\n", v5->getVisited());	
	printf("V6 (fourth line from v3): %i\n", v6->getVisited());	

	printf("-----------------------------------------------\n");
	printf("\t\tEnd of tests.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
