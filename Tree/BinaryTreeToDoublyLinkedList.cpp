/**
 * Title     : Convert a Binary Tree to Doubly Linked List
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (temp -> left != NULL)
            q.push(temp -> left);
        else {
            temp -> left = new Node(data);
            return root;
        }
        if (temp -> right != NULL)
            q.push(temp -> right);
        else {
            temp -> right = new Node(data);
            return root;
        }
    }
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

void BTToDLL(Node *root, Node **head, Node **prev) {
    if (!root)
        return;
    // static Node *prev = NULL;
    BTToDLL(root -> left, head, prev);
    if (*prev == NULL)
        *head = root;
    else {
        root -> left = *prev;
        (*prev) -> right = root;
    }
    *prev = root;
    BTToDLL(root -> right, head, prev);
}

void printDLL(Node *head) {
    while (head) {
        cout << head -> data << ' ';
        head = head -> right;
    }
}

int main()
{
    Node *root = NULL; // Empty BT

    root = insertNode(root, 1); root = insertNode(root, 2); root = insertNode(root, 3);
    root = insertNode(root, 4); root = insertNode(root, 5); root = insertNode(root, 6);
    root = insertNode(root, 7);

    cout << "Binary Tree is        : ";
    inorderTraversal(root);
    cout << endl;

    Node *headDLL = NULL; // Empty DLL
    Node *prev = NULL;
    BTToDLL(root, &headDLL, &prev);
    cout << "Doubly Linked List is : ";
    printDLL(headDLL);

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
