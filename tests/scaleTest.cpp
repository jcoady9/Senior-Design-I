//scaleTest.cpp

#include <stdio.h>
#include <stddef.h>
#include "../include/vertex.h"
#include "../include/scale.h"
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
	Vertex* rob = scale(img, imgH, imgL);
	
	//Results
	int points[2];
	rob->getPoints(points);
	
	printf("rob.x: %i\nrob.y: %i\n", points[0], points[1]);
	
	printf("-----------------------------------------------\n");
	printf("\t\tEnd of test.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
