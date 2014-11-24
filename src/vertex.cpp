//vertex.cpp


#include <stddef.h>
#include "../include/vertex.h"

//constructor
Vertex::Vertex(int x_coord, int y_coord){
	x = x_coord;
	y = y_coord;
	visited = 0;
}

//destructor
Vertex::~Vertex(){
}

/**
	**Getter for a Vertex's x and y points
	**writes the points to a presupplied array
**/
void Vertex::getPoints(int point[2]){
	point[0] = x;
	point[1] = y;
}
/**
	**sets the x and y coordinates of the vertex
**/
void Vertex::setPoints(int xcord, int ycord){
	x = xcord;
	y = ycord;
}

//Gets whether or not a vertex has been visited
int Vertex::getVisited(){
	return visited; 
}


//Sets whether or not a vertex has been visited
void Vertex::setVisited(int vis){
	visited = vis; 
}



