/**
 * Title     : Prune Binary Search Tree elements outside a given range
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

Node *pruneBST(Node *root, int minRange, int maxRange) {

    if (!root)
        return NULL;

    root -> left = pruneBST(root -> left, minRange, maxRange);
    root -> right = pruneBST(root -> right, minRange, maxRange);

    if (root -> data < minRange) {
        Node *temp = root -> right;
        delete root;
        return temp;
    }

    if (root -> data > maxRange) {
        Node *temp = root -> left;
        delete root;
        return temp;
    }

    return root;
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 15); root = insertNode(root, 12); root = insertNode(root, 20);
    root = insertNode(root, 25); root = insertNode(root, 5);  root = insertNode(root, 10);

    cout << "Tree is : ";
    inorderTraversal(root);
    cout << '\n';

    int minRange, maxRange;
    cout << "Enter the minimum and maximum range : ";
    cin >> minRange >> maxRange;

    root = pruneBST(root, minRange, maxRange);

    cout << "Pruned tree is : ";
    inorderTraversal(root);
    cout << '\n';

    return 0;
}

/*
 *** Worst Case ***
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)

 *** Average Case ***
 ~ Time Complexity  : O(log n)
 ~ Space Complexity : O(log n)
*/
