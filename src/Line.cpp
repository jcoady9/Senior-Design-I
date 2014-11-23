#include "../include/Line.h"



Line::Line(Vertex * current, Vertex * next){
	currentVertex = current;
	nextVertex = next;
}
Line::~Line(){

}

//Gets the Current vertex assoicated with the current one
Vertex* Line::getCurrentVertex(){
	return currentVertex;
}
//Sets the Current vertex assoicated with the current one
void Line::setCurrentVertex(Vertex* current){
	currentVertex = current; 
}

//Gets the next vertex assoicated with the current one
Vertex* Line::getNextVertex(){
	return nextVertex;
}
//Sets the next vertex assoicated with the current one
void Line::setNextVertex(Vertex* next){
	nextVertex = next; 
}

