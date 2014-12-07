//Line.cpp

#include "../include/Line.h"

//constructor
Line::Line(Point *p1, Point *p2){
	endPoint1 = p1;
	endPoint2 = p2;
}
//destructor
Line::~Line(){
}

/**
	**Gets the Current vertex assoicated with the current one
	** @return the Current Vertex
**/
	
Point * Line::getPoint1(){
	return endPoint1;
}

/**
	**Sets the Current vertex assoicated with the current one
**/
void Line::setPoint1(Point *p1){
	endPoint1 = p1; 
}

/**
	**Gets the Next vertex assoicated with the current one
	** @return the Next Vertex
**/
Point * Line::getPoint2(){
	return endPoint2;
}

/**
	**Sets the next vertex assoicated with the current one
**/
void Line::setPoint2(Point *p2){
	endPoint2 = p2; 
}
