#include "../include/quitCommand.h"
#include "../include/RobotComm.h"


//test the quit command
int main(){
	RobotComm robot;
	quitCommand *quit = new quitCommand();

	robot.RobotCommunication(quit); 
	return 0;
}
