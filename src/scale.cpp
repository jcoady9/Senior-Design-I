//scale.cpp
//This function takes the vertex coordinates of an image and converts them to the size of our drawing plane for the robot.

#include <stddef.h>
#include <stdio.h>
#include "../include/scale.h"
#include "../include/vertex.h"
#include "../include/scale.h"

Vertex* scale(Vertex* i, int imgH, int imgL)
{	
	int pointsI1[2], pointsI2[2];//, pointsR1[2], pointsR1[2];
	float tempRX, tempRY, tempRX2, tempRY2;
	int roboX, roboY;
	roboX = 512;
	roboY = 512; 	

	i->getPoints(pointsI1);
	i->getNextVertex()->getPoints(pointsI2);

	printf("Scaling... %i, %i\n", pointsI1[0], pointsI1[1]);

	tempRX = ((float) pointsI1[0] / imgH) * roboX;
	tempRY = ((float) pointsI1[1] / imgL) * roboY;
	tempRX2 = ((float) pointsI2[0] / imgH) * roboX;
	tempRY2 = ((float) pointsI2[1] / imgL) * roboY;

	i->setPoints((int) tempRX, (int) tempRY);
	i->getNextVertex()->setPoints((int) tempRX2, (int) tempRY2);
	return i;
}
