#include <iostream>
#include <string>
using namespace std;

/*
A basic ADT:
private: 
	vertices

public:
	init()
	insertVertex(value)
	insertEdge(startValue, endValue, weight)
	deleteVertex(value)
	deleteEdge(startValue, endValue)
	printGraph()
	search()

struct vertex {
	string key;
	vector <adjVertex> adj;    // vector key word, then the data type (int, string, etc), then name of the varible
							   // keeps a list of adjancencies
};

struct adjVertex {
	vertex *v;    // pointer to a vertex type
	int weight;
};

intsertVertex (value) {
	bool found = false;  // you only have one of each vector, see if what you're trying to add already exists
	loop (over entire vector of vertices) {
		if (matching value found at some vertex i) {
			set found to true
			break loop with index i  // can't have repeat values
		}
	}
	if (found is still false) {
		value doesnt exist, append new value as new vertex
	}
	return
}

insertEdge (startValue, endValue, weight) {
	find two values in the graph
	connect with edges (one in each direction)
	for x = 0 to vertices.end {
		if vertices[x] == startValue
			for y = 0 to vertices.end
				if vertices[y] == endValue and x not equal to y
					append new edge onto adjacency list of vertex == startValue
					w/ a pointer to vertex == endValue
					and specified weight
					add new edge in opposite direction
}

printGraph(){
	loop agin across all vertices
		print each vertex key
		print key of each adjacent vertex
		print weight of each edge
}

search(value) {
	loop across all vertices
		if key mathces value
			return vertex
	return NULL
}

firstTraverse (value) {
	vertex = search(value);
	print(vertex.key);
	vertex.visited = true;
}
*/


int main () {
	return 0;
}