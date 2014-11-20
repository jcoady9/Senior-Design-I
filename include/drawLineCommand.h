#ifndef DRAWLINECOMMAND_H
#define DRAWLINECOMMAND_H

/*
Header file for the command that will tell the main function to send four coordinates
to the robot to use to draw a straight line

*/

#include "commandInterface.h"

class drawLineCommand:public commandInterface
{
	public:
		drawLineCommand();
		~drawLineCommand();
		virtual char toString();

};



#endif //DRAWLINECOMMAND_H
