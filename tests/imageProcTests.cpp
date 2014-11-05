#include<stdio.h>
#include<errno.h>
#include <string>

#include <opencv2/highgui/highgui.hpp>

#include "../include/vertexSearch.h"

#define NUM_IMAGES 4 //number of images we are using for testing

int main(){

	//string array of image filenames
	std::string filename[NUM_IMAGES] = {"line.png", "diagonal-line.png", "horizontal-lines.jpg", "wovenlines.jpeg"};
	cv::Mat src[NUM_IMAGES]; //array of the actual images
	cv::RNG rng(0); //random number generator so we can make draw each line a different color
	

	printf("=================================\n");
	printf("IMAGE PROCESSING TESTS.\n");
	printf("=================================\n");

	printf("=================================\n");
	printf("detect straight line Tests.\n");
	printf("=================================\n");
	

	for(int i = 0; i < NUM_IMAGES; i++){
	
		src[i] = cv::imread(filename[i], CV_LOAD_IMAGE_COLOR);		

		if(src[i].empty()){
		    printf("'%s' is empty.\n\n", filename[i].c_str());
		    break;
		}
		
		cv::vector<cv::Vec4i> lines = processImage(src[i]);
	
		cv::Size imgSize = src[i].size();
	
		printf("\n'%s' Dimensions: %i x %i\n", filename[i].c_str(), imgSize.width, imgSize.height);

		for(size_t j = 0; j < lines.size(); j++){
			cv::Vec4i l = lines[j];	
			printf("line[%i]: (%i, %i) -> (%i, %i)\n", (int) j, l[0], l[1], l[2], l[3]);
			cv::Scalar line_color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			cv::line(src[i], cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), line_color, 1, CV_AA);
		}
		
		//cv::imshow(" after processing",src[i]);

	}

	cv::imshow("image[0]", src[0]);
	cv::imshow("image[1]", src[1]);
	cv::imshow("image[2]", src[2]);
	cv::imshow("image[3]", src[3]);

	cv::waitKey(0);

	return 0 ;
}

