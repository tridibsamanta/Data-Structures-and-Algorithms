/**
 * Title     : Find shortest paths from source to all vertices in a graph
               (Dijkstra's Algorithm)
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
    void findShortestPath(int source);
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<pair<int, int> >[totalVertices];
}

void Graph :: addEdge(int src, int dest, int weight) {
    adj[src].emplace_back(make_pair(dest, weight));
    adj[dest].emplace_back(make_pair(src, weight));
}

void Graph :: findShortestPath(int source) {

    vector<int> distance(totalVertices, INT_MAX);
    distance[source] = 0;

    set<pair<int, int> > s;
    s.insert(make_pair(0, source));

    while (!s.empty()) {

        pair<int, int> temp = *(s.begin());
        s.erase(s.begin());

        int currVertex = temp.second;

        vector<pair<int, int> > :: iterator i;
        for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i) {

            int adjVertex = (*i).first;
            int weight = (*i).second;

            if (distance[adjVertex] > distance[currVertex] + weight) {

                if (distance[adjVertex] != INT_MAX)
                    s.erase(s.find(make_pair(distance[adjVertex], adjVertex)));

                distance[adjVertex] = distance[currVertex] + weight;
                s.insert(make_pair(distance[adjVertex], adjVertex));
            }
        }
    }
    for (int i = 0; i < totalVertices; ++i)
        cout << "Distance of vertex " << i << " from source vertex is : " << distance[i] << '\n';
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
 ~ Time Complexity  : O(E log V)
 ~ Space Complexity : O(V + E + E), (vertices + edges + weight of all edges)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
