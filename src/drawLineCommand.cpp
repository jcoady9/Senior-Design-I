/*
@author Shane Bonner
   drawLineCommand.cpp - for the command that will tell the main function to use the four
coordinates it has been sent to draw a straight line

*/

#include "../include/drawLineCommand.h"
#include "string.h"

//constructor
drawLineCommand::drawLineCommand()
{
	str::string name = "a"; //CHANGE THIS WHEN NECESSARY. a is the current command on the arduino side. 

}

//destructor
drawLineCommand::~drawLineCommand()
{

}

str::string drawLineCommand::toString()
{
	return name;
}
