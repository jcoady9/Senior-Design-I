/*
 * dfs.cpp
 * 
 * Copyright 2014 Jason Fiddle <jfiddle@J-FId-VirtualBox>
 */
#include "vertex.cpp"


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
}

void DFS_Visit(Graph G, Vertex u)
{
	//time++;
	//u.d = time;
	u.color = GRAY
	//visit all other vertices associated with current vertex
	//TODO: need to know structure of vertex class before we can continue
	for each(v in G.Adj[u])
	{
		if(v.color == WHITE)
		{
			v.pi = u;
			DFS_Visit(G, v);
		}
	}
	
	u.color = BLACK;
	//time++;
	//u.f = time;
}
*/



