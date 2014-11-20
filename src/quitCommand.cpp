/*
@author Shane Bonner
   quitCommand.cpp - for the command that will tell the main function to tell the robot to
relax back to its starting position and quit the program

*/

#include "../include/quitCommand.h"

//constructor
quitCommand::quitCommand()
{
	char comm = 'q';
}

//destructor
quitCommand::~quitCommand()
{

}

quitCommand::toString()
{
	return comm;
}


