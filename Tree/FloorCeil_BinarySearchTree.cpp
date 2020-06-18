/**
 * Title     : Floor and Ceil of a given key in BST
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

void floorCeilBSTUtil(Node *root, int key, int &floorVal, int &ceilVal) {

    while(root) {

        if (root -> data == key) {
            ceilVal = floorVal = root -> data;
            return;
        }

        if (key > root -> data) {
            floorVal = root -> data;
            root = root -> right;
        }
        else {
            ceilVal = root -> data;
            root = root -> left;
        }
    }
    return;
}

void floorCeilBST(Node *root, int key) {
    int floorVal = INT_MIN, ceilVal = INT_MIN;
    floorCeilBSTUtil(root, key, floorVal, ceilVal);
    if (floorVal == INT_MIN)
        cout << "Key is lesser than the min value in BST \n";
    else
        cout << "Floor : " << floorVal << '\n';
    if (ceilVal == INT_MIN)
        cout << "Key is greater than the max value in BST \n";
    else
        cout << "Ceil  : " << ceilVal << '\n';
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 10); root = insertNode(root, 5);
    root = insertNode(root, 15); root = insertNode(root, 12);
    root = insertNode(root, 30);

    cout << "Tree : ";
    inorderTraversal(root);
    cout << '\n';

    int key;
    cout << "Enter the value of key : ";
    cin >> key;

    floorCeilBST(root, key);

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
