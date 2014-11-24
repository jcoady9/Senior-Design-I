/*
@author Shane Bonner
   relaxCommand.cpp - for the command that will tell the main function to tell the robot to
relax back to its starting position 

*/

#include "../include/relaxCommand.h"
#include <string>

//constructor
relaxCommand::relaxCommand()
{
	 command = "r";
}

//destructor
relaxCommand::~relaxCommand()
{

}

std::string relaxCommand::toString()
{
	return command;
}

