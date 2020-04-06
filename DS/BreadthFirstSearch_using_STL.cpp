#include<iostream>
#include<list>

using namespace std;

class Graph {
    int vertex; // No. of vertices
    list<int> *adjList; // Pointer to an array containing adjacent lists

public:
    Graph(int V); // Constructor
    void addEdge(int source, int destination); // Add edges to the graph
    void bfs(int startingVertex); // Compute the BFS
};

// Initialization and creating the adjList for 'V' vertices
Graph::Graph(int V) {
    this->vertex = V;
    adjList = new list<int>[V];
}

// Adding the edge to source node's adj list
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

// Implement BFS
void Graph::bfs(int startingVertex) {

    bool *visited = new bool[vertex];
    for(int i = 0; i < vertex; i++)
        visited[i] = false;

    list<int> q;

    visited[startingVertex] = true;
    q.push_back(startingVertex);

    list<int>::iterator i;

    while(!q.empty()) {
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop_front();

        for (i = adjList[currentVertex].begin(); i != adjList[currentVertex].end(); i++) {
            if (visited[*i] == false) {
                visited[*i] == true;
                q.push_back(*i);
            }
        }
    }
}

int main() {
    Graph g(7);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(2, 7);

    cout << "Breadth First Traversal (BFS) of the graph starting from vertex 1 : " << endl;
    g.bfs(1);
}

/*
Example graph -

            1- - - - - 2- - - 7
           / \        / \
          /   \      /   \
         4     5    3     6

        BFS - 1 2 4 5 3 6 7

Time Complexity - O(V + E), where V is the number of vertex and E is the number of edges
*/
