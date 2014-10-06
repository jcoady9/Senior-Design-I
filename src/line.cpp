
#include <stddef.h>
#include "../include/line.h"

//constructors
Line::Line(){
	next_vertex = NULL;
}

Line::Line(Vertex* next){
	next_vertex = next;
}

//destructor
Line::~Line(){
	
}

Line::Line(const Line &line){
	next_vertex = line.next_vertex;
}

//assignment operator
Line& Line::operator= (const Line& line){

	next_vertex = line.next_vertex;
	
	return *this;
}

void Line::setVertex(Vertex* v){
	next_vertex = v;
}

//returns the next vertex
Vertex* Line::getVertex(){
	return next_vertex;
}
