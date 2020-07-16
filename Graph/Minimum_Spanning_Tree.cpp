/**
 * Title   : Minimum Spanning Tree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph) {

    vector<bool> visited(V+1, false);

    vector<int> val(V+1, INT_MAX);
    val[1] = 0;

    set<pair<int, int> > s;
    s.insert(make_pair(val[1], 1));

    int mstCost = 0;

    while (!s.empty()) {

        pair<int, int> temp = *(s.begin());
        s.erase(s.begin());

        int currVertex = temp.second;

        if (visited[currVertex] == true)
            continue;

        //mstCost += temp.first;
        mstCost += val[currVertex];
        visited[currVertex] = true;

        for (int i = 0; i < V; ++i) {

            if ((graph[currVertex-1][i] != 0) && (visited[i+1] == false) && (graph[currVertex-1][i] < val[i+1])) {

                    val[i+1] = graph[currVertex-1][i];
                    s.insert(make_pair(val[i+1], i+1));
            }
        }
    }

    return mstCost;
}
