/**
 * Title     : Construct a Binary Tree from its Inorder & Postorder Traversals
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preorderTraversal(Node *root) {
    if (root == NULL)
        return;
    cout << root -> data << ' ';
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int searchNode(string inorder, int startIndex, int endIndex, char value) {
    for (int i = startIndex; i <= endIndex; ++i)
        if (inorder[i] == value)
            return i;
}

Node *buildBinaryTree(string inorder, string postorder, int startIndex, int endIndex) {

    static int postorderIndex = inorder.length() - 1;

    if (startIndex > endIndex)
        return NULL;

    Node *newNode = new Node(postorder[postorderIndex]);
    --postorderIndex;

    if (startIndex == endIndex)
        return newNode;

    int nodeIdx = searchNode(inorder, startIndex, endIndex, newNode -> data);

    newNode -> right = buildBinaryTree(inorder, postorder, nodeIdx + 1, endIndex);
    newNode -> left = buildBinaryTree(inorder, postorder, startIndex, nodeIdx - 1);

    return newNode;
}

int main() {

    string inorder;
    cout << "Enter the inorder traversal list : ";
    cin >> inorder;

    string postorder;
    cout << "Enter the postorder traversal list : ";
    cin >>postorder;

    int len = inorder.length();
    Node *root = buildBinaryTree(inorder, postorder, 0, len - 1);

    cout << "Preorder traversal of the constructed tree is : ";
    preorderTraversal(root);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(h)
 ~ Space Complexity  : O(h)
   where 'h' is the height of the tree.
*/
