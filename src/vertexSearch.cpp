#include <iostream>
#include <stdio.h>
#include <math.h>

#include "../include/vertexSearch.h"

#define R_DELTA 12
#define T_DELTA 0.05

/*
*/
cv::vector<cv::Vec4i> processImage(cv::Mat image){
	
	//convert image to grayscale if not done already
	if(image.channels() > 1){
		cvtColor(image, image, CV_RGB2GRAY);
	}

	//detect any straight lines in the image
	cv::vector<cv::Vec4i> lines = lineDetection(image);

	cv::imshow("thinning", image);

	return lines;
}

/**
 * detects straight lines in an image
 *
 * @param img	the image to perform line detection on

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
 *
 *
*/
void contourDetection(cv::Mat src, cv::vector< cv::vector<cv::Point> > & contours, cv::vector<cv::Vec4i> & hierarchy){

	cv::RNG rng(12345);

	if(src.channels() > 1){
		cv::cvtColor(src, src, CV_BGR2GRAY);
	}

	Canny(src, src, 100, 200, 3);

	findContours(src, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	cv::Mat draw_contours = cv::Mat::zeros(src.size(), CV_8UC3);
	for(size_t i = 0; i < contours.size(); i++){
		cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(draw_contours, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
	}

	
	for(size_t i = 0; i < hierarchy.size(); i++){
		printf("%i, %i, %i, %i\n", hierarchy[i][0], hierarchy[i][1], hierarchy[i][2], hierarchy[i][3]);
	}
	
	for(int i = 0; i < (int)contours[0].size(); i++){
		cv::vector<cv::Point> p_vec = contours[0];
		cv::Point p = p_vec[i];
		circle(draw_contours, p, 5, cv::Scalar(0, 255, 0));
		printf("[%i] (%i, %i)\n", i, p.x, p.y);
	}
	
	for(int i = 0; i < (int)contours[1].size(); i++){
		cv::vector<cv::Point> p_vec = contours[1];
		cv::Point p = p_vec[i];
		circle(draw_contours, p, 5, cv::Scalar(0, 0, 255));
	}

	printf("hierarchy size: %i\n", (int)hierarchy.size());
	printf("size: %i\n", (int)contours.size());

	imshow("curved lines?", draw_contours);
	
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
























