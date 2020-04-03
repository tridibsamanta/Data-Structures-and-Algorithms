#include<stdio.h>
#include<stdlib.h>

struct AdjListNode {
    int data;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int vertices;
    struct AdjList* arr;
};

struct AdjListNode* newAdjListNode(int data) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->arr = (struct AdjList*) malloc(vertices * sizeof(struct AdjList));
    int i;
    for(i = 0; i < vertices; i++)
        graph->arr[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    struct AdjListNode* tempNode = newAdjListNode(destination);
    tempNode->next = graph->arr[source].head;
    graph->arr[source].head = tempNode;
    tempNode = newAdjListNode(source);
    tempNode->next = graph->arr[destination].head;
    graph->arr[destination].head = tempNode;
}

void printGraph(struct Graph* graph) {
    int i;
    for(i = 0; i < graph->vertices; i++) {
        struct AdjListNode* root = graph->arr[i].head;
        printf("Edge from vertex %d :\n",i);
        while(root != NULL) {
            printf("(%d -> %d)", i, root->data);
            root = root->next;
        }
        printf("\n");
    }
}

int main() {

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

    printf("Graph is - \n");
    printGraph(graph);
}
