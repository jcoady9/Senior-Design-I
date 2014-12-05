//relaxCommand.h

#ifndef RELAXCOMMAND_H
#define RELAXCOMMAND_H

/*
Header file for the command that will tell the main function to tell the robot to
relax back to its starting position
*/


#include "commandInterface.h"
#include <string>


class relaxCommand:public commandInterface
{
	private: 
		std::string command;
	public:
		relaxCommand();
		virtual ~relaxCommand();
		virtual std::string toString();

};



#endif //RELAXCOMMAND_H
