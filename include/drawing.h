
#ifndef DRAWING_H_
#define DRAWING_H_

#include <vector>

#include "Line.h"

class Drawing {

public:
	Drawing(std::vector<Line> lines); //constructor
	~Drawing(); //destructor
	std::vector<Line> getLines(); //getter method for the vector of lines

private:
	std::vector<Line> dLines; //lines detected from a processed image

};

#endif //DRAWING_H_
