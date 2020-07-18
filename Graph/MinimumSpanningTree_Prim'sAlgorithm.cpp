/**
 * Title     : Find Minimum Spanning Tree (Using Prim's Algorithm)
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
    void findMST(int source);
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<pair<int, int> >[totalVertices];
}

void Graph :: addEdge(int src, int dest, int weight) {
    adj[src].emplace_back(make_pair(dest, weight));
    adj[dest].emplace_back(make_pair(src, weight));
}

void Graph :: findMST(int source) {

    vector<bool> visited(totalVertices, false);
    vector<int> parent(totalVertices, INT_MIN);

    vector<int> distance(totalVertices + 1, INT_MAX);
    distance[source] = 0;

    set<pair<int, int> > pq;
    pq.insert(make_pair(0, source));

    int mstCost = 0;

    while (!pq.empty()) {

        pair<int, int> temp = *(pq.begin());
        pq.erase(pq.begin());

        int currVertex = temp.second;

        visited[currVertex] = true;
        mstCost += distance[currVertex];

        for (int i = 0; i < adj[currVertex].size(); ++i) {

            int adjVertex = adj[currVertex][i].first;
            int weight = adj[currVertex][i].second;

            if (visited[adjVertex] == false && weight < distance[adjVertex]) {

                if (distance[adjVertex] != INT_MAX)
                    pq.erase(pq.find(make_pair(distance[adjVertex], adjVertex)));

                distance[adjVertex] = weight;
                pq.insert(make_pair(weight, adjVertex));
                parent[adjVertex] = currVertex;
            }
        }
    }

    cout << "MST Edges \t Cost\n";
    for (int v = 1; v < totalVertices; ++v)
        cout << parent[v] << " - " << v << "  \t\t  " << distance[v] << '\n';

    cout << "Sum of weights of edges of MST : " << mstCost;
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

    g.findMST(source);

    return 0;
}

/*
 ~ Time Complexity  : O(ElogV)
 ~ Space Complexity : O(V + E + E), (vertices + edges + weight of all edges)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
