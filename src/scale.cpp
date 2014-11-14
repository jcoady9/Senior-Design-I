//scale.cpp
//This function takes the vertex coordinates of an image and converts them to the size of our drawing plane for the robot.

#include <stddef.h>
#include <stdio.h>
#include "../include/scale.h"
#include "../include/vertex.h"
#include "../include/line.h"

Vertex* scale(Vertex* i, int imgH, int imgL)
{	
	int pointsI1[2], pointsI2[2];//, pointsR1[2], pointsR1[2];
	
	float tempRX, tempRY, tempRX2, tempRY2;
	i->getPoints(pointsI1);
	i->getNextVertex()->getPoints(pointsI2);//
	printf("Scaling... %i, %i\n", pointsI1[0], pointsI1[1]);//
	tempRX = ((float) pointsI1[0] / imgH) * 50;
	tempRY = ((float) pointsI1[1] / imgL) * 25;
	tempRX2 = ((float) pointsI2[0] / imgH) * 50;
	tempRY2 = ((float) pointsI2[1] / imgL) * 25;
	i = new Vertex((int) tempRX, (int) tempRY);
	i->getNextVertex()->setPoints((int) tempRX2, (int) tempRY2);
	//pointsR[0] = (int) tempRX;
	//pointsR[1] = (int) tempRY;
	
	return i;
	//return new Vertex(pointsR[0], pointsR[1]);
}
