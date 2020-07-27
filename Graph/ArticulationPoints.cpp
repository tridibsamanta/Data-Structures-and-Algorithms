/**
 * Title     : Find Articulation Points (cut-vertex) in a graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void findArticulationPointsUtil(int v, bool visited[], int discoveryTime[], int lowTime[], int parent[], bool ap[]);

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void findArticulationPoints();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

void Graph::findArticulationPointsUtil(int v, bool visited[], int discoveryTime[], int lowTime[], int parent[], bool ap[]) {

    static int time = 0;
    int children = 0;

    visited[v] = true;
    discoveryTime[v] = time;
    lowTime[v] = time;
    ++time;

    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {

        int adjV = *i;

        if (!visited[adjV]) {

            ++children;
            parent[adjV] = v;

            findArticulationPointsUtil(adjV, visited, discoveryTime, lowTime, parent, ap);

            lowTime[v] = min(lowTime[v], lowTime[adjV]);

            if (parent[v] == -1 && children > 1)
                ap[v] = true;
            if (parent[v] != -1 && lowTime[adjV] >= discoveryTime[v])
                ap[v] = true;
        }
        else if (adjV != parent[v])
            lowTime[v] = min(lowTime[v], discoveryTime[adjV]);
    }
}

void Graph::findArticulationPoints() {

    bool visited[totalVertices], ap[totalVertices];
    int discoveryTime[totalVertices], lowTime[totalVertices], parent[totalVertices];

    memset(visited, false, sizeof(visited));
    memset(ap, false, sizeof(ap));
    memset(discoveryTime, -1, sizeof(discoveryTime));
    memset(lowTime, -1, sizeof(lowTime));
    memset(parent, -1, sizeof(parent));

    for (int v = 0; v < totalVertices; ++v) {
        if (!visited[v])
            findArticulationPointsUtil(v, visited, discoveryTime, lowTime, parent, ap);
    }

    cout << "Articulation points (Cut-vertex) are : ";
    for (int v = 0; v < totalVertices; ++v)
        if (ap[v])
            cout << v << ' ';
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

    g.findArticulationPoints();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
