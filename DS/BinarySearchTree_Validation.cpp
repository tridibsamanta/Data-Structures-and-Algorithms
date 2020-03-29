#include<iostream>
#include<climits>
#include<cstdio>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert Node according to level order.
Node* Insert(Node* root, int data) {
    if(root == NULL) {
        root = GetNewNode(data);
        return root;
    }
    queue<Node* > Q;
    Q.push(root);
    while(!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();
        if(temp->left != NULL)
            Q.push(temp->left);
        else {
            temp->left = GetNewNode(data);
            return root;
        }
        if(temp->right != NULL)
            Q.push(temp->right);
        else {
            temp->right = GetNewNode(data);
            return root;
        }
    }
}

bool IsBstUtil(Node* root, int minValue, int maxValue) {
    if(root == NULL)
        return true;
    if(root->data > minValue && root->data <= maxValue
       && IsBstUtil(root->left, minValue, root->data)
       && IsBstUtil(root->right, root->data, maxValue))
            return true;
    else
        return false;
}

bool  IsBinarySearchTree(Node* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = NULL;
    root = Insert(root, 7);
    root = Insert(root, 4);
    root = Insert(root, 9);
    root = Insert(root, 4); //Inserting duplicate value
    root = Insert(root, 6);
    root = Insert(root, 9);
    root = Insert(root, 10);
    if(IsBinarySearchTree(root) == true)
        printf("Tree is a Binary Search Tree\n");
    else
        printf("Tree is not a Binary Search Tree\n");
}

