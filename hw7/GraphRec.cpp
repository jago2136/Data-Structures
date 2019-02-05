#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "GraphRec.h"
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
                    /*adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);*/
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
            cout<<vertices[i].adj[j].v->name<<"("<<vertices[i].adj[j].weight<<")"<<"***";
        }
        cout<<endl;
    }
    return 0;
}

int main() {
    Graph Graph;
    ifstream myfile;                          
    myfile.open("Recitation.txt");  
    string line;
    vector<string> arr;                   
    if(myfile.is_open()) {
       /*int x = 1;
       while(getline(myfile, line)) {
            istringstream ss(line);
            string token;
            if (x) {
                int j = 0
                while(getline(ss, token, ',')) {
                    if (j) {
                        Graph.addVertex(token);
                        arr.push_back(token);
                    }
                    j = 1;
                }
                x = 0;
            }
            else {

                 while(getline(ss, token, ',')) {

            }
        }
    }*/
        string line;
        getline(myfile, line);
        stringstream ss(line);
        string curr;
        getline(ss, curr, ' ');
        vector<string> arr;
        while (getline(ss, curr,' ')) {
            cout<< curr<< endl;
            Graph.addVertex(curr);
            arr.push_back(curr);
        }

        while (getline(myfile, line)) {
            stringstream ss(line);
            string src;
            cout<< line<<endl;
            getline(ss, src, ' ');
            int i = 0;
            string newWord;
            while (getline(ss, newWord,' ')) {
                Graph.addEdge (src, arr[i], stoi(newWord));
                cout<< src<<" "<< arr[i]<< newWord<<endl;
                i++;
            }
        }
    }
}

