//drawImageRobot.cpp

#include "../include/drawImageRobot.h"
//#include "../include/RobotComm.h"
//#include "../include/commandInterface.h"
//#include "../include/drawLineCommand.h"

//constructor
DrawImageRobot::DrawImageRobot(){
}

//destructor
DrawImageRobot::~DrawImageRobot(){

}

/**
	**@param drawing object (which includes all lines found through the ImageProcessing class)
	**@param robot height and Width (for scaling)
	**Using the lines collected from an image, Use use the commandInterface to send the robot 
	**the coordinates it needs to draw a line
**/
void DrawImageRobot::drawPic(Drawing* drawing, int robotHeight, int robotWidth){
	
	std::vector<Line> lines = drawing->getLines();
	RobotComm robotcomm;
	for(int i = 0; i < (int)lines.size(); i++){
		
		//Scale the points for the robot
		Line * l = scale((Line*) &lines[i],drawing->getDrawingWidth(), drawing->getDrawingHeight(), robotHeight, robotWidth);
		
		//pull points from the the line to pass to robot
		int point1[2], point2[2];
		l->getCurrentVertex()->getPoints(point1);
		l->getNextVertex()->getPoints(point2);
		
		//Create and send Command
		drawLineCommand * drawLineComm = new drawLineCommand(point1[0], point1[1], point2[0], point2[1]);
		robotcomm.RobotCommunication(drawLineComm);
	}

}
/**
	**@param line to scale, the image and robot dimensions
	**Each point in an image will not correspond to the plane in
	**Which the robot will draw. Scale the points assoiciated to 
	**each vertex from a line pulled from an image to that of 
	**the robot's plane.
	** ScaledX = (ImageX/ImageWidth) * RobotWidth 
	** ScaledY = (ImageY/ImageHeight) * RobotHeight
	**@return scaled line
**/
Line* DrawImageRobot::scale(Line* i, int imgH, int imgL, int robH, int robW)
{	
	int pointsI1[2], pointsI2[2];
	float tempRX, tempRY, tempRX2, tempRY2;
	Vertex * v = new Vertex(0,0);

	//pull points from the the line to pass to robot
	v = i->getCurrentVertex();
	v->getPoints(pointsI1);

	v = i->getNextVertex();
	v->getPoints(pointsI2);
	
	//Scale the line to the plane in which we draw.
	tempRX = ((float) pointsI1[0] / imgH) * robH;
	tempRY = ((float) pointsI1[1] / imgL) * robW;
	tempRX2 = ((float) pointsI2[0] / imgH) * robH;
	tempRY2 = ((float) pointsI2[1] / imgL) * robW;
	
	//Create a new line for return with the scaled vertices
	i->getCurrentVertex()->setPoints((int) tempRX, (int) tempRY);
	i->getNextVertex()->setPoints((int) tempRX2, (int) tempRY2);
	return i;
}
