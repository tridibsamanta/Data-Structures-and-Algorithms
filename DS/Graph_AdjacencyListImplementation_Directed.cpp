#include<iostream>
#include<cstdlib>
using namespace std;

struct AdjListNode {
    int data;
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

AdjListNode* newAdjListNode(int data) {
    AdjListNode* newNode = new AdjListNode();
    newNode->data = data;
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

void addEdge(Graph* graph, int source, int destination) {
    AdjListNode* tempNode = newAdjListNode(destination);
    tempNode->next = graph->arr[source].head;
    graph->arr[source].head = tempNode;
}

// Function to display the adjacency list contents of the graph

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->vertices; ++i) {
        AdjListNode* root = graph->arr[i].head;
        cout << "Edge from vertex "<< i << " :\n";
        while(root != NULL) {
            cout << "(" << i << " -> " << root->data << ") ";
            root = root->next;
        }
        cout << "\n";
    }
}


int main() {

    int totalVertices = 5;

    Graph* graph = createGraph(totalVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    cout << "Graph is - \n";
    printGraph(graph);

}
