#include<stdio.h>
#include<errno.h>
#include <opencv2/highgui/highgui.hpp>
#include "../include/drawImageSimulator.h"
#include "../include/Line.h"
#include "../include/vertex.h"


using namespace std;
using namespace cv;


int main(){
	printf("-----------------------------------------------\n");
	printf("Testing the abstract drawLine simulation...\n");
	printf("-----------------------------------------------\n");

	drawImageSimulator sim;	
	
	Vertex* vertex1 = new Vertex(50,100);
	Vertex* vertex2 = new Vertex(200, 450);
	
	Line* line = new Line(vertex1,vertex2);
		
	
	//Run it
	sim.drawPic(line); 
	
	waitKey(0);
}

