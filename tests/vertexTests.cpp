//vertexTests.cpp

#include <stdio.h>

#include "../include/vertex.h"
#include <assert.h>

//Tests the creation of a Vertex
int test_Vertex(Vertex* v1)
{
	printf("Testing test_Vertex");
	int point[2];

	v1->getPoints(point);
	
	assert(point[0] == 5);
	assert(point[1] == 3);
	printf("Vertex coordinates are valid.\n");
	
	printf("test_Vertex passed!\n");
	
	return 0;
}

//Tests to identify the correct points of the Vertex
int test_getPoints(Vertex* v1)
{
	printf("Testing test_getPoints.\n");
	int point[2];
	
	v1->getPoints(point);
	
	assert(point[0] == 5);
	assert(point[1] == 3);
	printf("Successfully got Vertex coordinates.\n");
	
	printf("test_getPoints passed!\n");
	
	return 0;
}

//Tests to properly set the points of the Vertex
int test_setPoints(Vertex* v1)
{
	printf("Testing test_setPoints.\n");
	int point[2];
	
	v1->setPoints(6, 7);
	v1->getPoints(point);
	
	assert(point[0] == 6);
	assert(point[1] == 7);
	printf("Successfully set Vertex coordinates.\n");
	
	printf("test_setPoints passed!\n");
	
	return 0;
}

int main()
{
	printf("\nTesting Vertex class.\n");
	
	Vertex* v1 = new Vertex(5, 3);
	
	test_Vertex(v1);
	test_getPoints(v1);
	test_setPoints(v1);
	
	printf("All tests passed!\n");
	
	return 0;
}




















