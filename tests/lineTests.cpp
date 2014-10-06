
#include <stdio.h>
#include "../include/line.h"
#include "../include/vertex.h"

int main(){

	printf("Testing Line class.........\n\n");

	printf("Testing getVertex method...\n\n");
	
	Vertex* v1 = new Vertex(0, 0);
	Vertex* v2 = new Vertex(45, 68);
	Vertex* v3 = new Vertex(0, 50);

	Line* l1 = new Line(v1);
	Line* l2 = new Line(v2);
	Line* l3 = new Line(v3);
	

	printf("vertex addr: %p\nl1->next_vertex: %p\n\n", v1, l1->getVertex());
	printf("vertex addr: %p\nl1->next_vertex: %p\n\n", v2, l2->getVertex());
	printf("vertex addr: %p\nl1->next_vertex: %p\n\n", v3, l3->getVertex());

}
