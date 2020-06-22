/**
 * Title     : Remove all the half-nodes in a Binary Tree
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
    if (!root)
        return new Node(data);
    if (data < root -> data)
        root -> left = insertNode(root -> left, data);
    else if (data > root -> data)
        root -> right = insertNode(root -> right, data);
    return root;
}

void inorderTraversal(Node *root) {
    if (!root)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

Node *removeHalfNodes(Node *root) {

    if (!root)
        return NULL;

    root -> left = removeHalfNodes(root -> left);
    root -> right = removeHalfNodes(root ->right);

    if (root -> left == NULL && root -> right == NULL)
        return root;

    if (root -> left == NULL) {
        Node *temp = root -> right;
        delete root;
        return temp;
    }
    if (root -> right == NULL) {
        Node *temp = root -> left;
        delete root;
        return temp;
    }

    return root;
}

int main()
{
    Node *root = NULL;

    root = insertNode(root, 15); root = insertNode(root, 12); root = insertNode(root, 20);
    root = insertNode(root, 25); root = insertNode(root, 5);  root = insertNode(root, 10);

    cout << "Before removing the half nodes tree is : ";
    inorderTraversal(root);
    cout << endl;

    root = removeHalfNodes(root);

    cout << "After  removing the half nodes tree is : ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/
