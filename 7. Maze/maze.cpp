//EC330 HW 7
//Dong Hyun Kim
//Edwardo Portet

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <list>

#define INF 0x3f3f3f3f

using namespace std;
 
// This class represents a directed graph using 
// adjacency list representation
class Graph {
	int V; // Vertices
	list< pair<int, int> > *adj; // Vertex and weigth pair
	public:
		Graph(int V);  // Constructor

		// function to add an edge to graph
		void addEdge(int u, int v, int w);

		// prints shortest path from s
		void shortestPath(int s);
};
 
// Adjacency list
Graph::Graph(int V) {
	this->V = V;
	adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest path to target from source
void Graph::shortestPath(int src) {
	// Create a set to store vertices
	set< pair<int, int> > setds;

	// Initialize all distances to INF
	vector<int> dist(V, INF);

	setds.insert(make_pair(0, src));
	dist[src] = 0;

	while (!setds.empty()) {
		
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight)
			{
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));

				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distance
	if(dist[V-1] == INF) {
		cout << 0 << endl;
	}
	else {
		cout << dist[V-1] << endl;
	}
}
 
int main() {
		
	string filename = "maze.txt";
	string line = "";
	ifstream file(filename.c_str());
	int n = 0;
	char digit = 0;

	while(file >> line) {
		n++; // Count the size of the graph
	}

	int maze[n*n];
	file.clear();
	file.seekg(0, file.beg);

	for (int i = 0; i < n*n; ++i) {
		file >> digit;
		maze[i] = digit;
	}

	// create the graph
	int V = n*n;
	Graph g(V);

	// Add all the edges in the maze to the graph
	for (int i = 0; i < n*n; ++i) {
		for (int j = i+1; j < n*n; ++j) {
			if (maze[i] == '1' && maze[j] == '1' && (j == i+1) && (i+1)%n != 0 ) {
				//cout << "Vertex " << i << " has an edge with vertex " << j << endl;
				g.addEdge(i,j,1);
			}
			else if (maze[i] == '1' && maze[j] == '1' && j == i+n) {
				//cout << "Vertex " << i << " has an edge with vertex " << j << endl;
				g.addEdge(i,j,1);
			}
		}
	}

	// Print the shortest path
	g.shortestPath(0);

	return 0;
}