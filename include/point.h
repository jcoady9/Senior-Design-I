//vertex.h

//The base class for a Vertex, a point of intersecting lines or endpoints.

#ifndef _VERTEX_H__
#define _VERTEX_H__

/*
 * model class to store cartesian coordinates of line endpoints
*/
class Point {
	private:
		int x, y;								//x and y-coordinates for the vertex's location

	public:
		Point(int x, int y); 					//constructor
		~Point();				    			//destructor
		void getCoords(int point[2]);			//returns the coordinates of the vertex
		void setCoords(int xcord, int ycord);	//sets the coordinates of the vertex
};

#endif
