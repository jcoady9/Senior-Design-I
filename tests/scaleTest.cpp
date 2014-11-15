//scaleTest.cpp

#include <stdio.h>
#include <stddef.h>
#include "../include/vertex.h"
#include "../include/scale.h"
#include <assert.h>

int main()
{
	printf("-----------------------------------------------\n");
	printf("\tTesting scale.cpp...\n");
	printf("-----------------------------------------------\n");
	
	//image values
	Vertex* img = new Vertex(100, 100);
	int imgH = 0;
	int imgL = 0;
	
	assert(imgH == 500);
	assert(imgL == 500);
	
	//Run scale
	Vertex* rob = NULL;
	
	assert(rob == scale(img, imgH, imgL));
	
	//Results
	int points[2];
	rob->getPoint(points);
	
	printf("rob.x: %i\nrob.y: %i\n", points[0], points[1]);
	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
