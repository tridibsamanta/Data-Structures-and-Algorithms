/**
 * Title     : Topological Sorting
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &s);
public:
    Graph(int v);
    void addEdge(int src, int dest);
    void topologicalSort();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<int> [totalVertices];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph :: topologicalSortUtil(int v, bool visited[], stack<int> &s) {

    visited[v] = true;

    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, s);

    s.push(v);
}

void Graph :: topologicalSort() {

    stack<int> s;

    bool *visited = new bool[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    for (int i = 0; i < totalVertices; ++i)
        if (!visited[i])
            topologicalSortUtil(i, visited, s);

    delete[] visited;

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
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

    cout << "Topological Ordering : ";
    g.topologicalSort();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Auxiliary Space  : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/

