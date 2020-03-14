/* Linked List Implementation of Queue */

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

//Global variables to store address of front and rear nodes
struct Node * front = NULL;
struct Node * rear = NULL;

void Enqueue(int x) {
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next = NULL;
    printf("Inserting element : %d\n",x);
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue() {
    struct Node * temp = front;
    if(front == NULL) {
        printf("Queue is empty !\n");
        return;
    }
    printf("Deleting element : %d\n",Front());
    if(front == rear) {
        front = rear = NULL;
    }
    else {
    front = front->next;
    }
    //Anything in dynamic memory has to be explicitly freed
    free(temp);
}

int Front() {
    if(front == NULL) {
        printf("Queue is empty !\n");
        return;
    }
    return front->data;
}

void Print() {
    if(front == NULL) {
        printf("Queue is empty !\n");
        return;
    }
    printf("Queue is : ");
    struct Node * temp = front;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Dequeue(); Print();
    Enqueue(15); Print();
    Dequeue(); Print();
    Enqueue(23); Print();
    Enqueue(31); Print();
    Enqueue(47); Print();
    Dequeue(); Print();
    Enqueue(53); Print();
    return 0;
}
