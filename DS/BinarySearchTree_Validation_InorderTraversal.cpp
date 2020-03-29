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

bool IsBstUtil(Node* root, long long int &prev)
{
    if(root) {
        if(!IsBstUtil(root->left, prev))
            return false;
        //Check for current node is greater than or equal to previous node.
        //Use - root->data < prev if tree has duplicate nodes.
        if(root->data <= prev)
            return false;
        prev = root->data;
        return IsBstUtil(root->right, prev);
    }
    return true;
}

bool IsBinarySearchTree(Node* root){
    long long int prev = LLONG_MIN;
    return IsBstUtil(root, prev);
}

int main() {
    Node* root = NULL;
    root = Insert(root, 7);
    root = Insert(root, 4);
    root = Insert(root, 9);
    root = Insert(root, 3);
    root = Insert(root, 6);
    root = Insert(root, 8);
    root = Insert(root, 10);
    if(IsBinarySearchTree(root) == true)
        printf("Tree is a Binary Search Tree\n");
    else
        printf("Tree is not a Binary Search Tree\n");
}

