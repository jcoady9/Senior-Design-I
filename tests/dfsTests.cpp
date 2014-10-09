#include <stdio.h>

#include "../include/dfs.h"
#include "../include/vertex.h"
#include "../include/line.h"

int main()
{	
	printf("Testing the DFS modified Algorithm...\n");
	

	Vertex* v1 = new Vertex(0.0 , 0.0);
	Vertex* v2 = new Vertex(0.0 , 1.0);
	Vertex* v3 = new Vertex(1.0, 0.0);
	Vertex* v4 = new Vertex(1.0, 1.0);

	Line* l1 = new Line(v2);
	Line* l2 = new Line(v3);
	Line* l3 = new Line(v1);
	Line* l4 = new Line(v4);

	v1->addLine(l1);
	v2->addLine(l2);
	v3->addLine(l3);
	v3->addLine(l4);
	
	printf("Visited values before DFS: \n");
	printf("\rV1: %i\n", v1->getVisited());	
	printf("\rV2: %i\n", v2->getVisited());	
	printf("\rV3: %i\n", v3->getVisited());	
	printf("\rV4 (second line from v1): %i\n", v4->getVisited());	

	DFS_Visit(v1);
	
	printf("\nVisited values after DFS: \n");
	printf("\rV1: %i\n", v1->getVisited());	
	printf("\rV2: %i\n", v2->getVisited());	
	printf("\rV3: %i\n", v3->getVisited());	
	printf("\rV4 (second line from v1): %i\n", v4->getVisited());	

	
	return 0;
}
