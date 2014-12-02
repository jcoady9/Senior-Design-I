//imageProcUnitTests.cpp

#include <assert.h>
#include <stdio.h>

#include <opencv2/highgui/highgui.hpp>
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
	assert(!img.empty());

	cv::vector<cv::Vec4i> lines = imageProcessor.lineDetection(img);

	cv::vector< cv::vector<cv::Point> > contours;
	cv::vector<cv::Vec4i> hierarchy;
	imageProcessor.contourDetection(img, contours, hierarchy);

	assert(!contours.empty());
	assert(!hierarchy.empty());
	assert((int)contours.size() == 53);

	printf("contourDetection() test passed.\n");
}

/*
 * tests the thinning of straight lines
 */
 void testLineThinning(){
 	cv::Mat img = cv::imread("images/horizontal-lines.jpg", CV_LOAD_IMAGE_COLOR);
 	assert(!img.empty());

 	cv::imshow("original image.", img);

 	//convert image to grayscale
	if(img.channels() > 1){
		cv::cvtColor(img, img, CV_RGB2GRAY);
	}

 	//convert image to a binary image
	cv::threshold(img, img, 10, 255, CV_THRESH_BINARY_INV);

 	imageProcessor.thinning(img);

 	cv::imshow("image after thinning.", img);

 	cv::waitKey(0);

	printf("thinning() test passed.\n");
 }

/*
 * tests removeRedundantContours() function
 */
void testRemoveRedundantContours(){
	//test removing redundant contours with an image that should not have any contours after processing
	cv::Mat img = cv::imread("images/horizontal-lines.jpg", CV_LOAD_IMAGE_COLOR);
 	assert(!img.empty());

 	//process for lines and contours
	cv::vector<cv::Vec4i> lines = imageProcessor.lineDetection(img);
	assert(!lines.empty());
 	cv::vector< cv::vector<cv::Point> > contours;
	cv::vector<cv::Vec4i> hierarchy;
	imageProcessor.contourDetection(img, contours, hierarchy);

	cv::vector< cv::vector<cv::Point> > valid_contours = imageProcessor.removeRedundantContours(contours, lines);

	assert((int)valid_contours.size() == 0);

	//empty vectors for 2nd test
	lines.clear();
	contours.clear();
	hierarchy.clear();
	valid_contours.clear();

	//test removing redundant contours with an image that will have valid contours after processing the image
	img = cv::imread("images/two2.png", CV_LOAD_IMAGE_COLOR);
 	assert(!img.empty());

 	//process for lines and contours
	lines = imageProcessor.lineDetection(img);
	assert(!lines.empty());
	imageProcessor.contourDetection(img, contours, hierarchy);

	valid_contours = imageProcessor.removeRedundantContours(contours, lines);

	assert((int)valid_contours.size() == 48);

	printf("removeRedundantContours() test passed.\n");
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

int main(void){
	
	printf("\nImageProcessor Unit Tests\n");

	testLineDetection();
	testContourDetection();
	testLineThinning();
	testRemoveRedundantContours();
	testDistance();
	
	printf("\nAll tests passed!\n");

}
