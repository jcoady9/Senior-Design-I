/*
 * dfs.cpp
 * 
 * Copyright 2014 Jason Fiddle <jfiddle@J-FId-VirtualBox>
 */
#include "vertex.cpp"

void DFS_Visit(Vertex* v);
/*
**DFS will take one argument, the graph in which we need to parse through
**The Graph is represents simply by an array of Vertices

void DFS(Vertex arr[])
{//Note: varibles will need to be changed depending on our needs
	for(int i = 1; i<arr[0]; i++)
	{
		u.color = WHITE;
		//Pi should not be needed. We do not need to know 
		//where we came from just where we are headed.
		//u.pi = NULL;
	}
	
	//time will also be needed. We do not need to know how long it 		
	//took us to visit a vertex, only that the vertex as been visited.  
	//time = 0;
	
	for(int i = 1; i<arr[0]; i++)
	{
		if(u.color == WHITE)
			DFS_Visit(G, u);
	}
}*/
//Accepts first vertex and accesses all other via the Line's next vertex functionality.
void DFS_Visit(Vertex* v)
{
	//visit all other vertices associated with current vertex
	for(int i = 0; i<v->getNum_Lines(); i++)
	{
		if(v->getLine(i)->getVertex()->getVisited == 0)
		{
			//TODO: Call the draw line method
			DFS_Visit(v->getLine(i)->getVertex());
		}
	}
	
	v->setVisited(2);

}




