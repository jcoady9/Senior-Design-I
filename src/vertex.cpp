//vertex.cpp


#include <stddef.h>
#include "../include/vertex.h"
#include "../include/line.h"

//constructor
Vertex::Vertex(int x_coord, int y_coord){
	x = x_coord;
	y = y_coord;
	visited = 0; 
	arr_pos = 0;
	arr_size = 2;
	lines = new Line[arr_size];
}

//destructor
Vertex::~Vertex(){
	delete[] lines;
}

//returns the coordinates of the vertex
void Vertex::getPoint(int point[2]){
	point[0] = x;
	point[1] = y;
}

//adds a new line to the vertex's array
void Vertex::addLine(Line* newLine){
	
	//if the array is full, recreate the array with double the size
	if(arr_pos >= arr_size){
		resize(2 * arr_size);
	}

	lines[arr_pos] =  *newLine;

	lines[arr_pos].setVertex(newLine->getVertex());

	arr_pos++; //increment position in the array
	
}

Line* Vertex::getLine(int n){
	if(n < arr_size){
		return &lines[n];
	}
	return NULL;
}

//resized the array from its original size to an array of size 'newSize'
void Vertex::resize(int newSize){

	/*Line* temp = lines;
	delete[] lines;
	lines = new Line[newSize];
	
	for(int i = 0;  i <arr_size; i++){
		lines[i] = temp[i];
	}
	arr_size = newSize;*/

 		arr_size = newSize;  	         
	        Line* temp; 
	        temp = new Line[arr_size]; 
	 
	        for(int i = 0; i<arr_size; i++){ 
	                temp[i] = lines[i];  
	        } 
	 
	        lines = new Line[newSize];  
	 
	        for(int i = 0; i<arr_size; i++){//recopy temp back into heapArray 
	                lines[i] = temp[i];  
	        }  
	        delete[] temp; 
	
}

//current size of the array
int Vertex::getSize(){
	int size = arr_size;
	return size;
}

//returns number of lines currently in the line array
int Vertex::getNum_Lines(){
	//arr_pos is the position a new element will be added
	int numlines = 0;

	if(arr_pos > 0){
		numlines = arr_pos; 		
	}

	return numlines; 
}

void Vertex::setVisited(int vis){
	visited = vis; 
}

int Vertex::getVisited(){
	int vis = visited;
	return vis; 
}


