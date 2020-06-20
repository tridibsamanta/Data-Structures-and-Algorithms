/**
 * Title     : Check if two BST's contain the same set of elements
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

void inorder(Node *root, vector<int> &v) {
    if(!root)
        return;
    inorder(root -> left, v);
    v.emplace_back(root -> data);
    inorder(root -> right, v);
}

bool performCheck(Node *root1, Node *root2) {

    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    vector<int> v1, v2;

    inorder(root1, v1);
    inorder(root2, v2);

    return (v1 == v2);
}

int main() {

    Node *root1 = NULL;

    root1 = insertNode(root1, 15); root1 = insertNode(root1, 10);
    root1 = insertNode(root1, 5);  root1 = insertNode(root1, 12);
    root1 = insertNode(root1, 20); root1 = insertNode(root1, 25);

    Node *root2 = NULL;

    root2 = insertNode(root2, 15); root2 = insertNode(root2, 12);
    root2 = insertNode(root2, 20); root2 = insertNode(root2, 5);
    root2 = insertNode(root2, 10); root2 = insertNode(root2, 25);

    if (performCheck(root1, root2))
        cout << "The BST's have same elements \n";
    else
        cout << "The BST's do not have same elements \n";

    return 0;
}

/*
 ~ Time Complexity  : O(max(m, n))
 ~ Space Complexity : O(max(m, n))
*/
