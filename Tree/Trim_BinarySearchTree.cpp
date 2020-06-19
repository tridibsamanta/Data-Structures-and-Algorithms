/**
 * Title     : Trim a Binary Search Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insertNode(Node *root, int data) {
    if (root == NULL)
        return new Node(data);
    if (data < root -> data)
        root -> left = insertNode(root -> left, data);
    else if (data > root -> data)
        root -> right = insertNode(root -> right, data);
    return root;
}

void inorderTraversal(Node *root) {
    if(root == NULL)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

Node* trimBST(Node *root, int low, int high) {

    if (!root)
        return NULL;

    // If data in root is greater than high,
    // we ignore the right subtree and move on with the left subtree
    if (root -> data > high)
        return trimBST(root -> left, low, high);

    // If data in root is lesser than low,
    // we ignore the left subtree and move on with the right subtree
    if (root -> data < low)
        return trimBST(root -> right, low, high);

    // If data in root lies in the range - [low, high],
    // explore both left and right subtrees
    root -> left = trimBST(root -> left, low, high);
    root -> right = trimBST(root -> right, low, high);

    return root;
}


int main() {

    Node *root = NULL;

    root = insertNode(root, 10); root = insertNode(root, 5);
    root = insertNode(root, 15); root = insertNode(root, 12);
    root = insertNode(root, 30);

    cout << "Tree is : ";
    inorderTraversal(root);
    cout << '\n';

    int low, high;
    cout << "Enter the lowest boundary : ";
    cin >> low;
    cout << "Enter the highest boundary : ";
    cin >> high;

    root = trimBST(root, low, high);

    cout << "Trimmed tree is : ";
    inorderTraversal(root);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/
