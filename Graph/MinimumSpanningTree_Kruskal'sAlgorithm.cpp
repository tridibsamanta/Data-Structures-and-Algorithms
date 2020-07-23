/**
 * Title     : Find Minimum Spanning Tree (Using Kruskal's Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices, totalEdges;
    vector<pair<int, pair<int, int> > > edges;
    void makeSet(int parent[], int rank[]);
    int findSet(int parent[], int v);
    void performUnion(int parent[], int rank[], int v1, int v2);
public:
    Graph(int v, int e);
    void addEdge(int src, int dest,int weight);
    void findMST();
};

Graph :: Graph(int v, int e) {
    totalVertices = v;
    totalEdges = e;
}

void Graph :: addEdge(int src, int dest, int weight) {
    edges.emplace_back(make_pair(weight, make_pair(src, dest)));
}

void Graph :: makeSet(int parent[], int rank[]) {
    for (int v = 0; v < totalVertices; ++v) {
        parent[v] = v;
        rank[v] = 0;
     }
}

int Graph :: findSet(int parent[], int v) {

    if (parent[v] != v)
        parent[v] = findSet(parent, parent[v]);

    return parent[v];
}

void Graph :: performUnion(int parent[], int rank[], int v1, int v2) {

    int v1Set = findSet(parent, v1);
    int v2Set = findSet(parent, v2);

    if (rank[v1Set] < rank[v2Set])
        parent[v1Set] = v2Set;
    else if (rank[v1Set] > rank[v2Set])
        parent[v2Set] = v1Set;
    else {
        parent[v2Set] = v1Set;
        ++rank[v1Set];
    }
}

void Graph :: findMST() {

     vector<pair<int, pair<int, int> > > result;

     sort(edges.begin(), edges.end());

     int parent[totalVertices], rank[totalVertices];
     makeSet(parent, rank);

     int mstCost = 0, mstEdges = totalVertices - 1;

     vector<pair<int, pair<int, int> > > :: iterator itr;
     for (itr = edges.begin(); itr != edges.end(); ++itr) {

        int v1 = itr->second.first;
        int v2 = itr->second.second;
        int weight = itr->first;

        int v1Set = findSet(parent, v1);
        int v2Set = findSet(parent, v2);

        if (v1Set != v2Set) {

            result.emplace_back(make_pair(weight, make_pair(v1, v2)));
            mstCost += weight;

            performUnion(parent, rank, v1, v2);

            if(--mstEdges == 0)
                break;
        }
     }

     cout << "MST Edges \t Weight\n";
     for (itr = result.begin(); itr != result.end(); ++itr)
        cout << itr->second.first << " - " << itr->second.second << "   \t   " << itr->first << '\n';

     cout << "Sum of weights of edges of MST : " << mstCost;
}

int main() {

    int vertices;
    cout << "Enter the total number of vertices : ";
    cin >> vertices;

    int edges;
    cout << "Enter the total number of edges : ";
    cin >> edges;

    Graph g(vertices, edges);

    cout << "Enter " << edges << " edges and their weights : ";
    int src, dest, weight;
    for (int i = 0; i < edges; ++i) {
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    g.findMST();

    return 0;
}

/*
 ~ Time Complexity  : O(ElogE + ElogV) = O(ElogE) or O(ElogV)
 ~ Auxiliary Space  : O(V + V)

   where,
   V -> Number of vertices and E -> Number of edges, in the graph.
*/
