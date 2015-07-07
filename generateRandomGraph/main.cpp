/*
 * main.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: rudolpharaujo
 */
#include <vector>
#include <iostream>

using namespace std;

// adjaceny list using vector of linked list

struct node
{
	int value;
	node *next;
};


void printGraph (int v, vector<node*> graph)
{
	// iterate the vector
	//for (vector<node*>::iterator it = graph.begin(); it != graph.end(); ++it)
	for (int i = 0; i < v; ++i)
	{
		node* head = graph[i];
		cout  << i << "->";

		while (head != NULL)
		{
			cout << head->value << "->";
			head = head->next;
		}

		cout << "\n";
	}
}

void addEdge (vector<node*> &graph, int src, int dest)
{
	node *destNode =  new node();
	destNode->value = dest;
	destNode->next = graph [src];
	graph[src] = destNode;

	node *srcNode = new node ();
	srcNode->value = src;
	srcNode->next = graph [dest];
	graph[dest] = srcNode;

}

int main ()
{
	int v = 5;
	vector<node*> graph;

	//init the graph
	for (int i = 0; i < v; ++i)
		graph.push_back(NULL);

	addEdge (graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph (v, graph);
}
