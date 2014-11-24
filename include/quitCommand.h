#ifndef QUITCOMMAND_H
#define QUITCOMMAND_H


/*
Header file for the command that will tell the main function to tell the robot to
relax back to its starting position and quit the program
*/

#include <stdlib.h>
#include <string>
#include "commandInterface.h"


class quitCommand:public commandInterface
{
	private: 
		std::string command;
	public:
		quitCommand();
		~quitCommand();
		std::string toString();

};


#endif //QUITCOMMAND_H
