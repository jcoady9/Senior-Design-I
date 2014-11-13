#include<stdio.h>
#include<errno.h>

#include <opencv2/highgui/highgui.hpp>

#include "../include/vertexSearch.h"

#include "../include/vertex.h"
#include "../include/vec2vertex.h"
#include "../include/scale.h"
#include "../include/draw.h"


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
	
	//open a window to display the image and enter any key to close the window
	//imshow("Source Image", img);

	//process the image
	cv::vector<cv::Vec4i> lines = processImage(img);
	
	Size imgSize = img.size();

	printf("Image Dimensions: %i x %i\n", imgSize.width, imgSize.height);

	for( size_t i = 0; i < lines.size(); i++ ){
		cv::Vec4i l = lines[i];	
		printf("line[%i]: (%i, %i) -> (%i, %i)\n", (int) i, l[0], l[1], l[2], l[3]);
		//line( bw, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255), 1, CV_AA);
		Vertex* temp = vec2Vertex(l);
		//temp = scale(temp, imgSize.height, imgSize.width);
		Draw(temp, mode); 
		
	}

	//imshow("drawn image", img);

	waitKey(0);

	return 0;
}
