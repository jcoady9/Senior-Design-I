/*
@author Shane Bonner
   relaxCommand.cpp - for the command that will tell the main function to tell the robot to
relax back to its starting position 

*/

#include "../include/relaxCommand.h"
#include "string.h"

//constructor
relaxCommand::relaxCommand()
{
	str::string comm = "r";
}

//destructor
relaxCommand::~relaxCommand()
{

}

str::string relaxCommand::toString()
{
	return comm;
}

