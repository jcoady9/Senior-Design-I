//the base class for a Vertex, a point of intersecting lines or endpoints.

#ifndef _VERTEX_H__
#define _VERTEX_H__


class Vertex {
	private:
		int x, y;
		Vertex* vertices;
	public:
		Vertex(); //constructor
		~Vertex();				    //destructor
		void resize(int newSize);	    //resizes the verices array
};

#endif
