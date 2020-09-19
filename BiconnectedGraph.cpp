/**
 * Title     : Check whether a given undirected graph is biconnected
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    bool isBiconnectedUtil(int u, bool visited[], int discoveryTime[], int lowTime[], int parent[], int &time);

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void isBiconnected();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

bool Graph::isBiconnectedUtil(int u, bool visited[], int discoveryTime[], int lowTime[], int parent[], int &time) {

    visited[u] = true;
    discoveryTime[u] = lowTime[u] = time++;

    int child = 0;

    vector<int> :: iterator itr;
    for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {

        int v = *itr;

        if (!visited[v]) {

            ++child;
            parent[v] = u;

            if (!isBiconnectedUtil(v, visited, discoveryTime, lowTime, parent, time))
                return false;

            lowTime[u] = min(lowTime[u], lowTime[v]);

            if (parent[u] == -1 && child > 1)
                return false;
            if (parent[u] != -1 && lowTime[v] >= discoveryTime[u])
                return false;
        }
        else if (v != parent[u])
            lowTime[u] = min(lowTime[u], discoveryTime[v]);
    }

    return true;
}

void Graph::isBiconnected() {

    bool visited[totalVertices];
    int discoveryTime[totalVertices], lowTime[totalVertices], parent[totalVertices];

    memset(visited, false, sizeof(visited));
    memset(discoveryTime, -1, sizeof(discoveryTime));
    memset(lowTime, -1, sizeof(lowTime));
    memset(parent, -1, sizeof(parent));

    int time = 0;

    if (!isBiconnectedUtil(0, visited, discoveryTime, lowTime, parent, time)) {
        cout << "Graph is not biconnected.\n";
        return;
    }

    for (int v = 0; v < totalVertices; ++v) {
        if (!visited[v]) {
            cout << "Graph is not biconnected.\n";
            return;
        }
    }

    cout << "Graph is biconnected.\n";
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

    g.isBiconnected();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
