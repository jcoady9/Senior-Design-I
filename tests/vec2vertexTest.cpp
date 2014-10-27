#include <stdio.h>

#include "../include/dfs.h"
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/vec2vertex.h"

int main()
{
	printf("-----------------------------------------------\n");
	printf("\tTesting vec2vertex.cpp...\n");
	printf("-----------------------------------------------\n");
	
	cv::Vec4i* vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	
	//Run vec2vertex
	vec2Vertex(&vec);
	
	
	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
