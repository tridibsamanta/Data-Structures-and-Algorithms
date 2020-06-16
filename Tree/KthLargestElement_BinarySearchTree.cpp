/**
 * Title     : Kth largest element in a Binary Search Tree
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

Node* KthLargestElementUtil(Node *root, int &k) {

    if (root == NULL)
        return NULL;

    Node* right = KthLargestElementUtil(root -> right, k);

    if (right != NULL)
        return right;

    if (--k == 0)
        return root;

    return KthLargestElementUtil(root -> left, k);
}

int KthLargestElement(Node *root, int k) {

    Node *res = KthLargestElementUtil(root, k);

    if (res == NULL)
        return INT_MIN;
    else
        return res -> data;
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 5); root = insertNode(root, 3);
    root = insertNode(root, 6); root = insertNode(root, 2);
    root = insertNode(root, 4); root = insertNode(root, 1);

    cout << "Tree : ";
    inorderTraversal(root);
    cout << '\n';

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int res = KthLargestElement(root, k);

    if (res == INT_MIN)
        cout << "No. of nodes in BST is less than K !";
    else
        cout << "Kth Largest element is : " << res;

    return 0;
}

/*
 ~ Time Complexity              : O(n)
 ~ Auxiliary Space Complexity   : O(1)
*/
