#include<stdio.h>
#include<errno.h>
#include <opencv2/highgui/highgui.hpp>
#include "../include/drawImageSimulator.h"


using namespace std;
using namespace cv;


int main(){
	printf("-----------------------------------------------\n");
	printf("Testing the abstract drawLine simulation...\n");
	printf("-----------------------------------------------\n");
	drawImageSimulation sim;

	//Run it
	sim.drawPic();
	
	waitKey(0);
}

