
#ifndef _DRAWIMAGEROBOT_H_
#define _DRAWIMAGEROBOT_H_

#include "drawImageInterface.h"
#include "RobotComm.h"

class DrawImageRobot : public drawImageInterface {

public: 

	DrawImageRobot();
	~DrawImageRobot();

	virtual void drawPic(Vertex* vertex);

private: 
	RobotComm roboComm;

};

#endif //_DRAWIMAGEROBOT_H_
