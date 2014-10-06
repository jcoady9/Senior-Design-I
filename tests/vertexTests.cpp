#include <stdio.h>

#include "../include/vertex.h"
#include "../include/line.h"


#define ARR_SIZE 10

int main(){

	int arr[] = {0, 0, 10, 20, 100, 350};	
	
	Vertex* v1 = new Vertex(arr[0] , arr[1]);
	Vertex* v2 = new Vertex(arr[2] , arr[3]);
	Vertex* v3 = new Vertex(arr[4], arr[5]);

	printf("Testing Vertex class........\n\n");

	printf("Testing getPoint method...\n\n");
	
	int point[2];	

	v1->getPoint(point);
	printf("Correct output is -> x: %i, y: %i\nv1 output is -> x: %i, y: %i\n\n", 0, 0, point[0], point[1]);

	v2->getPoint(point);
	printf("Correct output is -> x: %i, y: %i\nv2 output is -> x: %i, y: %i\n\n", 10, 20, point[0], point[1]);

	v3->getPoint(point);
	printf("Correct output is -> x: %i, y: %i\nv3 output is -> x: %i, y: %i\n\n", 100, 350, point[0], point[1]);


	printf("Testing addLine method...\n\n");	

	Line* l1 = new Line(v1);
	Line* l2 = new Line(v3);
	Line* l3 = new Line(v2);

	v1->addLine(l1);
	v1->addLine(l2);
	v1->addLine(l3);

	printf("lines added to vertex\n\n");
	
	printf("l1 addr: %p\n", l1);
	printf("l2 addr: %p\n", l2);
	printf("l3 addr: %p\n\n", l3);

	Line* tmp = v1->getLine(0);
	
	printf("v1->line[0] addr: %p\n\n", tmp);

	tmp = v1->getLine(1);
	printf("v1->line[1] addr: %p\n\n", tmp);

	tmp = v1->getLine(2);
	printf("v1->line[2] addr: %p\n\n", tmp);

	printf("v1 addr: %p\n", v1);
	printf("v2 addr: %p\n", v2);
	printf("v3 addr: %p\n\n", v3);
	
	

	printf("%p\n\n", v1->getLine(0)->getVertex());

	return 0;
}
