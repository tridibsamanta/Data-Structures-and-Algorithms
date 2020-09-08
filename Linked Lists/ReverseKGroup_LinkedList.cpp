/**
 * Title     : Reverse a linked list in groups of given size
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

// ***** Approach 1 (Using Auxiliary Stack) *****
/*
Node* reverseKGroup(Node *head, int k) {

    stack <Node*> s;

    Node *curr = head, *prev = NULL;

    while (curr != NULL) {

        int nodeCount = 0;

        while (curr != NULL && nodeCount < k) {
            s.push(curr);
            curr = curr -> next;
            ++nodeCount;
        }

        while (!s.empty()) {

            if (prev == NULL) {
                prev = s.top();
                head = prev;
                s.pop();
            }
            else {
                prev -> next = s.top();
                prev = prev -> next;
                s.pop();
            }
        }
    }

    prev -> next = NULL;

    return head;
}
*/

// ***** Approach 2 (Using Recursion) *****

Node* reverseKGroup(Node *head, int k) {

    Node *prev = NULL, *curr = head, *next = NULL;
    int nodeCount = 0;

    while (curr != NULL && nodeCount < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        ++nodeCount;
    }

    if (next != NULL)
        head -> next = reverseKGroup(next, k);

    return prev;
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

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    cout << "Modified list is : ";
    head = reverseKGroup(head, k);
    printList(head);
    cout << '\n';

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(N)
 ~ Auxiliary Space  : O(k)

 ***** Approach 2 *****
 ~ Time Complexity  : O(N)
 ~ Auxiliary Space  : O(1)
*/
