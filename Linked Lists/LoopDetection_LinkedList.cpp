/**
 * Title     : Detect loop (cycle) in a Linked List
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

// ***** Approach 1 (Hashing) *****
/*
bool detectCycle(Node *head) {

    unordered_set <Node*> nodes;
    Node *temp = head;

    while (temp != NULL) {
        if (nodes.find(temp) != nodes.end())
            return true;
        else {
            nodes.insert(temp);
            temp = temp -> next;
        }
    }

    return false;
}
*/

// ***** Approach 2 (Floyd's Cycle Detection Algorithm / Hare and Tortoise Technique) *****

bool detectCycle(Node *head) {

    Node *slowPtr = head, *fastPtr = head;

    while (slowPtr && fastPtr && fastPtr -> next) {

        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;

        if (slowPtr == fastPtr)
            return true;
    }

    return false;
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);

    head -> next -> next -> next -> next -> next = head -> next; // Creates a loop

    if (detectCycle(head))
        cout << "Linked list contains a loop" << '\n';
    else
        cout << "Linked list does not contain a loop" << '\n';

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
