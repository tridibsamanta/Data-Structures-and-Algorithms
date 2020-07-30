/**
 * Title     : Print Eulerian Path for undirected graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int src, int dest);
    void printEulerPath();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

void Graph::printEulerPath() {

    int oddDegreeVertex = 0, start = 0;
    for (int i = 0; i < totalVertices; ++i) {
        if (adj[i].size() & 1) {
            ++oddDegreeVertex;
            start = i;
        }
    }

    if (oddDegreeVertex > 2) {
        cout << "No Eulerian Path exists\n";
        return;
    }

    int currVertex = start;
    vector<int> eulerPath;
    stack<int> s;

    while(!s.empty() || adj[currVertex].size() != 0) {

        if (adj[currVertex].size() == 0) {
            eulerPath.emplace_back(currVertex);
            currVertex = s.top();
            s.pop();
        }
        else {
            s.push(currVertex);

            vector<int> :: iterator it;
            it = adj[currVertex].begin();
            int adjV = *it;
            adj[currVertex].erase(it);

            currVertex = adjV;

            for (it = adj[currVertex].begin(); it != adj[currVertex].end(); ++it) {
                if (*it == s.top()) {
                    adj[currVertex].erase(it);
                    break;
                }
            }
        }
    }

    cout << "Eulerian Path is : ";
    vector<int> :: iterator i;
    for (i = eulerPath.begin(); i != eulerPath.end(); ++i)
        cout << *i << ' ';
    cout << currVertex << '\n';
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

    g.printEulerPath();

    return 0;
}

/*
 ~ Time Complexity  : O(E)
 ~ Space Complexity : O(V + E)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
