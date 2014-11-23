/*
@author Shane Bonner
   relaxCommand.cpp - for the command that will tell the main function to tell the robot to
relax back to its starting position 

*/

#include "../include/relaxCommand.h"

//constructor
relaxCommand::relaxCommand()
{
	char comm = 'r';
}

//destructor
relaxCommand::~relaxCommand()
{

}

relaxCommand::toString()
{
	return comm;
}

