//scale.cpp
//This function takes the vertex coordinates of an image and converts them to the size of our drawing plane for the robot.

#include <stddef.h>
#include <stdio.h>
#include "../include/scale.h"
#include "../include/Line.h"
#include "../include/vertex.h"
#include "../include/scale.h"

Line* scale(Line* i, int imgH, int imgL, int robH, int robW)
{	
	int pointsI1[2], pointsI2[2];
	float tempRX, tempRY, tempRX2, tempRY2;
	
	
	Vertex * v = new Vertex(0,0);

	v = i->getCurrentVertex();
	v->getPoints(pointsI1);
	v->setVisited(1);

	v = i->getNextVertex();
	v->getPoints(pointsI2);
	v->setVisited(1);

	tempRX = ((float) pointsI1[0] / imgH) * robH;
	tempRY = ((float) pointsI1[1] / imgL) * robW;
	tempRX2 = ((float) pointsI2[0] / imgH) * robH;
	tempRY2 = ((float) pointsI2[1] / imgL) * robW;

	i->getCurrentVertex()->setPoints((int) tempRX, (int) tempRY);
	i->getNextVertex()->setPoints((int) tempRX2, (int) tempRY2);
	return i;
}
