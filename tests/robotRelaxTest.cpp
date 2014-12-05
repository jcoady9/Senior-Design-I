//robotRelaxTest.cpp

#include "../include/relaxCommand.h"
#include "../include/RobotComm.h"


//test the relax command
int main(){
	RobotComm robot;
	relaxCommand * relax = new relaxCommand();

	robot.RobotCommunication(relax); 
	return 0;
}
