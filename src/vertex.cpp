//vertex.cpp

#include "../include/vertex.h"

//constructor
Vertex::Vertex(){
	x = 0;
	y = 0;
	vertices = new Vertex[1];
}

//destructor
Vertex::~Vertex(){
	delete[] vertices;
}

void Vertex::resize(int newSize){
	
}
