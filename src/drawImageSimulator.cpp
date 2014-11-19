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
#include "../include/vertex.h"



using namespace std;
//using namespace cv;


//const char * FILE_NAME = "test.txt"; 

void drawImageSimulator::drawPic(Vertex* vertex)
{

	cv::Mat img;

	cv::Vec4i vect;
	
	//receive the points from the vertex(model class) parameter
	int points[2];
	int points2[2];
	vertex->getPoints(points);
	vertex->getNextVertex()->getPoints(points2);	
	
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
