/**
 * Title     : Implement Queue using Linked List
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node *front, *rear;
    int queueSize;

public:
    Queue();

    void enQueue(int x);
    void deQueue();
    void printQueue();

    int sizeOfQueue();
    int frontOfQueue();
    int rearOfQueue();
};

Queue :: Queue() {
        front = rear = NULL;
        queueSize = 0;
    }

void Queue :: enQueue(int x) {

        Node *temp = new Node(x);

        if (temp == NULL) {
            cout << "Memory Error !" << '\n';
            return;
        }

        cout << "Element with value " << temp -> data << " is inserted" << '\n';
        ++queueSize;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear -> next = temp;
        rear = rear -> next;
}

void Queue :: deQueue() {

    if (front == NULL) {
        cout << "Queue is already empty" << '\n';
        return;
    }

    Node *temp = front;
    front = front -> next;

    if (front == NULL)
        rear = NULL;

    --queueSize;
    cout << "Element with value " << temp -> data << " is deleted" << '\n';

    delete(temp);
}

void Queue :: printQueue() {

    if (front == NULL) {
        cout << "Queue is empty" << '\n';
        return;
    }

    Node *temp = front;

    while (temp != NULL) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout << '\n';
}

int Queue :: sizeOfQueue() {
    return queueSize;
}

int Queue :: frontOfQueue() {

    if (front == NULL) {
        cout << "Queue is empty" << '\n';
        return INT_MIN;
    }

    return front -> data;
}

int Queue :: rearOfQueue() {

    if (rear == NULL) {
        cout << "Queue is empty" << '\n';
        return INT_MIN;
    }

    return rear -> data;
}

int main() {

    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    q.printQueue();
    cout << "Size of queue is: " << q.sizeOfQueue() << '\n';
    cout << "Front element of queue is: " << q.frontOfQueue() << '\n';
    cout << "Rear element of queue is: " << q.rearOfQueue() << '\n';

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.printQueue();
    cout << "Size of Queue is : " << q.sizeOfQueue() << '\n';

    return 0;
}

/*
 *** Time Complexity ***
 ~ enQueue()        : O(1)
 ~ deQueue()        : O(1)
 ~ printQueue()     : O(n)
 ~ sizeOfQueue()    : O(1)
 ~ frontOfQueue()   : O(1)
 ~ rearOfQueue()    : O(1)

 Space Complexity - O(n)
*/
