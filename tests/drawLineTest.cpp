//drawLineTest.cpp

#include <stdio.h>
#include "../include/Line.h"
#include "../include/vertex.h"
#include "../include/RobotComm.h"
#include "../include/commandInterface.h"
#include "../include/drawLineCommand.h"

int main()
{	printf("-----------------------------------------------\n");
	printf("\tTesting the Drawing Algorithm...\n");
	printf("-----------------------------------------------\n");
	

	Vertex* v1 = new Vertex(10 , 10);//top right 
	Vertex* v2 = new Vertex(100 , 100);//center
	
	Line *line = new Line(v1,v2);

	Vertex* v3 = new Vertex(30 , 30);//top right 
	Vertex* v4 = new Vertex(100 , 100);//center
	
	Line *line1 = new Line(v3,v4);
	
	RobotComm robot;

	//pull points from the the line to pass to robot
	int point1[2], point2[2];
	line->getCurrentVertex()->getPoints(point1);
	line->getNextVertex()->getPoints(point2);
	
	//Create and send Command
	drawLineCommand * drawLineComm = new drawLineCommand(point1[0], point1[1], point2[0], point2[1]);
	

	line1->getCurrentVertex()->getPoints(point1);
	line1->getNextVertex()->getPoints(point2);
	
	//Create and send Command
	drawLineCommand * drawLineComm2 = new drawLineCommand(point1[0], point1[1], point2[0], point2[1]);

	printf("-----------------------------------------------\n");
	printf("\t\tDrawing...: \n");
	printf("-----------------------------------------------\n");
	
	//Run Draw for robot
	robot.RobotCommunication(drawLineComm);	
	robot.RobotCommunication(drawLineComm2);
	

	printf("-----------------------------------------------\n");
	printf("\t\tEnd of tests.\n");
	printf("-----------------------------------------------\n");
	return 0;
}
