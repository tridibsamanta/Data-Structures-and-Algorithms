/**
 * Title     : Detect Euler Cycle(Circuit) or Euler Path for undirected graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    bool isConnected();
    void dfs(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int src, int dest);
    int checkEulerCycleEulerPath();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

void Graph::dfs(int v, bool visited[]) {
    visited[v] = true;
    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited);
}

bool Graph::isConnected() {

    bool visited[totalVertices];
    int i;
    for (i = 0; i < totalVertices; ++i)
        visited[i] = false;

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() > 0)
            break;

    if (i == totalVertices)
        return true;

    dfs(i, visited);

    for (i = 0; i < totalVertices; ++i)
        if (visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}

int Graph::checkEulerCycleEulerPath() {

    if (isConnected() == false)
        return 0;

    int oddDegreeVertex = 0;
    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() & 1)
            ++oddDegreeVertex;

    if (oddDegreeVertex > 2)
        return 0;

    return (oddDegreeVertex) ? 1 : 2;
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

    /*
        value = 0 -> Graph does not contain Euler Path or Cycle
        value = 1 -> Graph contains Euler Path
        value = 2 -> Graph contains Euler Cycle
    */
    int value = g.checkEulerCycleEulerPath();

    if (value == 0)
        cout << "Graph does not contain Eulerian Path or Eulerian Cycle";
    else if (value == 1)
        cout << "Graph contains Eulerian Path";
    else
        cout << "Graph contains Eulerian Cycle";

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V + E)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
