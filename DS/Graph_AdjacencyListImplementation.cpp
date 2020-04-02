#include<iostream>
#include<cstdlib>
using namespace std;

// Represents an adjacency list node
// Contains two part - data part & pointer to next node

struct AdjListNode {
    int data;
    AdjListNode* next;
};

//Represents a single adjacency list headed by the pointer head

struct AdjList {
    AdjListNode *head;
};

// Represents a collection (array) of adjacency lists
// Size of the array pointer will be equal to the number of vertices (nodes) in the graph

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
    Graph* graph = new Graph(); // Our graph is created
    graph->vertices = vertices; // Define the no. of nodes in our graph
    graph->arr = new AdjList[vertices]; // Create adj. list head pointer array, equal to the no. of nodes in the graph
    for(int i = 0; i < vertices; i++)
        graph->arr[i].head = NULL; // Assign the address of all the adj. list head nodes to NULL
    return graph;
}


/*
	Let's review the concept of adding an edge to a graph -

	An edge is the link between two vertices (nodes) in a graph.
	To add an edge to a graph we need to know both the nodes. Lets call then source node & the  destination node.
	And also the graph address, where we will be adding that particular edge.

	So do we need to create two nodes while adding an edge to the graph ?

	NO. As because we have already created a list (array), equal to the number of nodes in the graph,
	which contains the head pointers of all the nodes in the graph. This list will serve us the source node list.
	We just need to create the destination node and add this node to the existing source node list.
	That's all ! :D
*/

// Function to add an edge to an undirected graph

void addEdge(Graph* graph, int source, int destination) {
    AdjListNode* tempNode = newAdjListNode(destination); // Create the destinaton node
    // We're adding the node at the begining of the list.
    tempNode->next = graph->arr[source].head; // Link the 'next' address of destination node to the current 'head' address of the source node
    graph->arr[source].head = tempNode; // Change the current 'head' address of source node to the address of the destination node

    // As our graph is undirected we also need to add an edge from destination node to source node ! (Same process as above)
    tempNode = newAdjListNode(source);
    tempNode->next = graph->arr[destination].head;
    graph->arr[destination].head = tempNode;
}

// Funtion to display the adjacency list contents of the graph

void printGraph(Graph* graph) {
    // For each node we will print all edges
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

/*
Space complexity = O(|E|+|V|)
If, |V| << |E| then, O(|E|)

Worst Case - There can be (V^2 - V) no of edges,
which is the maximum edges possible in a graph of 'V' vertices,
then Space Complexity = O(V^2)
*/
