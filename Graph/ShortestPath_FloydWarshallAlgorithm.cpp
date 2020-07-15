/**
 * Title     : Find shortest path between all pair of vertices in a graph
               (Floyd-Warshall Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<pair<int, int> > *adj;
    void printPath(vector<vector<int> > parent, int src, int dest);
public:
    Graph(int v);
    void addEdge(int src, int dest, int weight);
    void findShortestPath();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<pair<int, int> >[totalVertices];
}

void Graph :: addEdge(int src, int dest, int weight) {
    adj[src].emplace_back(make_pair(dest, weight));
}

void Graph :: printPath(vector<vector<int> > parent, int src, int dest) {
    if (parent[src][dest] == INT_MAX)
        return;
    printPath(parent, src, parent[src][dest]);
    cout << dest << ' ';
}

void Graph :: findShortestPath() {

    vector<vector<int> > distance(totalVertices, vector<int> (totalVertices, INT_MAX));
    vector<vector<int> > parent(totalVertices, vector<int> (totalVertices, INT_MAX));

    for (int i = 0; i < totalVertices; ++i)
        distance[i][i] = 0;

    vector<pair<int, int> > :: iterator i;
    for (int v = 0; v < totalVertices; ++v) {
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            int adjVertex = (*i).first;
            int weight = (*i).second;
            distance[v][adjVertex] = weight;
            parent[v][adjVertex] = v;
        }
    }

    for (int k = 0; k < totalVertices; ++k) {

        for (int i = 0; i < totalVertices; ++i) {

            for (int j = 0; j < totalVertices; ++j) {

                if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                    continue;

                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    for (int i = 0; i < totalVertices; ++i) {
        for (int j = 0; j < totalVertices; ++j) {
            cout << "Distance of vertex " << j << " from vertex " << i << " is : " << distance[i][j] << '\n';
        }
    }

    cout << "Source Vertex \t\t Destination Vertex \t\t Shortest path\n";
    for (int i = 0; i < totalVertices; ++i) {
        for (int j = 0; j < totalVertices; ++j) {
            cout << i << "\t\t\t\t" << j << "\t\t\t\t" << i << ' ';
            printPath(parent, i, j);
            cout << '\n';
        }
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

    g.findShortestPath();

    return 0;
}

/*
 ~ Time Complexity  : O(V^3)
 ~ Space Complexity : O(V + E + E), (vertices + edges + weight of all edges)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
