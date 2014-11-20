
#include "../include/drawing.h"

/*
 *constructor
 *
 *@param lines - vector of Line objects to store in this instance of the Drawing object
*/
Drawing::Drawing(std::vector<Line> lines){
	dLines = lines;
}

/*
 * destructor
*/
Drawing::~Drawing(){
	lines.clear();
}

/*
 * getter method for the vector of lines
 *
 *@return - returns the vector of lines
*/
std::vector<Line> Drawing::getLines(){
	return dLines;
}
