#ifndef DRAWIMAGEINTERFACE_H
#define DRAWIMAGEINTERFACE_H


#include <stdio.h>
#include "Line.h"


class drawImageInterface
{
	public:
		virtual void drawPic(Line * l) = 0;
	

};

#endif //DRAWIMAGEINTERFACE_H
