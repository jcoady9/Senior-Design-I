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
	Vertex* img = new Vertex(150, 100);
	Vertex* imgnext = new Vertex(250, 400);
	img->setNextVertex(imgnext);

	int imgH = 500;
	int imgL = 500;
	
	//Run scale
	Vertex* rob = NULL;
	
	assert(rob == scale(img, imgH, imgL));
	
	//Results
	int points[2];
	rob->getPoints(points);
	
	printf("V1.x: %i\nV1.y: %i\n", points[0], points[1]);

	rob->getNextVertex()->getPoints(points);
	
	printf("V2.x: %i\nV2.y: %i\n", points[0], points[1]);
	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
