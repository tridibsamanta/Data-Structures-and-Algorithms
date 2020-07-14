/**
 * Title     : Detect negative weight cycle in a graph (Using Bellman-Ford Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<pair<int, int> > *adj;
public:
    Graph(int v);
    void addEdge(int src, int dest, int weight);
    bool checkNegativeWeightCycle();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<pair<int, int> >[totalVertices];
}

void Graph :: addEdge(int src, int dest, int weight) {
    adj[src].emplace_back(make_pair(dest, weight));
}

bool Graph :: checkNegativeWeightCycle() {

    vector<int> distance(totalVertices, INT_MAX);
    distance[0] = 0;

    for (int k = 0; k < totalVertices - 1; ++k) {

        for (int v = 0; v < totalVertices; ++v) {

            vector<pair<int, int> > :: iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i) {
                int adjVertex = (*i).first;
                int weight = (*i).second;
                if (distance[adjVertex] > distance[v] + weight) {
                    distance[adjVertex] = distance[v] + weight;
                }
            }
        }
    }

    // If further relaxation is possible then graph contains negative weight cycle
    for (int v = 0; v < totalVertices; ++v) {
            vector<pair<int, int> > :: iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i) {
                int adjVertex = (*i).first;
                int weight = (*i).second;
                if (distance[adjVertex] > distance[v] + weight)
                    return true;
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

    cout << "Enter " << E << " edges and their weights : ";
    int src, dest, weight;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    if (g.checkNegativeWeightCycle())
        cout << "Graph contains negative weight cycle\n";
    else
        cout << "Graph does not contain negative weight cycle\n";

    return 0;
}

/*
 ~ Time Complexity  : O(V*E)
 ~ Space Complexity : O(V + E + E), (vertices + edges + weight of all edges)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
