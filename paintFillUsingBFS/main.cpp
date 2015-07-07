/*
 * main.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: rudolpharaujo
 */

/*
 * A
simple problem that BFS is good at is the floodfill
problem, mentioned in the DFS section. A floodfill
simply fills all vertices reachable by some source
vertex with the same colour, much like the paint
bucket tool in imageediting programs. The idea is to
visit the vertices in a breadthfirst manner using BFS
and color every vertex as we reach it
 */

bool M[128][128]; // adjacency matrix (can
have at most 128 vertices)
bool seen[128]; // which vertices have been
visited
int n; // number of vertices
// ... Initialize M to be the adjacency
matrix
queue<int> q; // The BFS queue to represent
the visited set
int s = 0; // the source vertex
// BFS floodfill
for( int v = 0; v < n; v++ ) seen[v] =
false; // set all vertices to be "unvisited"
seen[s] = true;
DoColouring( s, some_color );
q.push( s );

while ( !q.empty() ) {
int u = q.front(); // get first
untouched
vertex
q.pop();
for( int v = 0; v < n; v++ ) if(
!seen[v] && M[u][v] ) {
seen[v] = true;
DoColouring( v, some_color );
q.push( v );
}
}


