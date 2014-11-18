//vertex.cpp


#include <stddef.h>
#include "../include/vertex.h"

//constructor
Vertex::Vertex(int x_coord, int y_coord){
	x = x_coord;
	y = y_coord;
	visited =0;
	next_vert = NULL;
}

//destructor
Vertex::~Vertex(){
}

//returns the coordinates of the vertex
void Vertex::getPoints(int point[2]){
	point[0] = x;
	point[1] = y;
}

//sets the coordinates of the vertex
void Vertex::setPoints(int xcord, int ycord){
	x = xcord;
	y= ycord;
}
//Sets whether or not a vertex has been visited
void Vertex::setVisited(int vis){
	visited = vis; 
}
//Gets whether or not a vertex has been visited
int Vertex::getVisited(){
	return visited; 
}
//Gets the next vertex assoicated with the current one
Vertex* Vertex::getNextVertex(){
	return next_vert;
}
//Sets the next vertex assoicated with the current one
void Vertex::setNextVertex(Vertex* next){
	next_vert = next; 
}

