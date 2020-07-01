/**
 * Title     : Depth First Search (DFS) for a graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void dfsUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void dfs(int start);
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph::dfsUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << ' ';
    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfsUtil(*i, visited);
}

void Graph::dfs(int start) {

    bool *visited = new bool[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    dfsUtil(start, visited);
    // Handles the case when graph as more than one component. (disconnected graph)
    for (int i = 0; i < totalVertices; ++i)
        if (visited[i] == false)
            dfsUtil(i, visited);
}

int main() {

    int vertices;
    cout << "Enter the total number of vertices : ";
    cin >> vertices;

    Graph g(vertices);

    int E;
    cout << "Enter the total number of edges : ";
    cin >> E;

    cout << "Enter " << E << " edges (Source Vertex -> Destination Vertex) : ";
    int src, dest;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal : ";
    cin >> startVertex;

    cout << "Depth First Search / Traversal (DFS) is : ";
    g.dfs(startVertex);

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
