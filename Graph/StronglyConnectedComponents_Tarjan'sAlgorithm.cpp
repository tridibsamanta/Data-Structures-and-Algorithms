/**
 * Title     : Strongly Connected Components (Tarjan's Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<vector<int> > adj;
    void dfsUtil(int u, int discoveryTime[], int lowTime[], bool inStack[], stack<int>& s, int &time);

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void findSCC();
};

Graph :: Graph(int V) {
    totalVertices = V;
    adj.resize(V);
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph :: dfsUtil(int u, int discoveryTime[], int lowTime[], bool inStack[], stack<int>& s, int &time) {

    discoveryTime[u] = lowTime[u] = time++;
    s.push(u);
    inStack[u] = true;

    vector<int> :: iterator itr;
    for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {

        int v = *itr;

        if (discoveryTime[v] == -1) {
            dfsUtil(v, discoveryTime, lowTime, inStack, s, time);
            lowTime[u] = min(lowTime[u], lowTime[v]);
        }
        else if (inStack[v] == true) {
            lowTime[u] = min(lowTime[u], discoveryTime[v]);
        }
    }

    if (lowTime[u] == discoveryTime[u]) {

        int curr;
        while (s.top() != u) {
            curr = s.top();
            cout << curr << ' ';
            s.pop();
            inStack[curr] = false;
        }
        curr = s.top();
        cout << curr << '\n';
        s.pop();
        inStack[curr] = false;
    }
}

void Graph :: findSCC() {

    int discoveryTime[totalVertices], lowTime[totalVertices];
    bool inStack[totalVertices];
    stack<int> s;
    int time = 0;

    memset(discoveryTime, -1, sizeof(discoveryTime));
    memset(lowTime, -1, sizeof(lowTime));
    memset(inStack, false, sizeof(inStack));

    for (int i = 0; i < totalVertices; ++i) {
        if (discoveryTime[i] == -1) {
            dfsUtil(i, discoveryTime, lowTime, inStack, s, time);
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

    cout << "Enter " << E << " edges : ";
    int src, dest;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Strongly connected components in the graph : \n";
    g.findSCC();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)
   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
