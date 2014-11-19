
#include "drawImageInterface.h"
#include "RobotComm.h"

class DrawImageRobot : public drawImageInterface {

public: 

	DrawImageRobot();
	~DrawImageRobot();

	void drawPic(Vertex* vertex);

private: 
	RobotComm roboComm;

};
