/**
 * Title     : Merge k sorted linked lists
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

struct compare {
    bool operator()(const Node* list1, const Node* list2) {
        return list1 -> data > list2 -> data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {

    if (lists.size() == 0)
        return NULL;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i])
            minHeap.push(lists[i]);
    }

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (!minHeap.empty()) {

        Node *top = minHeap.top();
        minHeap.pop();

        if (top -> next)
            minHeap.push(top -> next);

        tail -> next = top;
        tail = tail -> next;
    }

    return dummy -> next;
}

int main() {

    int k = 3;

    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    head1 = insertNode(head1, 5); head1 = insertNode(head1, 4); head1 = insertNode(head1, 1);
    head2 = insertNode(head2, 4); head2 = insertNode(head2, 3); head2 = insertNode(head2, 1);
    head3 = insertNode(head3, 6); head3 = insertNode(head3, 2);

    vector<Node*> lists(k);

    lists[0] = head1;
    lists[1] = head2;
    lists[2] = head3;

    Node *mergedListHead = mergeKLists(lists);

    cout << "Merged list is : ";
    printList(mergedListHead);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(nlogk)
 ~ Space Complexity : O(k)
*/
