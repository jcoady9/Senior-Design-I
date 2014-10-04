/*
 * dfs.cpp
 * 
 * Copyright 2014 Jason Fiddle <jfiddle@J-FId-VirtualBox>
 */

void DFS(Graph G)
{
	for each(Vertex u in G.V)
	{
		u.color = WHITE;
		u.pi = NULL;
	}
	
	time = 0;
	
	for each(Vertex u in G.V)
	{
		if(u.color == WHITE)
			DFS_Visit(G, u);
	}
}

void DFS_Visit(Graph G, Vertex u)
{
	time++;
	u.d = time;
	u.color = GRAY
	
	for each(v in G.Adj[u])
	{
		if(v.color == WHITE)
		{
			v.pi = u;
			DFS_Visit(G, v);
		}
	}
	
	u.color = BLACK;
	time++;
	u.f = time;
}





