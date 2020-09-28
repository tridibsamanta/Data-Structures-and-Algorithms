/**
 * Title     : Remove Nth node from end of a linked list
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

// ***** Approach 1 (Two-pass) *****
/*
Node* removeNthNodeFromEnd(Node *head, int n) {

    Node *temp = head;
    int length = 0;

    while (temp) {
        ++length;
        temp = temp -> next;
    }

    length -= n;

    Node *dummy = new Node(0);
    dummy -> next = head;
    temp = dummy;

    while (length--)
        temp = temp -> next;

    Node *target = temp -> next;
    temp -> next = target -> next;
    delete target;
    return dummy -> next;
}
*/

// ***** Approach 2 (One-pass using two pointers) *****

Node* removeNthNodeFromEnd(Node *head, int n) {

    Node *dummy = new Node(0);
    dummy -> next = head;

    Node *prev = dummy, *temp = head;

    while (n--)
        temp = temp -> next;

    while (temp) {
        prev = prev -> next;
        temp = temp -> next;
    }

    Node *target = prev -> next;
    prev -> next = target -> next;
    delete target;
    return dummy -> next;
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    int n = 2;

    cout << "List is : ";
    printList(head);
    cout << '\n';

    head = removeNthNodeFromEnd(head, n);

    cout << "List after removing " << n << " node from end is : ";
    printList(head);
    cout << '\n';

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
