/**
 * Title     : Flatten a linked list
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *down;

    Node(int val) {
        data = val;
        next = down = NULL;
    }
};

void insertNode(Node** head, int data) {

    Node *newNode = new Node(data);

    if (!newNode) {
        cout << "Memory Error !" << '\n';
    }

    newNode -> down = *head;
    *head = newNode;
}

void printList(Node* head) {

    if (head == NULL) {
        cout << "Empty List !" << '\n';
        return;
    }

    Node *temp = head;

    while (temp != NULL) {
        cout << temp -> data << ' ';
        temp = temp -> down;
    }
}

struct compare {
    bool operator()(const Node* list1, const Node* list2) {
        return list1 -> data > list2 -> data;
    }
};

Node* flattenLinkedList(Node *head) {

    if (head == NULL || head -> next == NULL)
        return head;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    Node *temp = head;
    while (temp != NULL) {
        minHeap.push(temp);
        temp = temp -> next;
    }

    Node *dummy = new Node(0);
    temp = dummy;

    while (!minHeap.empty()) {

        Node *curr = minHeap.top();
        minHeap.pop();

        if (curr -> down != NULL)
            minHeap.push(curr -> down);

        temp -> down = curr;
        temp = temp -> down;
        temp -> next = NULL;
    }

    return dummy -> down;
}

int main() {

    /*      7  -  9  -  13
            |     |     |
            12    20    17
            |           |
            15          23

        Flattened list is : 7 - 9 - 12 - 13 - 15 - 17 - 20 - 23
    */

    Node *head = NULL;

    insertNode(&head, 15);
    insertNode(&head, 12);
    insertNode(&head, 7);

    insertNode(&(head -> next), 20);
    insertNode(&(head -> next), 9);

    insertNode(&(head -> next -> next), 23);
    insertNode(&(head -> next -> next), 17);
    insertNode(&(head -> next -> next), 13);

    head = flattenLinkedList(head);

    cout << "Flattened list is : ";
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(N * log k)
 ~ Auxiliary Space  : O(k)
   where,
        'k' is the number of nodes in the topmost horizontal list and
        'N' is the total number of nodes among all the lists.
*/
