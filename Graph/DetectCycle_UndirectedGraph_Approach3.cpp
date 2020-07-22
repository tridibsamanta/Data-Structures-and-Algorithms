/**
 * Title     : Detect Cycle in an Undirected Graph (Using Disjoint Sets)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void makeSet(int parent[], int rank[]);
    int findSet(int parent[], int v);
    void performUnion(int parent[], int rank[], int v1, int v2);
public:
    Graph(int v);
    void addEdge(int src, int dest);
    bool detectCycle();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<int> [totalVertices];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph :: makeSet(int parent[], int rank[]) {
    for (int v = 0; v < totalVertices; ++v) {
        parent[v] = v;
        rank[v] = 0;
     }
}

int Graph :: findSet(int parent[], int v) {
    // Applying path compression
    if (parent[v] != v)
        parent[v] = findSet(parent, parent[v]);

    return parent[v];
}

void Graph :: performUnion(int parent[], int rank[], int v1, int v2) {

    int v1Set = findSet(parent, v1);
    int v2Set = findSet(parent, v2);

    // Applying union by rank
    if (rank[v1Set] < rank[v2Set])
        parent[v1Set] = v2Set;
    else if (rank[v1Set] > rank[v2Set])
        parent[v2Set] = v1Set;
    else {
        parent[v2Set] = v1Set;
        ++rank[v1Set];
    }
}

bool Graph :: detectCycle() {

     int parent[totalVertices], rank[totalVertices];
     makeSet(parent, rank);

     for (int v = 0; v < totalVertices; ++v) {

        for (int i = 0; i < adj[v].size(); ++i) {

            int v1Set = findSet(parent, v);
            int v2Set = findSet(parent, adj[v][i]);

            if (v1Set == v2Set)
                return true;

            performUnion(parent, rank, v, adj[v][i]);
        }
     }
     return false;
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

    if (g.detectCycle())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}

/*
 ~ Time Complexity  : O(E) * O(1) = O(E)
 ~ Space Complexity : O(V + V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
