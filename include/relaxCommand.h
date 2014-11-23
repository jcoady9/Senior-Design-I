#ifndef RELAXCOMMAND_H
#define RELAXCOMMAND_H

/*
Header file for the command that will tell the main function to tell the robot to
relax back to its starting position
*/


#include "commandInterface.h"
#include "string.h"


class relaxCommand:public commandInterface
{
	public:
		relaxCommand();
		~relaxCommand();
		virtual str::string toString();

};



#endif //RELAXCOMMAND_H
