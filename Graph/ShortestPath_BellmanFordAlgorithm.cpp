/**
 * Title     : Find shortest paths from source to all vertices in a graph
               (Bellman-Ford Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<pair<int, int> > *adj;
    void printPath(vector<int> parent, int v);
public:
    Graph(int v);
    void addEdge(int src, int dest, int weight);
    void findShortestPath(int source);
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<pair<int, int> >[totalVertices];
}

void Graph :: addEdge(int src, int dest, int weight) {
    adj[src].emplace_back(make_pair(dest, weight));
}

void Graph :: printPath(vector<int> parent, int v) {
    if (parent[v] == INT_MIN)
        return;
    printPath(parent, parent[v]);
    cout << v << ' ';
}

void Graph :: findShortestPath(int source) {

    vector<int> parent(totalVertices, INT_MIN);

    vector<int> distance(totalVertices, INT_MAX);
    distance[source] = 0;

    for (int k = 0; k < totalVertices - 1; ++k) {

        for (int v = 0; v < totalVertices; ++v) {

            vector<pair<int, int> > :: iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i) {
                int adjVertex = (*i).first;
                int weight = (*i).second;
                if (distance[adjVertex] > distance[v] + weight) {
                    distance[adjVertex] = distance[v] + weight;
                    parent[adjVertex] = v;
                }
            }
        }
    }

    for (int i = 0; i < totalVertices; ++i)
        cout << "Distance of vertex " << i << " from source vertex is : " << distance[i] << '\n';

    cout << "Vertex        Shortest path from source\n";
    for (int i = 0; i < totalVertices; ++i) {
        cout << i << "\t\t\t" << source << ' ';
        printPath(parent, i);
        cout << '\n';
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

    cout << "Enter " << E << " edges and their weights : ";
    int src, dest, weight;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    int source;
    cout << "Enter the source vertex : ";
    cin >> source;

    g.findShortestPath(source);

    return 0;
}

/*
 ~ Time Complexity  : O(V*E)
 ~ Space Complexity : O(V + E + E), (vertices + edges + weight of all edges)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
