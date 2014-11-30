//LineTests.cpp

#include <stdio.h>
#include "../include/Line.h"
#include <assert.h>

int test_Line(Line* line, Vertex* v1, Vertex* v2)
{
	printf("Testing test_Line class.\n");	
	assert(line->getCurrentVertex() == v1);
	assert(line->getNextVertex() == v2);
	printf("Successfully identified current and next vertex.\n");
	
	printf("test_Line passed!\n");
	
	return 0;
}

int test_getCurrentVertex(Line* line, Vertex* v1)
{
	printf("Testing test_Line class.\n");	
	assert(line->getCurrentVertex() == v1);
	printf("Successfully got current vertex.\n");
	
	printf("test_getCurrentVertex passed!\n");
	
	return 0;
}

int test_setCurrentVertex(Line* line, Vertex* v2)
{
	printf("Testing test_Line class.\n");	
	line->setCurrentVertex(v2);
	assert(line->getCurrentVertex() == v2);
	printf("Successfully set current vertex.\n");
	
	printf("test_setCurrentVertex passed!\n");
	
	return 0;
}

int	test_getNextVertex(Line* line, Vertex* v2)
{
	printf("Testing test_getNextVertex class.\n");
	assert(line->getNextVertex() == v2);
	printf("Successfully got next vertex.\n");
	
	printf("test_getNextVertex passed!\n");
	
	return 0;
}

int	test_setNextVertex(Line* line, Vertex* v1)
{
	printf("Testing test_setNextVertex class.\n");
	line->setNextVertex(v1);
	assert(line->getNextVertex() == v1);
	printf("Successfully set next vertex.\n");
	
	printf("test_setNextVertex passed!\n");
	
	return 0;
}

int main()
{
	printf("Testing Line class.\n");
	
	Vertex* v1 = new Vertex(5, 3);
	Vertex* v2 = new Vertex(10, 9);
	Line* line = new Line(v1, v2);
	
	test_Line(line, v1, v2);
	test_getCurrentVertex(line, v1);
	test_setCurrentVertex(line, v2);
	test_getNextVertex(line, v2);
	test_setNextVertex(line, v1);
	
	printf("All tests passed!\n");
	
	return 0;
}
