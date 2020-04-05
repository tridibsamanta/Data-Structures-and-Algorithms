#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10 //Lets say maximum vertices in our graph is 10

//Create the queue structure
struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

//createQueue - Create space in memory for queue and initialize front & rear to -1 (empty queue)
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//isEmpty - Checks if queue is empty or not
int isEmpty(struct queue* q) {
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

//enqueue - Inserts element at rear end of the queue
void enqueue(struct queue* q, int element) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue is full !\n");
        return;
    }
    else if (isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = element;
}

//dequeue - Deletes element from front end of the queue
int dequeue(struct queue* q) {
    int element_deleted;
    if (isEmpty(q)) {
        printf("Queue is empty !\n");
        element_deleted = -1;
    }
    else if (q->front == q->rear) {
        element_deleted = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else {
        element_deleted = q->arr[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return element_deleted;
}

//frontElement - Returns the front element of the queue
int frontElement(struct queue* q) {
    if (q->front == -1)
        return -1;
    return q->arr[q->front];
}

//Structure of a single vertex (node)
struct AdjListNode {
    int data;
    struct AdjListNode* next;
};

//Adjacency list for a vertex (node)
struct AdjList {
    struct AdjListNode* head;
};

//Structure of the graph which contains collection of adjacency lists
struct Graph {
    int vertices;
    struct AdjList* arr;
    int* visited;
};

//newAdjListNode - Create a new node
struct AdjListNode* newAdjListNode(int data) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//createGraph - Create a graph of 'n' vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->arr = (struct AdjList*) malloc(vertices * sizeof(struct AdjList));
    graph->visited = (int*) malloc(vertices * sizeof(int));
    int i;
    for(i = 1; i <= vertices; i++) {
        graph->arr[i].head = NULL;
        graph->visited[i] = 0; //Initially all vertices are undiscovered, so set to 0
    }
    return graph;
}

//addEdge - Add the edges to the respective adjacency lists
void addEdge(struct Graph* graph, int source, int destination) {
    struct AdjListNode* tempNode = newAdjListNode(destination);
    tempNode->next = graph->arr[source].head;
    graph->arr[source].head = tempNode;
    //As the graph is undirected we also need to add an edge from destination node to source node
    tempNode = newAdjListNode(source);
    tempNode->next = graph->arr[destination].head;
    graph->arr[destination].head = tempNode;
}

//bfs - Breadth First Search (traversal) implementation

void bfs(struct Graph* graph, int startVertex) {

    struct queue* q = createQueue(); // Create the queue

    graph->visited[startVertex] = 1; // Set the value at index = starting vertex, in visited list to 1
    enqueue(q, startVertex); // Insert the starting vertex to our queue

    printf("Breadth First Search (traversal) starting from vertex %d is : \n", startVertex);

    //As long as queue is not empty continue the process
    while(!isEmpty(q)) {

        printf("%d ", frontElement(q)); // Print the front element and then delete it from queue

        int currentVertex = dequeue(q); // Vertex to be explored is stored in current vertex
        struct AdjListNode* temp = graph->arr[currentVertex].head;

        //All adjacent vertices of the current vertex to be added to the queue if unvisited
        while(temp != NULL) {

            int adjVertex = temp->data;

            //Add vertex to the queue only if unvisited
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }

            temp = temp->next;
        }
    }
}

int main() {

    /*
    int vertices, edges;
    printf("Enter the total number of vertices in the graph = ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the total number of edges in the graph = ");
    scanf("%d", &edges);

    int i, source, destination;
    for(i = 1; i <= edges; i++) {
        printf("Enter the source vertex and destination vertex of edge %d - \n", i);
        scanf("%d%d", &source, &destination);
        addEdge(graph, source, destination);
    }

    int startingVertex;
    printf("Enter the starting vertex = ");
    scanf("%d", &startingVertex);
    bfs(graph, startingVertex);
    */

    struct Graph* graph = createGraph(7);
    addEdge(graph, 1, 5);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 3);

    bfs(graph, 1);
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
