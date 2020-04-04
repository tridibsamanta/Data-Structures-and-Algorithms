#include<iostream>
#include<cstdlib>
using namespace std;

struct AdjListNode {
    int data;
    int weight;
    AdjListNode* next;
};

struct AdjList {
    AdjListNode *head;
};

struct Graph{
    int vertices;
    AdjList *arr;
};

//Function to create a new adjacency list node

AdjListNode* newAdjListNode(int data, int weight) {
    AdjListNode* newNode = new AdjListNode();
    newNode->data = data;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of desired number of vertices

Graph* createGraph(int vertices) {
    Graph* graph = new Graph();
    graph->vertices = vertices;
    graph->arr = new AdjList[vertices];
    for(int i = 0; i < vertices; i++)
        graph->arr[i].head = NULL;
    return graph;
}

// Function to add an edge to a directed graph

void addEdge(Graph* graph, int source, int destination, int weight) {
    AdjListNode* tempNode = newAdjListNode(destination, weight);
    tempNode->next = graph->arr[source].head;
    graph->arr[source].head = tempNode;
}

// Function to display the adjacency list contents of the graph

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->vertices; ++i) {
        AdjListNode* root = graph->arr[i].head;
        cout << "Edge from vertex "<< i << " :\n";
        if(root == NULL)
            cout << "No edges exist from vertex " << i;
        else {
            while(root != NULL) {
                cout << "(" << i << " -> " << root->data << ") (W = " << root->weight << ") " ;
                root = root->next;
            }
        }
        cout << "\n";
        delete root;
    }
}

int main() {

    int totalVertices = 5;

    Graph* graph = createGraph(totalVertices);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 3, 4, 3);

    cout << "Graph is - \n";
    printGraph(graph);

}
