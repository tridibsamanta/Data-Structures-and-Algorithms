/**
 * Title     : Connected components in an undirected graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void connectedComponentsUtil(int s, bool visited[]);
public:
    Graph(int v);
    int countCC = 0;
    void addEdge(int src, int dest);
    void findConnectedComponents();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<int> [totalVertices];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

void Graph :: findConnectedComponents() {
    bool *visited = new bool[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;
    for (int i = 0; i < totalVertices; ++i) {
        if (!visited[i]) {
            connectedComponentsUtil(i, visited);
            ++countCC;
            cout << '\n';
        }
    }
    delete[] visited;
}

void Graph :: connectedComponentsUtil(int s, bool visited[]) {
    visited[s] = true;
    cout << s << ' ';
    vector <int> :: iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            connectedComponentsUtil(*i, visited);
}

int main() {

    int vertices;
    cout << "Enter the total number of vertices : ";
    cin >> vertices;

    Graph g(vertices);

    int E;
    cout << "Enter the total number of edges : ";
    cin >> E;

    cout << "Enter " << E << " edges : ";
    int src, dest;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Connected components in the undirected graph : ";
    g.findConnectedComponents();

    cout << "Number of connected components = " << g.countCC << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Auxiliary Space  : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
