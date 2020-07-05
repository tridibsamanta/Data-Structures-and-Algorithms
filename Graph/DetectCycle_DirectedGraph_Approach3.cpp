/**
 * Title     : Detect Cycle in a Directed Graph (Using Vertex Colors)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

/*
    Color Code :
    WHITE   - Vertex is unvisited. Initially all vertices are marked as WHITE.
    GREY    - Vertex is currently processed (present in recursion stack).
    BLACK   - Vertex has been processed.
*/

enum color {WHITE, GREY, BLACK};

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    bool detectCycleUtil(int v, int vertexColor[]);
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

bool Graph :: detectCycleUtil(int v, int vertexColor[]) {

    vertexColor[v] = GREY;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (vertexColor[*i] == GREY)
            return true;
        if (vertexColor[*i] == WHITE && detectCycleUtil(*i, vertexColor))
            return true;
    }
    vertexColor[v] = BLACK;
    return false;
}

bool Graph :: detectCycle() {

    int *vertexColor = new int[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        vertexColor[i] = WHITE;

    for (int i = 0; i < totalVertices; ++i)
        if (vertexColor[i] == WHITE && detectCycleUtil(i, vertexColor))
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
