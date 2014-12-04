//vertex.h

//The base class for a Vertex, a point of intersecting lines or endpoints.

#ifndef _VERTEX_H__
#define _VERTEX_H__


class Vertex {
	private:
		int x, y;								//x and y-coordinates for the vertex's location

	public:
		Vertex(int x_coord, int y_coord); 		//constructor
		~Vertex();				    			//destructor
		void getPoints(int point[2]);			//returns the coordinates of the vertex
		void setPoints(int xcord, int ycord);	//sets the coordinates of the vertex
};

#endif
