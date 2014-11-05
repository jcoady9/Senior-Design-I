#ifndef DRAWIMAGESIMULATOR_H
#define DRAWIMAGESIMULATOR_H

#include "drawImageInterface.h"

class drawImageSimulator: public drawImageInterface
{
public:
	virtual void drawPic(FILE* file);

};

#endif // DRAWIMAGESIMULATOR_H
