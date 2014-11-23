#ifndef QUITCOMMAND_H
#define QUITCOMMAND_H


/*
Header file for the command that will tell the main function to tell the robot to
relax back to its starting position and quit the program
*/


#include "commandInterface.h"
#include "string.h"

class quitCommand:public commandInterface
{
	public:
		quitCommand();
		~quitCommand();
		virtual str::string toString();

};


#endif //QUITCOMMAND_H
