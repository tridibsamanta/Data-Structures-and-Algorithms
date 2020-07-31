/**
 * Title     : Print Euler Cycle(Circuit) for directed eulerian graph (Hierholzer's Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<vector<int> > adj;
public:
    Graph(int V);
    void addEdge(int src, int dest);
    void printEulerCycle();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj.resize(V);
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph::printEulerCycle() {

    stack<int> currPath;
    vector<int> eulerCycle;

    currPath.push(0);

    while(!currPath.empty()) {

        int currV = currPath.top();

        if (adj[currV].size() > 0) {

            int adjV = adj[currV].back();
            adj[currV].pop_back();

            currPath.push(adjV);
        }
        else {
            eulerCycle.emplace_back(currV);
            currPath.pop();
        }
    }

    cout << "Euler Cycle is : ";
    for (int i = eulerCycle.size() - 1; i >= 0; --i)
        cout << eulerCycle[i] << ' ';
}

int main() {

    int vertices;
    cout << "Enter the total number of vertices : ";
    cin >> vertices;

    Graph g(vertices);

    int edges;
    cout << "Enter the total number of edges : ";
    cin >> edges;

    cout << "Enter " << edges << " edges : ";
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    g.printEulerCycle();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V + E)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
