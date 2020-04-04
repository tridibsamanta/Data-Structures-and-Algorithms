#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int source, int destination)
{
    adj[source].push_back(destination);
    //As graph is undirected, there must be an edge from destination to source also
    adj[destination].push_back(source);
}

void displayGraph(vector<int> adj[], int vertices) {
    for(int vertex = 0; vertex < vertices; ++vertex) {
        cout << "Edges from vertex " << vertex << " :\n";
            for(auto itr : adj[vertex])
                cout << "(" << vertex << " -> " << itr << ") ";
            cout << "\n";
    }
}


int main() {
    int totalVertices = 5;
    vector<int> adj[totalVertices];
    //Let's add some edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    //Let's display the edges
    cout << "Graph is - \n";
    displayGraph(adj, totalVertices);
}
