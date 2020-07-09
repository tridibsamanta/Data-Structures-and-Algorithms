/**
 * Title     : Find shortest paths from source to all vertices in an unweighted graph
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
    void findShortestPath(int source);
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<int>[totalVertices];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    // adj[dest].emplace_back(src);
}

void Graph :: findShortestPath(int source) {

    vector<int> parent(totalVertices, INT_MIN);
    vector<int> distance(totalVertices, -1);
    distance[source] = 0;

    queue<int> q;
    q.push(source);

    vector<int> :: iterator i;
    while(!q.empty()) {

        int currVertex = q.front();
        q.pop();

        for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i) {
            if (distance[*i] == -1) {
                distance[*i] = distance[currVertex] + 1;
                parent[*i] = currVertex;
                q.push(*i);
            }
        }
    }
    for (int i = 0; i < totalVertices; ++i)
        cout << "Distance of vertex " << i << " from source vertex is : " << distance[i] << '\n';

    for (int i = 0; i < totalVertices; ++i) {

        cout << "Shortest path from source vertex to vertex " << i << " is : ";

        stack<int> path;

        int d = parent[i];
        while(d != INT_MIN) {
            path.push(d);
            d = parent[d];
        }

        while (!path.empty()) {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << i << '\n';
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

    int source;
    cout << "Enter the source vertex : ";
    cin >> source;

    g.findShortestPath(source);

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Auxiliary Space  : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
