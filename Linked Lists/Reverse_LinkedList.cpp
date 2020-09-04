/**
 * Title     : Reverse a Linked List
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
Node* reverseList(Node *head) {

    Node *prev = NULL, *next = NULL, *curr = head;

    while (curr) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
*/

// ***** Approach 2 (Recursive) *****

Node* reverseList(Node *head) {

    if (head == NULL || head -> next == NULL)
        return head;

    Node *temp = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return temp;
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

    cout << "Reversed list is : ";
    head = reverseList(head);
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
*/
