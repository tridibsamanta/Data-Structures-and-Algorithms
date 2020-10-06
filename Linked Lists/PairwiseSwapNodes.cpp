/**
 * Title     : Pairwise swap nodes of a Linked List
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
        cout << "Empty List !" << '\n';
        return;
    }

    Node *temp = head;

    while (temp) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

// ***** Approach 1 (Pairwise swap node data) *****
/*
Node* pairwiseSwap(Node *head) {

    Node *temp = head;

    while (temp != NULL && temp -> next != NULL) {

        int val = temp -> data;
        temp -> data = temp -> next -> data;
        temp -> next -> data = val;

        temp = temp -> next -> next;
    }

    return head;
}
*/

// ***** Approach 2 (Recursively adjust links) *****

Node* pairwiseSwap(Node *head) {

    if (!head || !head -> next)
        return head;

    Node *newHead = head -> next;
    Node *temp = head -> next -> next;

    newHead -> next = head;
    head -> next = pairwiseSwap(temp);

    return newHead;
}


// ***** Approach 3 (Iteratively adjust links) *****
/*
Node* pairwiseSwap(Node *head) {

    if (!head || !head -> next)
        return head;

    Node dummy(-1);
    dummy.next = head;

    Node *prev = &dummy, *curr = head;

    while (curr && curr -> next) {

        prev -> next = curr -> next;
        prev = prev -> next;
        curr -> next = prev -> next;
        prev -> next = curr;
        prev = curr;
        curr = curr -> next;
    }

    return dummy.next;
}
*/

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

    head = pairwiseSwap(head);

    cout << "Modified list is : ";
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
 ~ Space Complexity : O(n)

 ***** Approach 3 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
