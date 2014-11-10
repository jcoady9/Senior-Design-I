#ifndef DRAWIMAGEINTERFACE_H
#define DRAWIMAGEINTERFACE_H


#include <stdio.h>
#include "vertex.h"


class drawImageInterface
{
	public:
		virtual void drawPic(Vertex* vertex) = 0;
	

};

#endif //DRAWIMAGEINTERFACE_H
