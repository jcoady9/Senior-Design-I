#include<stdio.h>
#include<errno.h>

#include <opencv2/highgui/highgui.hpp>
#include "../include/vertexSearch.h"

using namespace cv;

int main(int argc, char** argv){
	
	//make sure path to the image was entered
	if(argc < 2){
		printf("Missing Arguments. Did you forget to add the path of the image?\n\n");
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

	cv::vector<cv::Vec4i> lines = processImage(img);
	
	Size imgSize = img.size();

	printf("Image Dimensions: %i x %i\n", imgSize.width, imgSize.height);

	for( size_t i = 0; i < lines.size(); i++ )
	{
		cv::Vec4i l = lines[i];	
		printf("line[%i]: (%i, %i) -> (%i, %i)\n", (int) i, l[0], l[1], l[2], l[3]);
		//line( img, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255), 1, CV_AA);
	}
	imshow("line draw", img);

	waitKey(0);

	return 0;
}
