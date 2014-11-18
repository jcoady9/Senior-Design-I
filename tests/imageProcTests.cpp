#include<stdio.h>
#include<errno.h>
#include <string>

#include <opencv2/highgui/highgui.hpp>

#include "../include/vertexSearch.h"

#define NUM_IMAGES 6 //number of images we are using for testing

int main(){

	//string array of image filenames
	std::string filename[NUM_IMAGES] = {"images/line.png", "images/diagonal-line.png", "images/horizontal-lines.jpg", "images/wovenlines.jpeg", "images/curved-line.png", "images/two2.png"};
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

		cv::Mat detected_lines_img = cv::Mat::zeros(src.size(), CV_8UC3);
		//detected_lines_img.copyTo(detected_lines_img, src);
		for(size_t j = 0; j < lines.size(); j++){
			cv::Vec4i l = lines[j];	
			printf("line[%i]: (%i, %i) -> (%i, %i)\n", (int) j, l[0], l[1], l[2], l[3]);
			cv::Scalar line_color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			cv::line(src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), line_color, 1, CV_AA);
		}

		cv::imshow(filename[i].c_str(), src_copy);
		
	}

	printf("=================================\n");
	printf("detect curved line Tests.\n");
	printf("=================================\n");


	for(int j = 0; j < NUM_IMAGES; j++){
		cv::Mat img = cv::imread(filename[j].c_str(), CV_LOAD_IMAGE_COLOR);

		if(img.empty()){
	    		printf("%s is empty.\n\n", filename[j].c_str());
	   		continue;
		}

		cv::vector< cv::vector<cv::Point> > contours;
		cv::vector<cv::Vec4i>hierarchy;		

		contourDetection(img, contours, hierarchy);

		for(size_t i = 0; i < hierarchy.size(); i++){
			printf("%i, %i, %i, %i\n", hierarchy[i][0], hierarchy[i][1], hierarchy[i][2], hierarchy[i][3]);
		}

		cv::Mat draw_contours = cv::Mat::zeros(img.size(), CV_8UC3);
		for(size_t i = 0; i < contours.size(); i++){
			cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(draw_contours, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
		}

		for(int i = 0; i < (int)contours.size(); i++){
			cv::vector<cv::Point> p_vec = contours[i];
			cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

			for(int j = 0; j < (int)p_vec.size(); j++){
				cv::Point p = p_vec[j];
				circle(draw_contours, p, 5, color);
			}
		}

		printf("hierarchy size: %i\n", (int)hierarchy.size());
		printf("size: %i\n", (int)contours.size());

		//cv::imshow(filename[j].c_str(), draw_contours);

	}

	printf("=================================\n");
	printf("Remove Redundant Contours Tests.\n");
	printf("=================================\n");


	for(int k = 0; k < NUM_IMAGES; k++){

		cv::Mat img = cv::imread(filename[k].c_str(), CV_LOAD_IMAGE_COLOR);

		if(img.empty()){
	    		printf("%s is empty.\n\n", filename[k].c_str());
	   		continue;
		}

		if(filename[k].c_str() == filename[3]){
			continue;
		}

		cv::vector< cv::vector<cv::Point> > contours;
		cv::vector<cv::Vec4i>hierarchy;

		

		cv::vector<cv::Vec4i> lines_copy = lineDetection(img);

		contourDetection(img, contours, hierarchy);

		cv::vector< cv::vector<cv::Point> > valid_contours = removeRedundantContours(contours, lines_copy);


		cv::Mat draw_valid_contours = cv::Mat::zeros(img.size(), CV_8UC3);
		for(size_t i = 0; i < valid_contours.size(); i++){
			cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(draw_valid_contours, valid_contours, i, color, 2, 8, hierarchy, 0, cv::Point());
		}

		for(int i = 0; i < (int)valid_contours.size(); i++){
		cv::vector<cv::Point> p_vec = valid_contours[i];
		cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

			for(int j = 0; j < (int)p_vec.size(); j++){
				cv::Point p = p_vec[j];
				circle(draw_valid_contours, p, 5, color);
			}
		}

		printf("%s: num valid contours: %i\n", filename[k].c_str(), (int)valid_contours.size());

		//if(filename[k] == filename[2])
			cv::imshow(filename[k].c_str(), draw_valid_contours);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	cv::waitKey(0);

	return 0 ;
}

