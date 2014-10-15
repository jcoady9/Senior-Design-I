#include <iostream>

#include <stdio.h>
#include "../include/vertexSearch.h"

//corner detection
cv::Mat detectCorners(cv::Mat src){
	
	cv::Mat gray_scale, norm, norm_scaled;

	cvtColor(src, gray_scale, CV_BGR2GRAY);

	cv::Mat dst = cv::Mat::zeros(src.size(), CV_32FC1);

	int block_size = 5;
	int aperature_size = 3;
	double hfp = 0.04;

	cornerHarris(gray_scale, dst, block_size, aperature_size, hfp, cv::BORDER_DEFAULT);

	normalize(dst, norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
	convertScaleAbs(norm, norm_scaled);
	
	int count = 0;
	
	for(int i = 0; i < norm.rows; i++){
		for(int j = 0; j < norm.cols; j++){
			if((int) norm.at<float>(i,j) > 200){
				circle(norm_scaled, cv::Point(j, i), 15, cv::Scalar(0), 2, 8, 0);
				count++;
			}
		}
	}
	printf("corner count: %i\n", count);
	return norm_scaled;
}



//line detection
cv::Mat lineDetection(cv::Mat src){

 cv::Mat dst, cdst;
 Canny(src, dst, 50, 200, 3);
 cvtColor(dst, cdst, CV_GRAY2BGR);

 //#if 0
  cv::vector<cv::Vec2f> lines;
  cv::HoughLines(dst, lines, 1, CV_PI/180, 100, 0, 0 );

  for( size_t i = 0; i < lines.size(); i++ )
  {
     float rho = lines[i][0];
	float theta = lines[i][1];
     cv::Point pt1;
	cv::Point pt2;
     double a = cos(theta);
	double b = sin(theta);
     double x0 = a*rho;
	double y0 = b*rho;
     pt1.x = cvRound(x0 + 1000*(-b));
     pt1.y = cvRound(y0 + 1000*(a));
     pt2.x = cvRound(x0 - 1000*(-b));
     pt2.y = cvRound(y0 - 1000*(a));
     line( cdst, pt1, pt2, cv::Scalar(0,0,255), 3, CV_AA);
  }
 /*#else
  vector<Vec4i> lines;
  HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50, 10 );
  for( size_t i = 0; i < lines.size(); i++ )
  {
    Vec4i l = lines[i];
    line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
  }
 #endif*/

 return cdst;
}
