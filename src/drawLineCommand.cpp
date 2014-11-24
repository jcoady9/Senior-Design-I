/*
@author Shane Bonner
   drawLineCommand.cpp - for the command that will tell the main function to use the four
coordinates it has been sent to draw a straight line

*/
#include <sstream>
#include "../include/drawLineCommand.h"
#include <string>
#include <stdio.h>


//constructor
drawLineCommand::drawLineCommand(int x1, int y1, int x2, int y2)
{
	checksum = x1 + y1 + x2 + y2;
	//write the ints to a char * so they can be 
	//converted to string
	std::stringstream ssx,ssy,ssxx,ssyy,ssc;
	ssx << x1;
	ssy << y1;
	ssxx << x2;
	ssyy << y2;
	ssc << checksum;
	command = "a,";
	command.append(ssx.str());
	command.append(",");
	command.append(ssy.str());
	command.append(",");
	command.append(ssxx.str());
	command.append(",");
	command.append(ssyy.str());
	command.append(",");
	command.append(ssc.str());/**/
}

//destructor
drawLineCommand::~drawLineCommand()
{

}

std::string drawLineCommand::toString()
{
	return command;
}
