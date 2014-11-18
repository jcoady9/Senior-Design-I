#ifndef DRAWIMAGESIMULATOR_H
#define DRAWIMAGESIMULATOR_H

#include "drawImageInterface.h"
#include "vertex.h"

class drawImageSimulator: public drawImageInterface
{
public:
	virtual void drawPic(Vertex* vertex);

};

#endif // DRAWIMAGESIMULATOR_H
