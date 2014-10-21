#include <iostream>

#include <stdio.h>
#include <math.h>

#include "../include/vertexSearch.h"
#include "../include/heapsort.h"

#define R_DELTA 12
#define T_DELTA 0.05


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

	cv::vector<cv::Vec2f> vec = findLineFamily(dst);

	cv::vector<cv::Vec4i> lines;
	cv::HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50, 10 );
	int line_count = 0;
	for( size_t i = 0; i < lines.size(); i++ )
	{
		//cv::Vec4i l = lines[i];	
		//printf("\npt1: (%i, %i)\n", l[0], l[1]);
		//printf("pt2: (%i, %i)\n", l[2], l[3]);
		//line( cdst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255), 1, CV_AA);
		line_count++;
	}

	printf("line count: %i\n\n", line_count);

	return cdst;
}

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

void findEndpoints(cv::vector<cv::Vec4i> lines_vec){
	/*
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
	*/

	//printf("line[]: p1(%i, %i) p2(%i, %i)", *i[0], *i[1], *i[2], *i[3]);

}





















