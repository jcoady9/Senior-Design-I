#include<stdio.h>
#include<errno.h>

#include <opencv2/highgui/highgui.hpp>
#include "../include/vertexSearch.h"

using namespace cv;

int main(int argc, char** argv){
	
	//make sure path to the image was entered
	if(argc < 2){
		printf("Missing Arguements. Did you forget to add the path of the image?\n\n");
		exit(EXIT_FAILURE);
	}

	//load the image
	Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	//if the image is not found, exit program
	if(img.empty()){
	    printf("image is empty.\n\n");
	    exit(1);
	}
	
	//open a window to display the image and enter any key to close the window
	imshow("Source Image", img);

	//corner detection
	Mat dst = detectCorners(img);
	imshow("corner detection", dst);

	//Hough Line Transformation
	Mat dst2 = lineDetection(img);
	if(dst2.empty()){
		printf("line detection image file is empty.\n");
	}
	imshow("line detection", dst2);

	waitKey(0);

	return 0;
}
