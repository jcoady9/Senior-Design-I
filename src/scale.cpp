//scale.cpp
//This function takes the vertex coordinates of an image and converts them to the size of our drawing plane for the robot.

#include <stddef.h>
#include "../include/vertex.h"
#include "../include/scale.h"

Vertex* scale(Vertex* i, int imgH, int imgL)
{	
	int pointsI[2], pointsR[2];
	float tempRX, tempRY;
	i->getPoint(pointsI);
	
	tempRX = ((float) pointsI[0] / imgH) * 50;
	tempRY = ((float) pointsI[1] / imgL) * 25;
	
	pointsR[0] = (int) tempRX;
	pointsR[1] = (int) tempRY;
	
	return new Vertex(pointsR[0], pointsR[1]);
}
