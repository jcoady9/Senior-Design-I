#include <stdio.h>

#include "../include/vertex.h"

int main(){

	int arr[] = {0, 0, 10, 20, 100, 350};	
	
	Vertex* v1 = new Vertex(arr[0] , arr[1]);
	Vertex* v2 = new Vertex(arr[2] , arr[3]);
	Vertex* v3 = new Vertex(arr[4], arr[5]);

	printf("-------------------------------------------\n");
	printf("\tTesting Vertex class...\n");
	printf("-------------------------------------------\n\n");

	
	printf("-------------------------------------------\n");
	printf("\tTesting getPoint() method...\n");
	printf("-------------------------------------------\n\n");
	
	//the getPoint method is being tested by comparing the x, y-coordinates with the array of int values declared above. 
	int point[2];	

	v1->getPoints(point);
	printf("Correct output is -> x: %i, y: %i\nv1 output is -> x: %i, y: %i\n\n", 0, 0, point[0], point[1]);

	v2->getPoints(point);
	printf("Correct output is -> x: %i, y: %i\nv2 output is -> x: %i, y: %i\n\n", 10, 20, point[0], point[1]);

	v3->getPoints(point);
	printf("Correct output is -> x: %i, y: %i\nv3 output is -> x: %i, y: %i\n\n", 100, 350, point[0], point[1]);


	
	//getVisited() - setVisited()
	printf("-------------------------------------------------\n");
	printf("\tTesting Visiting Methods...\n");
	printf("-------------------------------------------------\n");

	v1->setVisited(2);
	v2->setVisited(1);


	printf("v1 visited (0 for not, 1 for referenced, 2 for completed) should be 2: %i\n", v1->getVisited());
	printf("v2 visited (0 for not, 1 for referenced, 2 for completed) should be 1: %i\n", v2->getVisited());
	printf("v3 visited (0 for not, 1 for referenced, 2 for completed) should be 0: %i\n", v3->getVisited());

	printf("-------------------------------------------\n");
	printf("\t\tEnd of Tests...\n");
	printf("-------------------------------------------\n");

	return 0;
}
