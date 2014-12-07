//drawing.h

#ifndef DRAWING_H_
#define DRAWING_H_

#include <vector>
#include "Line.h"

/*
 * model class to store detected lines and source image dimensions after source image has been processed
*/
class Drawing {

public:
	Drawing(std::vector<Line> lines, int width, int height); //constructor
	~Drawing(); //destructor
	std::vector<Line> getLines(); //getter method for the vector of lines
	int getDrawingWidth();		//getter method for the width of the drawing
	int getDrawingHeight();		//getter method for the height of the drawing

private:
	std::vector<Line> dLines; //lines detected from a processed image
	int dimWidth, dimHeight; //width and height of the drawable image

};

#endif //DRAWING_H_
