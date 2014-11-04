#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <errno.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <fcntl.h> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
//using namespace cv;


const char * filename1 = "test.txt"; 

void drawPic(){

	int file;
	file = open(filename1, O_RDWR); 
	cv::Mat img;
	
	if(file < 0){
		cout << "Test file does not exist" << "\n";
		exit(1);
	}
	
	
	char data[128];

	int e = read(file, data, 128);
	if(e<0){
		cout << "Error reading file"  << "\n"; 
		exit(1);
	}

	string coordinates = data; 
	std::size_t pos = coordinates.find("\n");
	string cords = coordinates.substr(0,pos);

	cv::Vec4i vect;
	
	stringstream ss(cords);

	int i;
	int c = 0;
	while (ss >> i && c < 4)
	{
	    vect[c] = i;
		c++; 
	    if (ss.peek() == ',')
		ss.ignore();
	}
	
	int checksum = vect[0] + vect[1] + vect[2] + vect[3];

	ostringstream convert; 
	convert << checksum; 
	string checkint = convert.str();
	string check = "DONE(";
	check.append(checkint); 
	check.append(")\n");

	const char*  buf;
	buf = check.c_str(); 
	
	img = cv::imread("black.png", CV_LOAD_IMAGE_COLOR);
	cv::line(img,cv::Point(vect[0],vect[1]),cv::Point(vect[2],vect[3]),cv::Scalar(0,0,255), 2,CV_AA);
	
	bool wri= cv::imwrite("black.png", img);
	if(wri){
		cv::imshow("Robot Simulated Image", img);
	}

	int w = write(file, buf, 256);

	if(w<0){
		cout << "Error writing to file" << "\n";
	}
	if(close(file)<0){
		cout << "Error closing file" << "\n";
	}

	


	
}	
