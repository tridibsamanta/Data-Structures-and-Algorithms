/**
 * Title     : Lowest Common Ancestor (LCA) in a Binary Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
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

Node* findLowestCommonAncestor(Node *root, int node1, int node2) {

    if (root == NULL)
        return NULL;

    if (root -> data == node1 || root -> data == node2)
        return root;

    Node *left = findLowestCommonAncestor(root -> left, node1, node2);
    Node *right = findLowestCommonAncestor(root -> right, node1, node2);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;
    else
        return right;

}


int main() {

    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 4);
    root = insertNode(root, 11);

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

    int node1 = 9, node2 = 11;
    Node *lca = findLowestCommonAncestor(root, node1, node2);
    cout << "Lowest Common Ancestor of " << node1 << " and " << node2 << " is " << lca -> data << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
