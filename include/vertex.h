//the base class for a Vertex, a point of intersecting lines or endpoints.

#ifndef _VERTEX_H__
#define _VERTEX_H__


class Line;

class Vertex {
	private:
		int x, y;				//x and y-coordinates for the vertex's location
		int arr_pos, arr_size;	//current position in the array, and the size of the array respectively
		Line* lines;			//an array of Line objects to keep track of lines intersecting the vertex
		int visited; 	//tell whether or no the vertex has been visited or not (0= not, 1 = referenced, 2 = processed)
	public:
		Vertex(int x_coord, int y_coord); 	//constructor
		~Vertex();				    	//destructor
		void getPoint(int point[2]);		//returns the coordinates of the vertex
		void addLine(Line* line);			//adds a line to the lines array
		Line* getLine(int n);			//retrieve a line from the lines array
		void resize(int newSize);	    //resizes the verices array
		int getSize();				//returns current line array size
		int getNum_Lines(); 			//returns the number of lines in the array
		void setVisited(int vis);			//set the visited state of the vertex
		int getVisited();				//returns the visited state of the vertex

};

#endif
