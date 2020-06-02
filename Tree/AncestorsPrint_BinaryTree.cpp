/**
 * Title     : Print all ancestors of a node in a Binary Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = new Node(data);
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

bool printAllAncestors(Node* root, int target) {

    if (root == NULL)
        return false;

    if (root -> data == target)
        return true;

    if (printAllAncestors(root -> left, target) || printAllAncestors(root -> right, target)) {
        cout << root -> data << ' ';
        return true;
    }

    return false;
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

    int target = 11;
    cout << "Ancestors of " << target << " is : ";
    printAllAncestors(root, target);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(h), for recursive call stack.
   where 'n' is the number of nodes & 'h' is the height of the tree.
*/
