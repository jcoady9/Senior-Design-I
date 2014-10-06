
#include "../include/vertexSearch.h"

#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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

	for(int i = 0; i < norm.rows; i++){
		for(int j = 0; j < norm.cols; j++){
			if((int) norm.at<float>(i,j) > 200){
				circle(norm_scaled, cv::Point(j, i), 15, cv::Scalar(0), 2, 8, 0);
			}
		}
	}

	return norm_scaled;
}

