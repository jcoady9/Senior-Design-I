//the base class for a Vertex, a point of intersecting lines or endpoints.

#ifndef _VERTEX_H__
#define _VERTEX_H__


class Vertex {
	private:
		int x, y;				//x and y-coordinates for the vertex's location
		int visited; 	//tell whether or no the vertex has been visited or not (0= not, 1 = referenced, 2 = processed)
		Vertex* next_vert; //each vertex has one other associated with it
	public:
		Vertex(int x_coord, int y_coord); 	//constructor
		~Vertex();				    	//destructor
		void getPoints(int point[2]);		//returns the coordinates of the vertex
		void setPoints(int xcord, int ycord);		//returns the coordinates of the vertex
		void setVisited(int vis);			//set the visited state of the vertex
		int getVisited();				//returns the visited state of the vertex

};

#endif
