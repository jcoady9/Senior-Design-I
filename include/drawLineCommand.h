#ifndef DRAWLINECOMMAND_H
#define DRAWLINECOMMAND_H

/*
Header file for the command that will tell the main function to send four coordinates
to the robot to use to draw a straight line

*/

#include "commandInterface.h"
#include <string>

class drawLineCommand:public commandInterface
{
	private: 
		std::string command;
		int checksum; 
	public:
		drawLineCommand(int x1, int y1, int x2, int y2);
		virtual ~drawLineCommand();
		virtual std::string toString();

};



#endif //DRAWLINECOMMAND_H
