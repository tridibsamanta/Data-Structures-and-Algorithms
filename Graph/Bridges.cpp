/**
 * Title     : Find Bridges in a graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void findBridgesUtil(int v, bool visited[], int discoveryTime[], int lowTime[], int parent[], vector<pair<int, int> > &bridges);

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void findBridges();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

void Graph::findBridgesUtil(int v, bool visited[], int discoveryTime[], int lowTime[], int parent[], vector<pair<int, int> > &bridges) {

    static int time = 0;

    visited[v] = true;
    discoveryTime[v] = time;
    lowTime[v] = time;
    ++time;

    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {

        int adjV = *i;

        if (!visited[adjV]) {

            parent[adjV] = v;

            findBridgesUtil(adjV, visited, discoveryTime, lowTime, parent, bridges);

            lowTime[v] = min(lowTime[v], lowTime[adjV]);

            if (lowTime[adjV] > discoveryTime[v])
                //cout << v << ' ' << adjV << '\n';
                bridges.emplace_back(make_pair(v, adjV));
        }
        else if (adjV != parent[v])
            lowTime[v] = min(lowTime[v], discoveryTime[adjV]);
    }
}

void Graph::findBridges() {

    bool visited[totalVertices];
    int discoveryTime[totalVertices], lowTime[totalVertices], parent[totalVertices];
    vector<pair<int, int> > bridges;

    for (int i = 0; i < totalVertices; ++i) {
        visited[i] = false;
        discoveryTime[i] = -1;
        lowTime[i] = -1;
        parent[i] = -1;
    }

    for (int v = 0; v < totalVertices; ++v) {
        if (!visited[v])
            findBridgesUtil(v, visited, discoveryTime, lowTime, parent, bridges);
    }

    sort(bridges.begin(), bridges.end());
    cout << "Bridges : \n";
    vector<pair<int, int> > :: iterator i;
    for (i = bridges.begin(); i != bridges.end(); ++i)
        cout << (*i).first << ' ' << (*i).second << '\n';
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

    g.findBridges();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
