/**
 * Title     : Strongly Connected Components (Kosaraju's Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void dfsUtil(int v, bool visited[], stack<int> &s);
    void dfsTransposeUtil(int v, bool visited[]);
public:
    Graph(int v);
    void addEdge(int src, int dest);
    void findSCC();
    Graph getTranspose();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<int> [totalVertices];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph :: dfsUtil(int v, bool visited[], stack<int> &s) {
    visited[v] = true;
    vector <int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfsUtil(*i, visited, s);
    s.push(v);
}

Graph Graph :: getTranspose() {
    Graph g(totalVertices);
    for (int v = 0; v < totalVertices; ++v) {
        vector <int> :: iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            g.adj[*i].emplace_back(v);
    }
    return g;
}

void Graph :: dfsTransposeUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << ' ';
    vector <int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfsTransposeUtil(*i, visited);
}

void Graph :: findSCC() {

    stack<int> s;

    bool *visited = new bool[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    for (int i = 0; i < totalVertices; ++i)
        if (!visited[i])
            dfsUtil(i, visited, s);

    Graph gT = getTranspose();

    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        if (!visited[curr]) {
            gT.dfsTransposeUtil(curr, visited);
            cout << '\n';
        }
    }
    delete[] visited;
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

    cout << "Strongly connected components in the graph : \n";
    g.findSCC();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Auxiliary Space  : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/

