#include<stdio.h>
#include<errno.h>
#include <opencv2/highgui/highgui.hpp>
#include "../include/drawImageSimulator.h"


using namespace std;
using namespace cv;

const char * filename1 = "test.txt";

int main(){
	printf("-----------------------------------------------\n");
	printf("Testing the abstract drawLine simulation...\n");
	printf("-----------------------------------------------\n");
	drawImageSimulator sim;
	
	//open the file
	FILE* file = open(filename1, O_RDWR); 
	
	//Run it
	sim.drawPic(file);
	
	waitKey(0);
}

