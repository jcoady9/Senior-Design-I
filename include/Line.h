//Line.h

#ifndef _LINE_H__
#define _LINE_H__

#include "point.h"

class Line {

	private:
		Point * endPoint1;
		Point * endPoint2;
	public:
		Line(Point *p1, Point *p2);
		~Line();
		void setPoint2(Point *p2);//returns the next vertex assoicated with the current one
		Point * getPoint2();//Sets the next vertex assoicated with the current one
		void setPoint1(Point *p1);//returns the Current vertex assoicated with the current one
		Point * getPoint1();//Sets the Current vertex assoicated with the current one

};

#endif //LINE_H
