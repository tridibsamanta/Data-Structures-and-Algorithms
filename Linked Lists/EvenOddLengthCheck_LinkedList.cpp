/**
 * Title     : Determine whether a linked list has even or odd number of nodes
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

Node* insertNode(Node *head, int data) {

    Node *newNode = new Node(data);

    if (!newNode) {
        cout << "Memory Error !" << '\n';
        return head;
    }

    newNode -> next = head;
    head = newNode;

    return head;
}

void printList(Node *head) {

    if (!head) {
        cout << "List is empty !" << '\n';
        return;
    }

    Node *temp = head;

    while (temp) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

// ***** Approach 1 *****
/*
bool checkEvenOdd(Node *head) {

    if (head == NULL)
        return true;

    int nodeCount = 0;

    Node *temp = head;

    while (temp != NULL) {
        ++nodeCount;
        temp = temp -> next;
    }

    return (nodeCount & 1) ? false : true;
}
*/

// ***** Approach 2 (Using tortoise-hare method) *****

bool checkEvenOdd(Node *head) {

    if (head == NULL)
        return true;

    Node *slowPtr = head, *fastPtr = head;

    while (fastPtr != NULL && fastPtr -> next != NULL) {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    return (fastPtr == NULL) ? true : false;
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    cout << "List is: ";
    printList(head);
    cout << '\n';

    bool isEven = checkEvenOdd(head);

    if (isEven)
        cout << "Linked list has even number of nodes" << '\n';
    else
        cout << "Linked list has odd number of nodes" << '\n';

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)

 ***** Approach 2 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
