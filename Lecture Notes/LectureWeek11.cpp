#include <iostream>
#include <string>
using namespace std;

/*
Goal of BFT (traversal): traverse (and print) entire graph in a BF order
Goal of BFS (search): find a vertex via shortest path

Differences between BFT and BFS
	- BFS takes in 2 values
	- add "distance" numeric value to vertex struct
	- increment distance of each vertex as each "later" is traversed
	- return vertex if/when found
		* distance from starting vertex will be encoded in the returned vertex
		* update the vertex struct:
			struct vertex {
				string key;
				vector <adjVertex>;
				bool visited;
				int distance;
			}

// only for the non-weighted graph
BFS Algorithm: 
	vertex BreadthFirstSearch (startValue, searchValue) {
		vertex = search(startValue);
		vertexVisited = T;
		vertex.distance = 0;
		que.enque(vertex);
		while(!queIsEmpty) {
			n = que.deque();
			for x = 0 to n.adj.end 
				if (!n.adj[x].v.visited)
					n.adj[x].v.distance = n.distance + 1
					if (n.adj[x].v.key == searchValue)
						return n.adj[x].v;
					else 
						n.adj[x].v.visited = T;
						que.enque(n.adj[x].v)
		}
	}

Depth First
	Instead of evaluating all the vertices in the adjacent "layer" before moving onto the next layer, with
	the depth first approach, we evaluate each branch until we find the furthest vertex
	DFT(a) 
	Either do it recursively, or do it iteratively
		- Recursive algorithm
			DFT(vertex) {
				vertex.visited = True;
				for x = 0 to vertex.adjacent.end
					if (!vertex.adjacent[x].v.visited)
						print vertex.adj[x].v.key
						DFT (vertex.adj[x].v)
			}
Breadth first finds the shortest path in an unweighted graph.
But what if we have weights?
Use Dijkstra's algorithm!
	Finds the shortest path in a weighted graph, where all edge weights are strictly positive 
	MUST be greater than zero!!!
	Update the struct vertex:

	struct {
		string key;
		vector <adjVertex> adj;
		bool solved;
		vertex *parent;
	}

	vertex Dijkstra (start, end) {
		find start vertex;
		find end vertex;
		startV.solved = true;
		solvedList.add(startV);  // list of the solved vertices
		while(!endV.solved) {
			minimalDistance = INT.MAX  // initialize to some huge value
			for (each V in solved list) {
				for (each 'a' in v.adjacent) {
					if a !solved;
						calclate the distance to 'a' from start;
						if dist < mindist
							store 'a' as minVertex
							mindist = dist
							a.parent = v;
				}
			}
		}
		return endV;
	}

	Keep in mind the distance is the sum of the weighted edges, not the number of edges.
	"Solved" is like "visited" except its only marked if its the min distance vertex.

Hash Tables
	A hash table (aka a hash map) is a data structures that uses a mapping to assign a record to a unique
	index of an array
	Say we want to store the student ID's of students
		key: name
		value : SID (student id)
		hashF("Anna") -> 2
		hashF("Jamie") -> 0
		hashF("Brian") -> 1
		hashf("Laura") -> 3
	Two components to a hash table
		- an array of structs for storing the records
		- a hash function for generating the unique code from a key
			* hash functions are perfectly repeatable, calling a name will always result in the same value
			* for instance, above, calling "Anna" will always result in 2
Hash Functions:
	One of the simplest hash functions is to sum the values in a string and mod(%) by array length (table size)
	int hashsum (key, keylength, tableSize) {
		sum = 0;
		for i = 0 to key length
			sum = sum + key[i]
		return (sum % tableSize)
	}

	Example:
		key = "Anna"
		keyL = 4
		tablesize = 4
		A = 41 n = 110 n = 110 a = 97
		(the sum of this) % 4 = 2
		what if the sum changes, lets say the table size is 5
		358 % 5 = 3;
		Hash value (index) is a function of table size

	Store records in a has table:
		- calculate the index (hash the key)
		- write data to hash table of the index
	Retrieve Records:
		- use search key to calculate the index
		- read from the index
			index = hash("Anna", 4, 4)
			student = studentsTable[index]
	Collisions:
		Consider if you have two nonunique ascii values
		Each array location can only store a single record, but now we have 2 records occupying the same space
		However, you could put a linked list in each cell
		Regardless, you should develop an algorithm in which the number of collisions is minimized


*/

int main () {
	return 0;
}