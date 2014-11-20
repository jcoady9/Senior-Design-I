#ifndef _LINE_H__
#define _LINE_H__

#include "vertex.h"
class Line {

	private:
		Vertex * currentVertex;
		Vertex * nextVertex;
	public:
		Line(Vertex * current, Vertex *next);
		~Line();
		void setNextVertex(Vertex* next);//returns the next vertex assoicated with the current one
		Vertex * getNextVertex();//Sets the next vertex assoicated with the current one
		void setCurrentVertex(Vertex* current);//returns the Current vertex assoicated with the current one
		Vertex * getCurrentVertex();//Sets the Current vertex assoicated with the current one

};


#endif //LINE_H
