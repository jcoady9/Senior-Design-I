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
	Line * l = new Line(img, imgnext);

	int imgH = 500;
	int imgL = 500;
	int points[2];
	
	//print values before scaling happens
	img->getPoints(points);
	printf("Before: V1.x: %i. V1.y: %i\n", points[0], points[1]);
	
	imgnext->getPoints(points);
	printf("Before: V2.x: %i. V2.y: %i\n\n", points[0], points[1]);
	
	//Run scale
	Line* rob = scale(l, imgH, imgL);
	
	assert(rob == scale(l, imgH, imgL));
	
	//Results
	rob->getCurrentVertex()->getPoints(points);
	
	printf("After: V1.x: %i. V1.y: %i\n", points[0], points[1]);

	rob->getNextVertex()->getPoints(points);
	
	printf("After: V2.x: %i. V2.y: %i\n", points[0], points[1]);
	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
