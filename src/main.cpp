#include<stdio.h>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char** argv){
	
	//make sure path to the image was entered
	if(argc < 2){
		printf("Missing Arguements. Did you forget to add the path of the image?\n");
		exit(EXIT_FAILURE);
	}

	//load the image
	Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	//if the image is not found, exit program
	if(img.empty()){
	    printf("image is empty.\n\n");
	    exit(1);
	}
	
	//open a window to display the image and enter any key to close the window
	imshow("opencvtest", img);
	waitKey(0);

	return 0;
}
