/**
 * Title     : Find the middle element of a linked list
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

// ***** Approach 1 *****
/*
int getMiddleElement(Node *head) {

    if (!head)
        return INT_MIN;

    vector<int> dummy;

    Node *temp = head;
    while(temp != NULL) {
        dummy.emplace_back(temp -> data);
        temp = temp -> next;
    }

    return dummy[dummy.size() / 2];
}
*/

// ***** Approach 2 (Efficient) *****

int getMiddleElement(Node *head) {

    if (!head)
        return INT_MIN;

    Node *slowPtr = head, *fastPtr = head;

    while (fastPtr != NULL && fastPtr -> next != NULL) {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    return slowPtr -> data;
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

    int middleElement = getMiddleElement(head);

    if (middleElement == INT_MIN)
        cout << "Middle element does not exist !" << '\n';
    else
        cout << "Middle element is : " << middleElement;

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)

 ***** Approach 2 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
