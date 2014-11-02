#include <iostream>
#include <stdio.h>
#include <math.h>

#include "../include/vertexSearch.h"

#define R_DELTA 12
#define T_DELTA 0.05


/**

 * performs harris corner detection on an image
 *
 *@param src the source image
 *
 *@param reference to the image with the corner detection
*/
void detectCorners(cv::Mat src, cv::Mat & dst){
	
	cv::Mat gray_scale, norm, norm_scaled;

	cvtColor(src, gray_scale, CV_BGR2GRAY);

	dst = cv::Mat::zeros(src.size(), CV_32FC1);

	int block_size = 5;
	int aperature_size = 3;
	double hfp = 0.04;

	cornerHarris(gray_scale, dst, block_size, aperature_size, hfp, cv::BORDER_DEFAULT);

	normalize(dst, norm, 0, 255, cv::NORM_MINMAX, CV_8UC1, cv::Mat());
	convertScaleAbs(norm, dst);

	//dst = norm;

	return;
}

/**
 * detects straight lines in an image
 *
 * @param img	the image to perform line detection on

 * @return a vector with the cartesian coordinates of any detected line segments' endpoints
 *
*/
cv::vector<cv::Vec4i> lineDetection(cv::Mat src){

	cv::Mat dst, bw;

	detectCorners(src, dst);
	
	//convert image to gray-scale
	cv::cvtColor(src, bw, CV_BGR2GRAY);

	cv::threshold(dst, bw, 10, 255, CV_THRESH_BINARY_INV);
	
	//make the line thinner
	thinning(bw);

	imshow("Thinning", bw);

	//perform probabalistic hough line transformation storing any line segment endpoints in the lines vector
	cv::vector<cv::Vec4i> lines;
	cv::HoughLinesP(bw, lines, 1, CV_PI/180, 50, 50, 10 );
	
	return lines;
}

void contourDetection(cv::Mat src){

	cv::vector< cv::vector<cv::Point> > contours;
	cv::vector<cv::Vec4i> hierarchy;
	cv::RNG rng(12345);

	cv::cvtColor(src, src, CV_BGR2GRAY);

	Canny(src, src, 100, 200, 3);

	findContours(src, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	
	cv::Mat draw_contours = cv::Mat::zeros(src.size(), CV_8UC3);
	for(size_t i = 0; i < contours.size(); i++){
	
		cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(draw_contours, contours, i, color, 2, 8, hierarchy, 0, cv::Point());

	}

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

cv::vector<cv::Vec2f> findLineFamily(cv::Mat graySrc){
	
	cv::vector<cv::Vec2f> lines;	

	HoughLines(graySrc, lines, 1, CV_PI/180, 100, 0, 0 );


	for(size_t i = 0; i < lines.size(); i++){
		printf("(%f, %f)\n", lines[i][0], lines[i][1]);
	}
	
	vectorSort(lines);

	cv::vector<cv::Vec2f> line_family;

	int line_family_count = 0;
	int count = 1;

	while(!lines.empty()){

		line_family.push_back(lines.back());

		cv::Vec2f line = lines.back();
		printf("%f \n",  line[0]);	
	
		lines.pop_back();
		lines.pop_back();

		//cv::Vec2f line = lines.back();
		printf("%f \n",  line[0]);

		cv::Vec2f tmp = line_family[line_family_count];
		for(size_t i = lines.size(); i > 0; i--){

			if(inRange(tmp, lines[i])){

				printf("R: %f before. %f \n", line_family[line_family_count][0], lines[i][0]);
				line_family[line_family_count][0] += lines[i][0];
				printf("R: %f . \n", line_family[line_family_count][0]);

				printf("THETA: %f before. \n", line_family[line_family_count][1]);
				line_family[line_family_count][1] += lines[i][1];	
				printf("THETA: %f \n", line_family[line_family_count][1]);

				lines.pop_back();			
				count++;
				

				//printf("R_avg: %f \n", line_family[line_family_count][0] / 2);
				//printf("T_avg: %f \n", line_family[line_family_count][1] / 2);

			}
		}

		line_family[line_family_count][0] /= count;
		printf("R_avg_final: %f \n", line_family[line_family_count][0]);

		line_family[line_family_count][1] /= count;
		printf("T_avg_final: %f \n", line_family[line_family_count][1]);

		line_family_count++;
		count = 1;

	}

	printf("\n");
	
	for(size_t i = 0; i < line_family.size(); i++){
		printf("(%f, %f)\n", line_family[i][0], line_family[i][1]);
	}
	
	return line_family;
}

cv::vector<cv::Vec4f> mergeLines(cv::vector<cv::Vec4i> lines, cv::vector<cv::Vec2f> line_family){
	
	for(size_t i = 0; i < line_family.size(); i++){
		cv::Vec2f point;
		point[0] = line_family[i][0] * cos(line_family[i][1]);
		point[1] = line_family[i][0] * sin(line_family[i][1]);
	}	
	
	cv::vector<cv::Vec4f> ret;
	return ret;
}

void vectorSort(cv::vector<cv::Vec2f> &vec){
	
	printf("size: %i\n", (int) vec.size());
	printf("current capacity: %i\n", (int) vec.capacity());

	if(vec.capacity() > vec.size()){
		vec.resize(vec.size(), cv::Vec2f());
		printf("new capacity: %i\n", (int) vec.capacity());
	}
	
	
	printf("\n");
	printf("\n");

	insertionSort(vec);
	//heapsort(vec);

	for(size_t i = 0; i < vec.size(); i++){
		printf("(%f, %f)\n", vec[i][0], vec[i][1]);
	}
	
}

void insertionSort(cv::vector<cv::Vec2f> &vec){
	cv::Vec2f temp; 
	for(size_t i = 0; i < vec.size(); i++){
		size_t j = i;
		while(j > 0 && vec[j - 1][0] > vec[j][0]){
			temp = vec[j];
			vec[j] = vec[j - 1];
			vec[j - 1] = temp;
			j--;
		}
	}

}

bool inRange(cv::Vec2f center, cv::Vec2f point){
	
	if((point[0] <= center[0] + R_DELTA && point[0] >= center[0] - R_DELTA) ){
		if((point[1] <= center[1] + T_DELTA && point[1] >= center[1] - T_DELTA)){
			return true;
		}
	}

	return false;
}























