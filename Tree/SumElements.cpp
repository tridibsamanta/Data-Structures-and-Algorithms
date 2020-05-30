/**
 * Title     : Sum of all elements in binary tree
 * Author    : Tridib Samanta
**/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* getNewNode(int value) {
    Node *newNode = new Node();
    newNode -> data = value;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
        return root;
    }
    if (data <= root -> data)
        root -> left = insertNode(root -> left, data);
    else
        root -> right = insertNode(root -> right, data);
    return root;
}

void inorderTraversal(Node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

int getNodesSum(Node *root) {

    if (root == NULL)
        return 0;

    return (root -> data + getNodesSum(root -> left) + getNodesSum(root -> right));
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 11);
    root = insertNode(root, 4);

    /*
            10
           /  \
          7    15
         / \   /
        4  9  11
    */

    cout << "Tree : ";
    inorderTraversal(root);
    cout << '\n';

    int sum = getNodesSum(root);
    cout << "Sum of all elements is : " << sum << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
