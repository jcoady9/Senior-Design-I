#include <iostream>

#include <stdio.h>
#include <stack>
#include "../include/vertexSearch.h"

#define RADIUS 15

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
				printf("corner: (%i, %i)\n", j, i);
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

  cv::vector<cv::Vec4i> lines;
  cv::HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50, 10 );
	int line_count = 0;
  for( size_t i = 0; i < lines.size(); i++ )
  {
    cv::Vec4i l = lines[i];	
	printf("\npt1: (%i, %i)\n", l[0], l[1]);
	printf("pt2: (%i, %i)\n", l[2], l[3]);
    line( cdst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255), 1, CV_AA);
	line_count++;
  }

	printf("line count: %i\n\n", line_count);


 return cdst;

}

bool inRange(cv::Vec4i center, cv::Vec4i point){
	
	if((point[0] <= center[0] + RADIUS || point[0] >= center[0] - RADIUS) && (point[1] <= center[1] + RADIUS || point[1] >= center[1] - RADIUS)){
		if((point[2] <= center[2] + RADIUS || point[2] >= center[2] - RADIUS) && (point[3] <= center[3] + RADIUS || point[3] >= center[3] - RADIUS)){
			return true;
		}
	}

	return false;
}

void findEndpoints(cv::vector<cv::Vec4i> lines_vec){
	
	cv::vector< cv::vector<cv::Vec4i> > line_clusters; 	

	std::stack<cv::Vec4i> line_stack;

	cv::Vec4i line = lines_vec.back();
	while(!lines_vec.empty()){
		cv::vector<cv::Vec4i> cluster;
		if(inRange(line, lines_vec.back())){
			cluster.push_back(lines_vec.back());
			lines_vec.pop_back();
		}else{
			//add vector to stack
			line_stack.push(lines_vec.back());
			lines_vec.pop_back();
		}
		line_clusters.push_back(cluster);
	}	
	

	//printf("line[]: p1(%i, %i) p2(%i, %i)", *i[0], *i[1], *i[2], *i[3]);

}





















