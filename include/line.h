#ifndef _LINE_H__
#define _LINE_H__

class Vertex;

class Line {
	private:
		Vertex* next_vertex; //the next vertex to go to
	public:
		Line();
		Line(Vertex* next);	//constructor
		~Line();  		//destructor
		
		Line(const Line& line);
		Line& operator= (const Line& line);
		
		void setVertex(Vertex* v);
		Vertex* getVertex();	//return next_vertex
};

#endif
