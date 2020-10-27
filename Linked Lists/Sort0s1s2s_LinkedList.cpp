/**
 * Title     : Sort a linked list of 0s, 1s and 2s
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

    while (head != NULL) {
        cout << head -> data << ' ';
        head = head -> next;
    }
}

Node* sortList(Node *head) {

    if (!head || !head -> next)
        return head;

    int countZero = 0, countOne = 0, countTwo = 0;

    Node *curr = head;

    while (curr != NULL) {

        if (curr -> data == 0)
            ++countZero;
        else if (curr -> data == 1)
            ++countOne;
        else
            ++countTwo;

        curr = curr -> next;
    }

    curr = head;

    while (curr != NULL) {

        if (countZero != 0) {
            curr -> data = 0;
            --countZero;
        }
        else if (countOne != 0) {
            curr -> data = 1;
            --countOne;
        }
        else {
            curr -> data = 2;
        }

        curr = curr -> next;
    }

    return head;
}

int main() {

    Node *head = NULL;
    head = insertNode(head, 2);
    head = insertNode(head, 2);
    head = insertNode(head, 0);
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    head = insertNode(head, 0);
    head = insertNode(head, 2);

    cout << "List is : ";
    printList(head);
    cout << '\n';

    head = sortList(head);

    cout << "Sorted list is : ";
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
