#include <stdio.h>

#include "../include/vertex.h"
#include "../include/line.h"


#define ARR_SIZE 10

int main(){

	int arr[] = {0, 0, 10, 20, 100, 350};	
	
	Vertex* v1 = new Vertex(arr[0] , arr[1]);
	Vertex* v2 = new Vertex(arr[2] , arr[3]);
	Vertex* v3 = new Vertex(arr[4], arr[5]);
	printf("-------------------------------------------\n");
	printf("Testing Vertex class........\n");
	printf("-------------------------------------------\n\n");
	
	printf("-------------------------------------------\n");
	printf("Testing getPoint() method...\n");
	printf("-------------------------------------------\n\n");
	
	//the getPoint method is being tested by comparing the x, y-coordinates with the array of int values declared above. 
	int point[2];	

	v1->getPoint(point);
	printf("Correct output is -> x: %i, y: %i\nv1 output is -> x: %i, y: %i\n\n", 0, 0, point[0], point[1]);

	v2->getPoint(point);
	printf("Correct output is -> x: %i, y: %i\nv2 output is -> x: %i, y: %i\n\n", 10, 20, point[0], point[1]);

	v3->getPoint(point);
	printf("Correct output is -> x: %i, y: %i\nv3 output is -> x: %i, y: %i\n\n", 100, 350, point[0], point[1]);

	printf("-------------------------------------------\n");
	printf("Testing addLine() & getLine() methods...\n");
	printf("-------------------------------------------\n\n");

	//We are testing addLine() and getLine() by comparing the address' of the Line object at initialization and
	//the address' of the Line pointer returned by the getLine() method
	Line* l1 = new Line(v1);
	Line* l2 = new Line(v3);
	Line* l3 = new Line(v2);
	Line* l4 = new Line(v1);
	Line* l5 = new Line(v2);

	v1->addLine(l1);
	v1->addLine(l2);
	v1->addLine(l3);
	v1->addLine(l4);
	v1->addLine(l5);

	printf("line[0] addr: %p\n", v1->getLine(0));
	printf("line[1] addr: %p\n", v1->getLine(1));
	printf("line[2] addr: %p\n", v1->getLine(2));
	printf("line[3] addr: %p\n", v1->getLine(3));
	printf("line[4] addr: %p\n\n", v1->getLine(4));
	

	printf("		v1 addr: %p\n", v1);
	Vertex* tmp = v1->getLine(0)->getVertex();
	printf("line[0]->next_vertex addr: %p\n\n", tmp);
	
	printf("		v3 addr: %p\n", v3);
	tmp = v1->getLine(1)->getVertex();
	printf("line[1]->next_vertex addr: %p\n\n", tmp);
	
	
	printf("		v2 addr: %p\n", v2);
	tmp = v1->getLine(2)->getVertex();
	printf("line[2]->next_vertex addr: %p\n\n", tmp);	

	printf("		v1 addr: %p\n", v2);
	tmp = v1->getLine(3)->getVertex();
	printf("line[3]->next_vertex addr: %p\n\n", tmp);

	printf("		v2 addr: %p\n", v2);
	tmp = v1->getLine(4)->getVertex();
	printf("line[4]->next_vertex addr: %p\n\n", tmp);

	printf("-------------------------------------------\n");
	printf("Testing resize Method...\n");
	printf("-------------------------------------------\n\n");

	printf("%i Lines: Size = %i: \n",v1->getNum_Lines(), v1->getSize());
	for(int i = 0; i<=25; i++){
		for(int j = 0; j<=4; j++){
			v1->addLine(l2);
		}
	printf("%i Lines: Size = %i: \n",v1->getNum_Lines(), v1->getSize());
	}
	
//>>>>>>> ac9663277e56426767a091cc21755ea7a8a41ec3

	printf("-------------------------------------------\n");
	printf("End of Tests...\n");
	printf("-------------------------------------------\n");

	return 0;
}
