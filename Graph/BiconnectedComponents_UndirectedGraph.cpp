/**
 * Title     : Biconnected components in an undirected graph
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    void findBiconnectedComponentsUtil(int u, bool visited[], int discoveryTime[], int lowTime[], int parent[], stack<pair<int, int> >& s, int &time, int &bccCount);

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void findBiconnectedComponents();
};

Graph :: Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
}

void Graph :: findBiconnectedComponentsUtil(int u, bool visited[], int discoveryTime[], int lowTime[], int parent[], stack<pair<int, int> >& s, int &time, int &bccCount) {

    visited[u] = true;
    discoveryTime[u] = lowTime[u] = time++;

    int child = 0;

    vector<int> :: iterator itr;
    for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {

        int v = *itr;

        if (!visited[v]) {

            ++child;
            parent[v] = u;
            s.push(make_pair(u, v));

            findBiconnectedComponentsUtil(v, visited, discoveryTime, lowTime, parent, s, time, bccCount);

            lowTime[u] = min(lowTime[u], lowTime[v]);

            if ((parent[u] == -1 && child > 1) || (parent[u] != -1 && lowTime[v] >= discoveryTime[u])) {

                while (s.top() != make_pair(u, v)) {
                    cout << s.top().first << " - " << s.top().second << '\n';
                    s.pop();
                }
                cout << s.top().first << " - " << s.top().second << "\n----------\n";
                s.pop();
                ++bccCount;
            }

        }
        else if (v != parent[u] && (lowTime[u] > discoveryTime[v])) {
            lowTime[u] = discoveryTime[v];
            s.push(make_pair(u, v));
        }
    }
}

void Graph :: findBiconnectedComponents() {

    bool visited[totalVertices];
    int discoveryTime[totalVertices], lowTime[totalVertices], parent[totalVertices];

    memset(visited, false, sizeof(visited));
    memset(discoveryTime, -1, sizeof(discoveryTime));
    memset(lowTime, -1, sizeof(lowTime));
    memset(parent, -1, sizeof(parent));

    int time = 0, bccCount = 0;
    stack<pair<int, int> > s;

    cout << "Biconnected component edges are : \n";

    for (int v = 0; v < totalVertices; ++v) {
        if (!visited[v])
            findBiconnectedComponentsUtil(v, visited, discoveryTime, lowTime, parent, s, time, bccCount);

        if (!s.empty()) {
            ++bccCount;
            while (!s.empty()) {
                cout << s.top().first << " - " << s.top().second << '\n';
                s.pop();
            }
            cout << "----------\n";
        }
    }

    cout << "Number of biconnected component : " << bccCount << '\n';
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

    g.findBiconnectedComponents();

    return 0;
}

/*
 ~ Time Complexity  : O(V + E)
 ~ Space Complexity : O(V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
