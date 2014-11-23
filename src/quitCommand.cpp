/*
@author Shane Bonner
   quitCommand.cpp - for the command that will tell the main function to tell the robot to
relax back to its starting position and quit the program

*/

#include "../include/quitCommand.h"
#include "string.h"

//constructor
quitCommand::quitCommand()
{
	str::string comm = 'q';
}

//destructor
quitCommand::~quitCommand()
{

}

str::string quitCommand::toString()
{
	return comm;
}


