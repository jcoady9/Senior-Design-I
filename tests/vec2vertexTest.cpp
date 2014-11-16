#include <stdio.h>
#include <stddef.h>
#include "../include/vertex.h"
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
	
	printf("Vector = : %i , %i, %i, %i\n", vec[0], vec[1], vec[2], vec[3]);

	//Run vec2vertex
	Vertex* test = vec2Vertex(vec);

	int points1[2];
	int points2[2];
	test->getPoints(points1);//current vertex
	test->getNextVertex()->getPoints(points2); //next vertex
	
	printf("v1: %i , %i\n", points1[0], points1[1]);
	printf("v2: %i , %i\n", points2[0], points2[1]);

	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
