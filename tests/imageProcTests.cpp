#include<stdio.h>
#include<errno.h>
#include <string>

#include <opencv2/highgui/highgui.hpp>

#include "../include/vertexSearch.h"

#define NUM_IMAGES 6 //number of images we are using for testing

int main(){

	//string array of image filenames
	std::string filename[NUM_IMAGES] = {"images/line.png", "images/diagonal-line.png", "images/horizontal-lines.jpg", "images/wovenlines.jpeg", "images/curved-line.png", "images/two.jpg"};
	cv::RNG rng(0); //random number generator so we can make draw each line a different color
	

	printf("=================================\n");
	printf("IMAGE PROCESSING TESTS.\n");
	printf("=================================\n");

	printf("=================================\n");
	printf("detect straight line Tests.\n");
	printf("=================================\n");
	

	for(int i = 0; i < NUM_IMAGES; i++){
	
		cv::Mat src = cv::imread(filename[i], CV_LOAD_IMAGE_COLOR);		

		if(src.empty()){
		    printf("'%s' is empty.\n\n", filename[i].c_str());
		    break;
		}
		cv::Mat src_copy = src;
		cv::vector<cv::Vec4i> lines = lineDetection(src_copy);
	
		cv::Size imgSize = src.size();
	
		printf("\n'%s' Dimensions: %i x %i\n", filename[i].c_str(), imgSize.width, imgSize.height);

		//cv::Mat detected_lines_img = cv::Mat::zeros(src.size(), CV_8UC3);
		//detected_lines_img.copyTo(detected_lines_img, src);
		for(size_t j = 0; j < lines.size(); j++){
			cv::Vec4i l = lines[j];	
			printf("line[%i]: (%i, %i) -> (%i, %i)\n", (int) j, l[0], l[1], l[2], l[3]);
			cv::Scalar line_color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			cv::line(src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), line_color, 1, CV_AA);
		}

		cv::imshow(filename[i].c_str(), src);
		
	}

	printf("=================================\n");
	printf("detect curved line Tests.\n");
	printf("=================================\n");

	cv::Mat curve_img = cv::imread("images/curved-line.png", CV_LOAD_IMAGE_COLOR);
	cv::Mat x_img = cv::imread("images/horizontal-lines.jpg", CV_LOAD_IMAGE_COLOR);
	cv::Mat two_img = cv::imread("images/two.jpg", CV_LOAD_IMAGE_COLOR);

	if(curve_img.empty() || x_img.empty() || two_img.empty()){
	    printf("image is empty.\n\n");
	    exit(1);
	}

	cv::vector< cv::vector<cv::Point> > contours;
	cv::vector<cv::Vec4i>hierarchy;

	//contourDetection(curve_img);
	contourDetection(x_img, contours, hierarchy);
	//contourDetection(two_img);


	cv::waitKey(0);

	return 0 ;
}

