/**
 * Title     : Remove all the leaf nodes in a Binary Tree
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

Node *removeLeafNodes(Node *root) {
    if (!root)
        return NULL;
    if (root -> left == NULL && root -> right == NULL) {
        delete root;
        return NULL;
    }
    root -> left = removeLeafNodes(root -> left);
    root -> right = removeLeafNodes(root -> right);
    return root;
}

int main()
{
    Node *root = NULL;

    root = insertNode(root, 15); root = insertNode(root, 12); root = insertNode(root, 20);
    root = insertNode(root, 25); root = insertNode(root, 5);  root = insertNode(root, 10);

    cout << "Before removing leaf nodes tree is : ";
    inorderTraversal(root);
    cout << endl;

    root = removeLeafNodes(root);

    cout << "After  removing leaf nodes tree is : ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/
