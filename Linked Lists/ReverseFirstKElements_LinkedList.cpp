/**
 * Title     : Reverse first K elements of a Linked List
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

// ***** Approach 1 (Iterative) *****
/*
Node* reverseKElements(Node *head, int k) {

    Node *prev = NULL, *curr = head, *next = NULL;

    while (k--) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    head -> next = curr;
    return prev;
}
*/

// ***** Approach 2 (Recursive) *****

Node *successor = NULL;

Node* reverseKElements(Node *head, int k) {

    if (k == 1) {
        successor = head -> next;
        return head;
    }

    Node *last = reverseKElements(head -> next, k - 1);
    head -> next -> next = head;
    head -> next = successor;
    return last;
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
    cout << "Enter the value of k :";
    cin >> k;

    cout << "Reversed list is : ";
    head = reverseKElements(head, k);
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(k)
 ~ Space Complexity : O(1)

 ***** Approach 2 *****
 ~ Time Complexity  : O(k)
 ~ Space Complexity : O(k)
*/
