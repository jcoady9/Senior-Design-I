//drawImageRobot.h

#ifndef _DRAWIMAGEROBOT_H_
#define _DRAWIMAGEROBOT_H_

#include "drawImageInterface.h"
#include "RobotComm.h"
#include "Line.h"
#include "drawing.h"
#include "RobotComm.h"
#include "commandInterface.h"
#include "drawLineCommand.h"

class DrawImageRobot : public drawImageInterface {

public: 

	DrawImageRobot();
	~DrawImageRobot();

	virtual void drawPic(Drawing* drawing, int robotHeight, int robotWidth);
	virtual Line* scale(Line* i, int imgH, int imgL, int robH, int robW); 

private: 
	RobotComm roboComm;

};

#endif //_DRAWIMAGEROBOT_H_
