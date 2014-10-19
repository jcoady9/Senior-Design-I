
#include <stdio.h>
#include "../include/line.h"
#include "../include/vertex.h"

int main(){
	
	printf("-------------------------------------------\n");
	printf("Testing Line class.........\n");
	printf("-------------------------------------------\n\n");
	
	printf("-------------------------------------------\n");
	printf("Testing getVertex() method\n");
	printf("------------------------------------------\n\n");
	
	Vertex* v1 = new Vertex(0, 0);
	Vertex* v2 = new Vertex(45, 68);
	Vertex* v3 = new Vertex(0, 50);

	Line* l1 = new Line(v1);
	Line* l2 = new Line(v2);
	Line* l3 = new Line(v3);
	
	//testing that the vertex added to Line in the constructor is the vertex we return with getVertex()
	//by looking at the pointers, we see if the vertex added to the line is the vertex returned.
	printf("vertex v1 addr:  %p\nl1->next_vertex: %p\n\n", v1, l1->getVertex());
	printf("vertex v2 addr:  %p\nl2->next_vertex: %p\n\n", v2, l2->getVertex());
	printf("vertex v3 addr:  %p\nl3->next_vertex: %p\n\n", v3, l3->getVertex());
	
	//Here we test setVertex in the same manner as getVertex(). We compare the address of the vertex with the
	//addresss of the vertex returned by the line
	printf("-------------------------------------------\n");
	printf("Testing setVertex() method\n");	
	printf("-------------------------------------------\n\n");

	l1->setVertex(v3);
	l2->setVertex(v1);
	l3->setVertex(v2);

	printf("vertex v3 addr:  %p\nl1->next_vertex: %p\n\n", v3, l1->getVertex());
	printf("vertex v1 addr:  %p\nl2->next_vertex: %p\n\n", v1, l2->getVertex());
	printf("vertex v2 addr:  %p\nl3->next_vertex: %p\n\n", v2, l3->getVertex());
	
	printf("---------------------------\n");
	printf("End of Tests.....\n");

	return 0;
}
