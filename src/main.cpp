#include<stdio.h>
#include<errno.h>
#include "../include/drawImageSimulator.h"
#include "../include/drawImageInterface.h"
#include <opencv2/highgui/highgui.hpp>
#include "../include/imageProcessor.h"
#include "../include/Line.h"
#include "../include/vertex.h"
#include "../include/vec2vertex.h"
#include "../include/scale.h"
#include "../include/RobotComm.h"



using namespace cv;

int main(int argc, char** argv){
	
	//make sure path to the image was entered
	if(argc < 3){
		printf("Missing Arguments:\n"); 
		printf("Did you forget to add the path of the image? (images/name-of-image.*) \n\t***Please do not use jpg or jpeg images***\n");
		printf("Or did you forget the Simulation mode? (1 for Simulation or 2 for robot)\n");
		printf("Example for robot execution on file 'img.png': ./project images/img.png 2\n");
		exit(EXIT_FAILURE);
	}
	
	//load the image
	Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	int mode = atoi(argv[2]);

	//if the image is not found, exit program
	if(img.empty()){
	    printf("image is empty.\n\n");
	    exit(1);
	}

	//Store the black image so it can be reset later
	Mat img2 = imread("black.png", CV_LOAD_IMAGE_COLOR);
	if(img2.empty()){
	    printf("Please supply a blank image.\n\n");
	    exit(1);
	}

	//open a window to display the image and enter any key to close the window
	imshow("Source Image", img);

	static ImageProcessor imageProcessor;

	//process the image
	cv::vector<cv::Vec4i> lines = imageProcessor.processImage(img);
	
	//write image dimensions to CLI
	Size imgSize = img.size();
	printf("Image Dimensions: %i x %i\n", imgSize.width, imgSize.height);

	for( size_t i = 0; i < lines.size(); i++ ){
		cv::Vec4i l = lines[i];	
		printf("line[%i]: (%i, %i) -> (%i, %i)\n", (int) i, l[0], l[1], l[2], l[3]);
		
		Line * temp = vec2Vertex(l);
		temp = scale(temp, imgSize.width, imgSize.height);
		//Line * line = new Line(temp->, temp->getNextVertex());
		if(mode == 1){//simulated
			drawImageSimulator sim;	
			sim.drawPic(temp);
		}else if(mode == 2){//actual robot
			RobotComm Robot;
			Robot.RobotCommunication(temp);
		} 
	}

	//clear the black image for next run
	bool wri= cv::imwrite("black.png", img2);
	if(wri < 0){
		printf("Error clearing black image.\n");
	}

	waitKey(0);

	return 0;
}
