#ifndef DRAWIMAGESIMULATOR_H
#define DRAWIMAGESIMULATOR_H

#include "drawImageInterface.h"
#include "Line.h"
#include "drawing.h"

class drawImageSimulator: public drawImageInterface
{
public:
	virtual void drawPic(Drawing* drawing);
	virtual Line* scale(Line* i, int imgH, int imgL, int robH, int robW); 
};

#endif // DRAWIMAGESIMULATOR_H
