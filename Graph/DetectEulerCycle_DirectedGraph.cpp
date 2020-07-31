/**
 * Title     : Detect Euler Cycle(Circuit) for directed graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    int *in;
    bool isStronglyConnected();
    void dfs(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int src, int dest);
    bool containsEulerCycle();
    Graph getTranspose();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
    in = new int[V];
    for (int i = 0; i < V; ++i)
        in[i] = 0;
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    in[dest]++;
}

Graph Graph::getTranspose() {
    Graph g(totalVertices);
    for (int v = 0; v < totalVertices; ++v) {
        vector<int> :: iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            g.adj[*i].emplace_back(v);
    }
    return g;
}

void Graph::dfs(int v, bool visited[]) {
    visited[v] = true;
    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited);
}

bool Graph::isStronglyConnected() {

    bool visited[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    int v;
    for (v = 0; v < totalVertices; ++v)
        if (adj[v].size() > 0)
            break;

    dfs(v, visited);

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() > 0 && !visited[i])
            return false;

    Graph gT = getTranspose();

    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    gT.dfs(v, visited);

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() > 0 && !visited[i])
            return false;

    return true;
}

bool Graph::containsEulerCycle() {

    if (!isStronglyConnected())
        return false;

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() != in[i])
            return false;

    return true;
}

int main() {

    int vertices;
    cout << "Enter the total number of vertices : ";
    cin >> vertices;

    Graph g(vertices);

    int edges;
    cout << "Enter the total number of edges : ";
    cin >> edges;

    cout << "Enter " << edges << " edges : ";
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    if (g.containsEulerCycle())
        cout << "Graph contains Euler Cycle";
    else
        cout << "Graph does not contain Euler Cycle";

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V + E)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
