
#include <assert.h>
#include <stdio.h>

#include <opencv2/imgproc/imgproc.hpp>

#include "../include/imageProcessor.h"

#define DELTA 0.1

ImageProcessor imageProcessor;

/*
 * tests the lineDetection() function
*/
void testLineDetection(){
	cv::Mat img = cv::imread("images/line.png", CV_LOAD_IMAGE_COLOR);

	cv::vector<cv::Vec4i> line_vec = imageProcessor.lineDetection(img);
	assert(!line_vec.empty());
	assert(line_vec.size() <= 7);

	line_vec.clear();

	img = cv::imread("images/horizontal-lines.jpg", CV_LOAD_IMAGE_COLOR);

	line_vec = imageProcessor.lineDetection(img);
	assert(!line_vec.empty());
	assert(line_vec.size() <= 13);

	printf("lineDetection() test passed.\n");
}

/*
 * tests the contourDetection() function
*/
void testContourDetection(){
	cv::Mat img = cv::imread("images/two2.png", CV_LOAD_IMAGE_COLOR);

	cv::vector<cv::Vec4i> lines = imageProcessor.lineDetection(img);

	cv::vector< cv::vector<cv::Point> > contours;
	cv::vector<cv::Vec4i> hierarchy;
	imageProcessor.contourDetection(img, contours, hierarchy);

	assert(!contours.empty());
	assert(!hierarchy.empty());

	printf("contourDetection() test passed.\n");
}

/*
 * tests the distance() function
*/
void testDistance(){
	double result = imageProcessor.distance(cv::Point(100, 15), cv::Point(75, 36));
	assert(result < 32.64 + DELTA && result > 32.64 - DELTA);
	
	result = imageProcessor.distance(cv::Point(3, 5), cv::Point(9, 7));
	assert(result < 6.32 + DELTA && result > 6.32 - DELTA);

	result = imageProcessor.distance(cv::Point(572, 641), cv::Point(894, 127));
	assert(result < 606.53 + DELTA && result > 606.53 - DELTA);

	printf("distance() test passed.\n");
}

int main(){
	
	printf("\nImageProcessor Unit Tests\n");

	testLineDetection();
	testContourDetection();
	testDistance();
	
	printf("all tests passed!\n");

}
