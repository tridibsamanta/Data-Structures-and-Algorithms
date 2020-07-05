/**
 * Title     : Detect Cycle in a Directed Graph (Using DFS)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    bool detectCycleUtil(int v, bool visited[], bool recStack[]);
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

bool Graph :: detectCycleUtil(int v, bool visited[], bool recStack[]) {

    visited[v] = true;
    recStack[v] = true;

    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i] && detectCycleUtil(*i, visited, recStack))
            return true;
        else if (recStack[*i])
            return true;
    }
    recStack[v] = false;
    return false;
}

bool Graph :: detectCycle() {

    bool *visited = new bool[totalVertices];
    bool *recStack = new bool[totalVertices];
    for (int i = 0; i < totalVertices; ++i) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < totalVertices; ++i)
        if (!visited[i] && detectCycleUtil(i, visited, recStack))
            return true;

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
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
