/**
 * Title     : Starting node in a linked list cycle (loop)
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
Node* getStartingNode(Node *head) {

    unordered_set <Node*> nodes;
    Node *temp = head;

    while (temp != NULL) {
        if (nodes.find(temp) != nodes.end())
            return temp;
        else {
            nodes.insert(temp);
            temp = temp -> next;
        }
    }

    return NULL;
}
*/

// ***** Approach 2 (Floyd's Cycle Detection Algorithm / Hare and Tortoise Technique) *****

Node* getStartingNode(Node *head) {

    if (!head || !head -> next)
        return NULL;

    Node *slowPtr = head, *fastPtr = head;

    while (fastPtr && fastPtr -> next) {

        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;

        if (slowPtr == fastPtr)
            break;
    }

    if (slowPtr != fastPtr)
        return NULL;

    slowPtr = head;

    while (slowPtr != fastPtr) {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next;
    }

    return slowPtr;
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    head -> next -> next -> next -> next -> next = head -> next; // Creates a loop

    Node *startNode = getStartingNode(head);

    if (!startNode)
        cout << "Linked list does not contain a cycle." << '\n';
    else
        cout << "Cycle starts with node having value " << startNode -> data << '\n';

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
