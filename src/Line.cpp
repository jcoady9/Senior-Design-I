//Line.cpp

#include "../include/Line.h"


//constructor
Line::Line(Vertex * current, Vertex * next){
	currentVertex = current;
	nextVertex = next;
}
//destructor
Line::~Line(){

}

/**
	**Gets the Current vertex assoicated with the current one
	** @return the Current Vertex
**/
Vertex* Line::getCurrentVertex(){
	return currentVertex;
}
/**
	**Sets the Current vertex assoicated with the current one
**/
void Line::setCurrentVertex(Vertex* current){
	currentVertex = current; 
}

/**
	**Gets the Next vertex assoicated with the current one
	** @return the Next Vertex
**/
Vertex* Line::getNextVertex(){
	return nextVertex;
}
/**
	**Sets the next vertex assoicated with the current one
**/
void Line::setNextVertex(Vertex* next){
	nextVertex = next; 
}

