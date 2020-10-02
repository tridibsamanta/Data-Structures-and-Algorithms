/**
 * Title     : Flatten a multilevel doubly linked list
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node *child;

    Node(int val) {
        data = val;
        next = prev = child = NULL;
    }
};

void printList(Node* head) {

    if (!head) {
        cout << "Empty List !" << '\n';
        return;
    }

    Node *temp = head;

    while (temp != NULL) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

Node* flattenList(Node *head) {

    Node *curr = head;

    while (curr != NULL) {

        if (curr -> child != NULL) {

            Node *next = curr -> next;
            Node *temp = curr -> child;

            curr -> next = temp;
            curr -> child = NULL;
            temp -> prev = curr;

            while (temp -> next != NULL)
                temp = temp -> next;

            temp -> next = next;

            if (next != NULL)
                next -> prev = temp;
        }
        curr = curr -> next;
    }
    return head;
}

int main() {

    /*      1 --- 2 --- 3 --- 4 --- 5
                  |
                  6 --- 7 --- 8
                        |
                        9 --- 10

        Flattened list is : 1 - 2 - 6 - 7 - 9 - 10 - 8 - 3 - 4 - 5
    */

    Node *head = NULL;

    head = new Node(1);
    head -> next = new Node(2);
    head -> next -> prev = head;
    head -> next -> next = new Node(3);
    head -> next -> next -> prev = head -> next;
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> prev = head -> next -> next;
    head -> next -> next -> next -> next = new Node(5);
    head -> next -> next -> next -> next -> prev = head -> next -> next -> next;

    head -> next -> child = new Node(6);
    head -> next -> child -> next = new Node(7);
    head -> next -> child -> next -> prev = head -> next -> child;
    head -> next -> child -> next -> next = new Node(8);
    head -> next -> child -> next -> next -> prev = head -> next -> child -> next;

    head -> next -> child -> next -> child = new Node(9);
    head -> next -> child -> next -> child -> next = new Node(10);
    head -> next -> child -> next -> child -> next -> prev = head -> next -> child -> next -> child;

    head = flattenList(head);

    cout << "Flattened list is : ";
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(N)
 ~ Auxiliary Space  : O(1)
   where,
        'N' is the total number of nodes among all the lists.
*/
