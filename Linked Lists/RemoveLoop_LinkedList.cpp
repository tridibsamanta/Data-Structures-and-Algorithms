/**
 * Title     : Remove loop (cycle) in a Linked List
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

Node* insertNode(Node* head, int data) {

    Node *newNode = new Node(data);

    if (!newNode) {
        cout << "Memory Error !" << '\n';
        return head;
    }

    newNode -> next = head;
    head = newNode;

    return head;
}

void printList(Node* head) {

    if (head == NULL) {
        cout << "Empty List !" << '\n';
        return;
    }

    Node *temp = head;

    while (temp != NULL) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

// ***** Approach 1 (Hashing) *****
/*
void removeLoop(Node *head) {

    if (!head || !head -> next)
        return;

    Node *temp = head;

    unordered_set <Node*> nodes;
    nodes.insert(head);

    while (temp -> next != NULL) {
        if (nodes.find(temp -> next) != nodes.end())
            break;
        else {
            nodes.insert(temp -> next);
            temp = temp -> next;
        }
    }

    temp -> next = NULL;
}
*/

// ***** Approach 2 (Floyd's Cycle Detection Algorithm / Hare and Tortoise Technique) *****

void removeLoop(Node *head) {

    if (!head || !head -> next)
        return;

    Node *slowPtr = head, *fastPtr = head;

    slowPtr = slowPtr -> next;
    fastPtr = fastPtr -> next -> next;

    while (fastPtr && fastPtr -> next) {

        if (slowPtr == fastPtr)
            break;

        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    if (slowPtr == fastPtr) {

        slowPtr = head;

        if (fastPtr == head) {
            while (fastPtr -> next != slowPtr) {
                fastPtr = fastPtr -> next;
            }
        }
        else {
            while (slowPtr -> next != fastPtr -> next) {
                slowPtr = slowPtr -> next;
                fastPtr = fastPtr -> next;
            }
        }
        fastPtr -> next = NULL;
    }
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    head -> next -> next -> next -> next -> next = head -> next; // Creates a loop

    removeLoop(head);

    cout << "Linked list after loop removal : ";
    printList(head);

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(n)
 ~ Auxiliary Space  : O(n)

 ***** Approach 2 *****
 ~ Time Complexity  : O(n)
 ~ Auxiliary Space  : O(1)
*/
