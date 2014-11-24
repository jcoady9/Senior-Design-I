#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <errno.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <fcntl.h> 
#include "../include/drawImageSimulator.h"
#include "../include/Line.h"
#include "../include/vertex.h"



using namespace std;

void drawImageSimulator::drawPic(Line * l)
{

	cv::Mat img;

	cv::Vec4i vect;

	//pull vertices from the Line
	Vertex * v = new Vertex(0,0);
	int points[2], points2[2];

	v = l->getCurrentVertex();
	v->getPoints(points);

	v = l->getNextVertex();
	v->getPoints(points2);

	
	//store the points in the vector to be used later
	vect[0] = points[0];
	vect[1] = points[1];
	vect[2] = points2[0];
	vect[3] = points2[1];
	cout << "Points sent: = " << points[0] << "," << points[1] << "," << points2[0] << "," << points2[1] << 	"\n"; 

	img = cv::imread("black.png", CV_LOAD_IMAGE_COLOR);
	cv::line(img,cv::Point(vect[0],vect[1]),cv::Point(vect[2],vect[3]),cv::Scalar(0,0,255),2,CV_AA);
	
	bool wri = cv::imwrite("black.png", img);
	if(wri){
		cv::imshow("Robot Simulated Image", img);
	}
}

Line* drawImageSimulator::scale(Line* i, int imgH, int imgL, int robH, int robW)
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
