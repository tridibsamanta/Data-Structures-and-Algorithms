/**
 * Title     : Add two non-negative numbers represented by linked lists
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node *next;

    Node (int val) {
        data = val;
        next = NULL;
    }
};

Node* insertNode(Node *head, int data) {

    Node *newNode = new Node(data);

    if (!newNode) {
        cout << "Memory Error !\n";
        return head;
    }

    newNode -> next = head;
    head = newNode;

    return head;
}

void printList(Node *head) {

    if (!head) {
        cout << "Empty List !";
        return;
    }

    Node *temp = head;

    while (temp) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

int getListLength(Node *head) {

    int nodeCount = 0;

    while(head) {
        ++nodeCount;
        head = head -> next;
    }

    return nodeCount;
}

void addRemList(Node *head, Node *curr, int &carry, Node **result) {

    int sum = 0;

    if (head != curr) {

        addRemList(head -> next, curr, carry, result);

        sum = head -> data + carry;
        carry = sum / 10;

        *result = insertNode(*result, sum % 10);
    }
}

Node* addTwoListsUtil(Node *head1, Node *head2, int &carry) {

    if (!head1)
        return NULL;

    int sum;

    Node *result = new Node(0);
    result -> next = addTwoListsUtil(head1 -> next, head2 -> next, carry);

    sum = head1 -> data + head2 -> data + carry;
    carry = sum / 10;

    result -> data = sum % 10;

    return result;
}

Node* addTwoLists(Node *head1, Node *head2) {

    if (!head1)
        return head2;

    if (!head2)
        return head1;

    int len1 = getListLength(head1);
    int len2 = getListLength(head2);

    int diff = abs(len1 - len2);
    Node *curr1 = head1, *curr2 = head2;

    if (diff != 0) {
        if (len1 < len2) {
            curr1 = head2;
            curr2 = head1;
            head1 = curr1;
            head2 = curr2;
        }
        for(int i = 1; i <= diff; ++i)
            curr1 = curr1 -> next;
    }

    int carry = 0;

    Node *result = addTwoListsUtil(curr1, curr2, carry);

    if (diff > 0)
        addRemList(head1, curr1, carry, &result);

    if (carry)
        result = insertNode(result, carry);

    return result;
}

int main() {

    // Number 1: 563
    Node *head1 = NULL;
    head1 = insertNode(head1, 3);
    head1 = insertNode(head1, 6);
    head1 = insertNode(head1, 5);

    // Number 2: 9842
    Node *head2 = NULL;
    head2 = insertNode(head2, 2);
    head2 = insertNode(head2, 4);
    head2 = insertNode(head2, 8);
    head2 = insertNode(head2, 9);

    cout << "List 1 is : ";
    printList(head1);
    cout << '\n';

    cout << "List 2 is : ";
    printList(head2);
    cout << '\n';

    Node *sumHead = addTwoLists(head1, head2);

    cout << "Result list is : ";
    printList(sumHead);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(max(m,n))
 ~ Space Complexity : O(1)
*/
