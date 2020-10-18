/**
 * Title     : Check if a linked list is palindrome
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

// ***** Approach 1 (Using Stack) *****
/*
bool checkPalindrome(Node *head) {

    if (!head || !head -> next)
        return true;

    stack<int> values;

    Node *curr = head;

    while (curr) {
        values.push(curr -> data);
        curr = curr -> next;
    }

    curr = head;

    while(curr) {

        if (curr -> data != values.top())
            return false;

        values.pop();
        curr = curr -> next;
    }

    return true;
}
*/

// ***** Approach 2 (Reverse half list) *****

void reverseList(Node **head) {

    if (!(*head) || !(*head) -> next)
        return;

    Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

bool isPalindromeUtil(Node *head1, Node *head2) {

    Node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 -> data != temp2 -> data) {
            return false;
        }
        else {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }

    return true;
}

bool isPalindrome(Node *head) {

    if (!head || !head -> next)
        return true;

    Node *slowPtr = head, *fastPtr = head, *prevSlowPtr = NULL;

    while (fastPtr != NULL && fastPtr -> next != NULL) {
        prevSlowPtr = slowPtr;
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    Node *midNode = NULL;

    if (fastPtr != NULL) {
        midNode = slowPtr;
        slowPtr = slowPtr -> next;
    }

    Node *head2 = slowPtr;
    prevSlowPtr -> next = NULL;

    reverseList(&head2);

    bool check = isPalindromeUtil(head, head2);

    reverseList(&head2);

    if (midNode != NULL) {
        prevSlowPtr -> next = midNode;
        midNode -> next = head2;
    }
    else {
        prevSlowPtr -> next = head2;
    }

    return check;
}

int main() {

    Node *head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 2);
    head = insertNode(head, 1);

    cout << "List is : ";
    printList(head);
    cout << '\n';

    if (isPalindrome(head))
        cout << "List is palindrome" << '\n';
    else
        cout << "List is not palindrome" << '\n';

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
