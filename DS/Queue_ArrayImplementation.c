/* Circular Array Implementation of Queue */

#include<stdio.h>
#define MAX_SIZE 10

int A[MAX_SIZE];
int front = -1;
int rear = -1;

void Enqueue(int element) {
    if((rear+1) % MAX_SIZE == front) {
        printf("Queue is full ! Insertion cannot be performed\n");
        return;
    }
    else if(IsEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear+1) % MAX_SIZE;
    }
    A[rear] = element;
    printf("Element successfully inserted into the Queue\n");
}

void Dequeue() {
    if(IsEmpty()) {
        printf("Queue is empty ! Deletion cannot be performed\n");
        return;
    }
    else if(front == rear) {
        front = rear = -1;
        printf("Element successfully deleted from the Queue\n");
        return;
    }
    else {
        front = (front+1) % MAX_SIZE;
        printf("Element successfully deleted from the Queue\n");
        return;
    }
}

int IsEmpty() {
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

int Front() {
    if(front == -1) {
        printf("Queue is empty !\n");
        return -1;
    }
    return A[front];
}

void Print() {
    if(IsEmpty()) {
        printf("Queue is empty !\n");
        return;
    }
    printf("Queue is : ");
    int i,count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
    for(i = 0; i < count; i++) {
        int index = (front + i) % MAX_SIZE;
        printf("%d ",A[index]);
    }
    printf("\n");
}

int main() {
    Dequeue(); Print();
    Enqueue(15); Print();
    Enqueue(23); Print();
    Enqueue(31); Print();
    Enqueue(47); Print();
    Dequeue(); Print();
    Dequeue(); Print();
    Enqueue(53); Print();

    int front_element = Front();
    printf("Front element = %d\n",front_element);

    return 0;
}
