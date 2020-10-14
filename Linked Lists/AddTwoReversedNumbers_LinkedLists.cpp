/**
 * Title     : Add two non-negative numbers represented by linked lists (Digits are stored in reverse order)
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

Node* addTwoNumbers(Node *head1, Node *head2) {

    if (!head1) return head2;
    if (!head2) return head1;

    Node dummy(-1);
    Node *curr1 = head1, *curr2 = head2, *res = &dummy;
    int carry = 0;

    while (curr1 != NULL || curr2 != NULL) {

        int sum = 0;

        if (curr1 != NULL) {
            sum = curr1 -> data;
            curr1 = curr1 -> next;
        }
        if (curr2 != NULL) {
            sum += curr2 -> data;
            curr2 = curr2 -> next;
        }
        sum += carry;

        res -> next = new Node(sum % 10);
        res = res -> next;

        carry = sum / 10;
    }

    if (carry)
        res -> next = new Node(1);

    return dummy.next;
}

int main() {

    // Number 1: 563
    Node *head1 = NULL;
    head1 = insertNode(head1, 5);
    head1 = insertNode(head1, 6);
    head1 = insertNode(head1, 3);

    // Number 2: 9842
    Node *head2 = NULL;
    head2 = insertNode(head2, 9);
    head2 = insertNode(head2, 8);
    head2 = insertNode(head2, 4);
    head2 = insertNode(head2, 2);

    cout << "List 1 is : ";
    printList(head1);
    cout << '\n';

    cout << "List 2 is : ";
    printList(head2);
    cout << '\n';

    Node *sumHead = addTwoNumbers(head1, head2);

    cout << "Result list is : ";
    printList(sumHead);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(max(m,n))
 ~ Space Complexity : O(1)
*/
