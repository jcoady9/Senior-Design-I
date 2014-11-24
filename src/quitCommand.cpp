/*
@author Shane Bonner
   quitCommand.cpp - for the command that will tell the main function to tell the robot to
relax back to its starting position and quit the program

*/

#include "../include/quitCommand.h"
#include <string>

//constructor
quitCommand::quitCommand()
{
	 command = "q";
}

//destructor
quitCommand::~quitCommand()
{

}
/**
	**@return the command
**/
std::string quitCommand::toString()
{
	return command;
}


