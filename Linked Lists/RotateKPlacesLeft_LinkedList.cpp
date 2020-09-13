/**
 * Title     : Rotate a linked list to the left (anti-clockwise) by k places
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

Node* rotateLeft(Node* head, int k) {

    if (head == NULL)
        return NULL;

    int nodeCount = 1;
    Node* curr = head;

    while (curr -> next != NULL) {
        ++nodeCount;
        curr = curr -> next;
    }

    k = k % nodeCount;

    if (k == 0)
        return head;

    curr -> next = head;

    while (k--) {
        curr = curr -> next;
    }

    head = curr -> next;
    curr -> next = NULL;

    return head;
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    cout << "List is : ";
    printList(head);
    cout << '\n';

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    cout << "Modified list is : ";
    head = rotateLeft(head, k);
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
