/**
 * Title     : Intersection node of two Linked Lists
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

// ***** Approach 1 (Two pointers) *****

Node* getIntersectionNode(Node *head1, Node *head2) {

    if (!head1 || !head2)
        return NULL;

    Node *temp1 = head1, *temp2 = head2;
    int len1 = 1, len2 = 1;

    while (temp1 -> next != NULL) {
        ++len1;
        temp1 = temp1 -> next;
    }

    while (temp2 -> next != NULL) {
        ++len2;
        temp2 = temp2 -> next;
    }

    if (temp1 != temp2)
        return NULL;

    if (len1 > len2) {
        temp1 = head1;
        temp2 = head2;
    }
    else {
        temp1 = head2;
        temp2 = head1;
    }

    int diff = abs(len1 - len2);

    while (diff--) {
        temp1 = temp1 -> next;
    }

    while (temp1 != temp2) {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    return temp1;
}


// ***** Approach 2 (Hashing) *****
/*
Node* getIntersectionNode(Node *head1, Node *head2) {

    if (!head1 || !head2)
        return NULL;

    unordered_set<Node*> nodeSet;

    Node *temp1 = head1;

    while(temp1 != NULL) {
        nodeSet.insert(temp1);
        temp1 = temp1 -> next;
    }

    temp1 = head2;

    while (temp1 != NULL) {
        if (nodeSet.find(temp1) != nodeSet.end())
            return temp1;
        temp1 = temp1 -> next;
    }

    return NULL;
}
*/

int main() {

    Node *head1 = NULL, *head2 = NULL;

    head1 = insertNode(head1, 4); head1 = insertNode(head1, 2);

    head2 = insertNode(head2, 3);
    head2->next = head1;

    head1 = insertNode(head1, 1); head1 = insertNode(head1, 9); head1 = insertNode(head1, 3);

    /*
            (3) ---> (9) ---> (1) -
                                    --> (2) ---> (4) ---> X
                              (3) -
    */

    cout << "List 1 is : ";
    printList(head1);
    cout << '\n';

    cout << "List 2 is : ";
    printList(head2);
    cout << '\n';

    Node *intersectionNode = getIntersectionNode(head1, head2);

    if (!intersectionNode)
        cout << "The two lists doesn't intersect !" << '\n';
    else
        cout << "Intersection node value is : " << intersectionNode -> data << '\n';

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(m + n)
 ~ Auxiliary Space  : O(1)

 ***** Approach 2 *****
 ~ Time Complexity  : O(m + n)
 ~ Auxiliary Space  : O(m) or O(n)
*/
