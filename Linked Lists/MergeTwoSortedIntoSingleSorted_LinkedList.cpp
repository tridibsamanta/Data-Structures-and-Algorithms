/**
 * Title     : Merge two sorted linked lists into a single sorted linked list
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
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
        cout << "List is empty !" << '\n';
        return;
    }

    Node *temp = head;

    while (temp) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
}

// ***** Approach 1 (Recursive)*****
/*
Node* mergeSortedLists(Node *list1, Node *list2) {

    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *result = NULL;

    if (list1 -> data < list2 -> data) {
        result = list1;
        result -> next = mergeSortedLists(list1 -> next, list2);
    }
    else {
        result = list2;
        result -> next = mergeSortedLists(list1, list2 -> next);
    }

    return result;
}
*/

// ***** Approach 2 (Iterative) *****

Node* mergeSortedLists(Node *list1, Node *list2) {

    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node dummy(INT_MIN);
    Node *curr = &dummy;

    while (list1 != NULL && list2 != NULL) {

        if (list1 -> data < list2 -> data) {
            curr -> next = list1;
            list1 = list1 -> next;
        }
        else {
            curr -> next = list2;
            list2 = list2 -> next;
        }
        curr = curr -> next;
    }

    if (list1 != NULL)
        curr -> next = list1;
    else
        curr -> next =list2;

    return dummy.next;
}

int main() {

    Node *head1 = NULL;

    head1 = insertNode(head1, 9);
    head1 = insertNode(head1, 6);
    head1 = insertNode(head1, 5);
    head1 = insertNode(head1, 2);

    cout << "List 1 is: ";
    printList(head1);
    cout << '\n';

    Node *head2 = NULL;

    head2 = insertNode(head2, 8);
    head2 = insertNode(head2, 3);
    head2 = insertNode(head2, 1);

    cout << "List 2 is: ";
    printList(head2);
    cout << '\n';

    Node *result = mergeSortedLists(head1, head2);

    cout << "Merged list is: ";
    printList(result);
    cout << '\n';

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(m + n)
 ~ Space Complexity : O(m + n)

 ***** Approach 2 *****
 ~ Time Complexity  : O(m + n)
 ~ Space Complexity : O(1)
*/
