#include <iostream>
#include <stdio.h>
#include <math.h>

#include "../include/vertexSearch.h"

#define POWER 2
#define MAX_DIST 10.0
#define PERCENTAGE 0.1

/*
 * performs all neccessary processing on an image to detect lines and contours
 *
 *@param image - the image to be processed
 * 
 *@return a vector of line and contour coordinates
*/
cv::vector<cv::Vec4i> processImage(cv::Mat image){
	
	//convert image to grayscale if not done already
	if(image.channels() > 1){
		cvtColor(image, image, CV_RGB2GRAY);
	}

	//detect any straight lines in the image
	cv::vector<cv::Vec4i> lines = lineDetection(image);

	return lines;
}

/**
 * detects straight lines in an image
 *
 * @param img	the image to perform line detection on
 *
 * @return a vector with the cartesian coordinates of any detected line segments' endpoints
 *
*/
cv::vector<cv::Vec4i> lineDetection(cv::Mat & src){

	if(src.channels() > 1){
		cv::cvtColor(src, src, CV_RGB2GRAY);
	}

	cv::threshold(src, src, 10, 255, CV_THRESH_BINARY_INV);

	thinning(src);

	cv::vector<cv::Vec4i> lines;
	cv::HoughLinesP(src, lines, 1, CV_PI/180, 50, 50, 10 );
	
	return lines;
}

/*
 * detects contours (curved lines) in an image
 *
 *@param src - image to be processed for contours
 *@param contours - reference to a vector that will store information on detected contours
 *@param hierarchy - reference to a vector that will store information on the contour hierarchy
 * 
*/
void contourDetection(cv::Mat src, cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> & hierarchy){

	cv::RNG rng(12345);

	//convert image to grayscale if not done so already
	if(src.channels() > 1){
		cv::cvtColor(src, src, CV_BGR2GRAY);
	}

	//perform edge detection
	Canny(src, src, 100, 200, 3);

	//detect contours
	findContours(src, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
}

/**
 * Based off of code found from here: http://opencv-code.com/quick-tips/implementation-of-thinning-algorithm-in-opencv/
 *
 * This is part of the Zhang-Suen algorithm, documentation on how it works can be seenhere: http://read.pudn.com/downloads99/sourcecode/graph/texture_mapping/403914/Parallel%20thinning%20with%20two-	    subiteration%20algorithms.pdf
 *
 * Perform one thinning iteration.
 * Normally you wouldn't call this function directly from your code.
 *
 * @param  im    Binary image with range = 0-1
 * @param  iter  0=even, 1=odd
 */
void thinningIteration(cv::Mat& im, int iter)
{
    cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);

    for (int i = 1; i < im.rows-1; i++)
    {
        for (int j = 1; j < im.cols-1; j++)
        {
            uchar p2 = im.at<uchar>(i-1, j);
            uchar p3 = im.at<uchar>(i-1, j+1);
            uchar p4 = im.at<uchar>(i, j+1);
            uchar p5 = im.at<uchar>(i+1, j+1);
            uchar p6 = im.at<uchar>(i+1, j);
            uchar p7 = im.at<uchar>(i+1, j-1);
            uchar p8 = im.at<uchar>(i, j-1);
            uchar p9 = im.at<uchar>(i-1, j-1);

            int A  = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) + 
                     (p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) + 
                     (p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
                     (p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
            int B  = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
            int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
            int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);

            if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
                marker.at<uchar>(i,j) = 1;
        }
    }

    im &= ~marker;
}

/**
 * Function for thinning the given binary image
 *
 * Based off of code found from here: http://opencv-code.com/quick-tips/implementation-of-thinning-algorithm-in-opencv/
 *
 * This is part of the Zhang-Suen algorithm, documentation on how it works can be seen here: http://read.pudn.com/downloads99/sourcecode/graph/texture_mapping/403914/Parallel%20thinning%20with%20two-	    subiteration%20algorithms.pdf
 *
 * @param  im  Binary image with range = 0-255
 */
void thinning(cv::Mat& im)
{
    im /= 255;

    cv::Mat prev = cv::Mat::zeros(im.size(), CV_8UC1);
    cv::Mat diff;

    do {
        thinningIteration(im, 0);
        thinningIteration(im, 1);
        cv::absdiff(im, prev, diff);
        im.copyTo(prev);
    } 
    while (cv::countNonZero(diff) > 0);

    im *= 255;
}

/*
 * Takes the vector of detected contours from and image and determines whether the points of a contour are clustered around an endpoint making the contour invalid.
 * Any contours deemed to be invalid are not included in the returned vector containing contours deemed valid
 * 
 *@param contours - a vector containing all the detected contours
 *@param lines - a vector containing all detected straight lines
 * 
 *@return - a vector of valid contours
*/
cv::vector< cv::vector<cv::Point> > removeRedundantContours(cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> lines){
	
	cv::vector< cv::vector<cv::Point> > valid_contours; //a vector to contain all contours that are determined to be valid

	for(int i = 0; i < (int)contours.size(); i++){

		float invalid_point_count = 0.0f; //count of points in a contour that are clustering around an endpoint
		cv::vector<cv::Point> contour_vec = contours[i];
		for(int k = 0; k < (int)contour_vec.size(); k++){

			//compute the distance between each point in the contour and the endpoints of each straight line
			cv::Point point = contour_vec[k];
			for(int j = 0; j < (int)lines.size(); j++){
				double dist1 = distance(point, cv::Point(lines[j][0], lines[j][1]));
				double dist2 = distance(point, cv::Point(lines[j][2], lines[j][3]));
				
				//if the distance between the contour point and a line endpoint, then increment the number of detected invalid points
				if(dist1 < MAX_DIST || dist2 < MAX_DIST){
					invalid_point_count++;
					break;
				}
			}
		}
		
		//compute the percentage of invalid points in the contour, current contour is valid and pushed onto back of valid_contour vector
		//if less than 10% of the points are found to be invalid.
		float invalid_percentage = invalid_point_count / (float) contour_vec.size();
		if(invalid_percentage < PERCENTAGE){
			valid_contours.push_back(contours[i]);
		}				
	}

	return valid_contours;
}

/*
 * calculates the distance between two points
 * 
 * @param p1 - first point
 * @param p2 - second point
 *
 * @return the distance between p1 and p2
 *
*/
double distance(cv::Point p1, cv::Point p2){
	
	double x_sqr, y_sqr;
	x_sqr = pow( (double)(p2.x - p1.x), POWER); 	
	y_sqr = pow( (double)(p2.y - p1.y), POWER);
	
	return sqrt(x_sqr + y_sqr);
}























