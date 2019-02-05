#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}
 ///////////////////////////////////////// main

#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


int main()
{
    Graph g;
    g.addVertex("Boulder");
    g.addVertex("Denver");
    g.addVertex("New Mexico");
    g.addVertex("Texas");
    g.addVertex("New Orleans");
    //edge written to be undirected
    g.addEdge("Boulder", "Denver", 30);
    g.addEdge("Boulder", "New Mexico", 200);
    g.addEdge("Boulder", "Texas", 500);
    g.addEdge("Denver", "Texas", 300);
    g.addEdge("Texas", "New Orleans", 500);
    g.displayEdges();
    return 0;
}

//////////////////////////// header

#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;

};

#endif // GRAPH_H

