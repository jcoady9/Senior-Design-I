//vec2vertex.cpp
//Convert Vec4i into verticies. 

#include <stdio.h>
#include <stddef.h>
#include "../include/vertex.h"
#include "../include/line.h"
#include "../include/vec2vertex.h"

Vertex* vec2Vertex(cv::Vec4i vec)
{
	Vertex* v1 = new Vertex(vec[0], vec[1]);
	
	Vertex* v2 = new Vertex(vec[2], vec[3]);
	Line* l = new Line(v2);
	v1->addLine(l);
	
	return v1;
}
