#ifndef DRAWIMAGESIMULATOR_H
#define DRAWIMAGESIMULATOR_H

#include "drawImageInterface.h"
#include "../include/vertex.h"

class drawImageSimulator: public drawImageInterface
{
public:
	virtual void drawPic(Vertex vertex); //CHANGE PARAMETER

};

#endif // DRAWIMAGESIMULATOR_H
