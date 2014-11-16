//vec2vertex.cpp

//Convert Vec4i into two verticies, then append them.


#include <stdio.h>
#include <stddef.h>
#include "../include/vertex.h"
#include "../include/vec2vertex.h"

Vertex* vec2Vertex(cv::Vec4i vec)
{
	Vertex* v1 = new Vertex(vec[0], vec[1]);
	
	Vertex* v2 = new Vertex(vec[2], vec[3]);

	v1->setNextVertex(v2);
	
	return v1;
}
