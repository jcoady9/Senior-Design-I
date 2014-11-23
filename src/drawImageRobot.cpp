#include "../include/drawImageRobot.h"
#include "../include/RobotComm.h"

//constructor
DrawImageRobot::DrawImageRobot(){
}

//destructor
DrawImageRobot::~DrawImageRobot(){

}

//implementation of drawPic() for the drawing image with Arbotix robot
void DrawImageRobot::drawPic(Line * line){
	/*
	for(int i = 0; i < (int)lines.size(); i++){
		if(i == 0){
			Command quitComm = new QuitCommand();
			roboComm.runCommand(quitComm);
			break;
		}

		lines[i] = scale(lines[i]);
		
		Command sendCoords = new SendCommand(lines[i]);
		roboComm.runCommand(sendCoords);

		
	
	}*/
}

Line* DrawImageRobot::scale(Line* i, int imgH, int imgL, int robH, int robW)
{	
	int pointsI1[2], pointsI2[2];
	float tempRX, tempRY, tempRX2, tempRY2;
	
	Vertex * v = new Vertex(0,0);

	v = i->getCurrentVertex();
	v->getPoints(pointsI1);
	v->setVisited(1);

	v = i->getNextVertex();
	v->getPoints(pointsI2);
	v->setVisited(1);

	tempRX = ((float) pointsI1[0] / imgH) * robH;
	tempRY = ((float) pointsI1[1] / imgL) * robW;
	tempRX2 = ((float) pointsI2[0] / imgH) * robH;
	tempRY2 = ((float) pointsI2[1] / imgL) * robW;

	i->getCurrentVertex()->setPoints((int) tempRX, (int) tempRY);
	i->getNextVertex()->setPoints((int) tempRX2, (int) tempRY2);
	return i;
}
