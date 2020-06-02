/**
 * Title     : Lowest Common Ancestor (LCA) in a Binary Search Tree
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

// ~~~ Recursive Approach ~~~

Node* findLowestCommonAncestor(Node *root, int node1, int node2) {

    if (root == NULL)
        return NULL;

    if (root -> data > node1 && root -> data > node2)
        return findLowestCommonAncestor(root ->left, node1, node2);

    if (root -> data < node1 && root -> data < node2)
        return findLowestCommonAncestor(root ->right, node1, node2);

    return root;
}

// ~~~ Iterative Approach ~~~
/*
Node* findLowestCommonAncestor(Node* root, int node1, int node2) {

    while (root != NULL) {

        if (root -> data > node1 && root -> data > node2)
            root = root -> left;
        else if (root -> data < node1 && root -> data < node2)
            root = root -> right;
        else
            break;
    }
    return root;
}
*/

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

    int node1 = 4, node2 = 9;
    Node *lca = findLowestCommonAncestor(root, node1, node2);
    cout << "Lowest Common Ancestor of " << node1 << " and " << node2 << " is " << lca -> data << '\n';

    return 0;
}

/*
 ~ Recursive Approach ~
 ~ Time Complexity   : O(h)
 ~ Space Complexity  : O(h)

 ~ Iterative Approach ~
 ~ Time Complexity   : O(h)
 ~ Space Complexity  : O(1)

   where 'h' is the height of the BST.
*/
