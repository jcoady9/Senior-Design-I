//drawing.cpp

#include "../include/drawing.h"

/*
 *constructor
 *
 *@param lines - vector of Line objects to store in this instance of the Drawing object
*/
Drawing::Drawing(std::vector<Line> lines, int width, int height){
	dLines = lines;
	dimWidth = width;
	dimHeight = height;
}

/*
 * destructor
*/
Drawing::~Drawing(){
	dLines.clear();
}

/*
 * getter method for the vector of lines
 *
 *@return - returns the vector of lines
*/
std::vector<Line> Drawing::getLines(){
	return dLines;
}

/*
 * getter method for the width of the drawable image
 *
 *@return - the width of the drawable image
*/
int Drawing::getDrawingWidth(){
	return this->dimWidth;
}

/*
 *getter for the height of the drawable image
 *
 *@return - the height of the drawable image
*/
int Drawing::getDrawingHeight(){
	return this->dimHeight;
}
