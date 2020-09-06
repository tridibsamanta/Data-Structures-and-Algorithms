/**
 * Title     : Reverse a linked list from position m to n
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
Node* reverseBetween(Node *head, int m, int n) {

    Node *prev = NULL, *curr = head, *next = NULL;

    while (m > 1) {
        prev = curr;
        curr = curr -> next;
        --m;
        --n;
    }

    Node *prev_start = prev, *start = curr;

    while (n--) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    if (prev_start != NULL)
        prev_start -> next = prev;
    else
        head = prev;

    start -> next = curr;

    return head;
}
*/

// ***** Approach 2 (Recursive) *****

Node *succ = NULL;

Node* reverseFirstKElements(Node *head, int k) {
    if (k == 1) {
        succ = head -> next;
        return head;
    }
    Node *last = reverseFirstKElements(head -> next, k - 1);
    head -> next -> next = head;
    head -> next = succ;
    return last;
}

Node* reverseBetween(Node *head, int m, int n) {
    if (m == 1) {
        return reverseFirstKElements(head, n);
    }
    head -> next = reverseBetween(head -> next, m - 1, n - 1);
    return head;
}

int main() {

    Node *head = NULL;

    head = insertNode(head, 6);
    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    cout << "List is : ";
    printList(head);
    cout << '\n';

    int m, n;
    cout << "Enter the value of m : ";
    cin >> m;
    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Modified list is : ";
    head = reverseBetween(head, m, n);
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(N)
 ~ Space Complexity : O(1)

 ***** Approach 2 *****
 ~ Time Complexity  : O(N)
 ~ Space Complexity : O(N)
*/
