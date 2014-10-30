#include <stdio.h>
#include <stddef.h>
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/vec2vertex.h"

int main()
{
	printf("-----------------------------------------------\n");
	printf("\tTesting vec2vertex.cpp...\n");
	printf("-----------------------------------------------\n");
	
	cv::Vec4i vec;
	vec[0] = 10;
	vec[1] = 20;
	vec[2] = 30;
	vec[3] = 40;
	
	//Run vec2vertex
	Vertex* test = vec2Vertex(vec);
	
	printf("v1: %i\n", test->getVisited());
	printf("v2: %i\n", test->getLine(0)->getVertex()->getVisited());
	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
