/**
 * Title     : Detect Cycle in a Directed Graph (Using Kahn's Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
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

bool Graph :: detectCycle() {

    vector<int> indegree(totalVertices, 0);

    for (int v = 0; v < totalVertices; ++v) {
        vector<int> :: iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            ++indegree[*i];
    }

    queue<int> q;
    for (int v = 0; v < totalVertices; ++v)
        if (indegree[v] == 0)
            q.push(v);

    // We can simply use a vertex counter variable, if we don't want the sorted list
    vector<int> sortedList;

    while (!q.empty()) {

        int currVertex = q.front();
        q.pop();
        sortedList.emplace_back(currVertex);

        vector<int> :: iterator i;
        for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i)
            if (--indegree[*i] == 0)
                q.push(*i);
    }

    if (sortedList.size() == totalVertices)
        return false;
    else
        return true;
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
