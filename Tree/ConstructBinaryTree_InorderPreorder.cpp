/**
 * Title     : Construct a Binary Tree from its Inorder & Preorder Traversals
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;
    Node *left;
    Node *right;
};

Node* getNewNode(char value) {
    Node *newNode = new Node();
    newNode -> data = value;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

void postorderTraversal(Node *root) {
    if (root == NULL)
        return;
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << ' ';
}

int searchNode(string inorder, int startIndex, int endIndex, char value) {
    for (int i = startIndex; i <= endIndex; ++i)
        if (inorder[i] == value)
            return i;
}

Node *buildBinaryTree(string inorder, string preorder, int startIndex, int endIndex) {

    static int preorderIndex = 0;

    if (startIndex > endIndex)
        return NULL;

    Node *newNode = getNewNode(preorder[preorderIndex]);
    ++preorderIndex;

    if (startIndex == endIndex)
        return newNode;

    int nodeIdx = searchNode(inorder, startIndex, endIndex, newNode -> data);

    newNode -> left = buildBinaryTree(inorder, preorder, startIndex, nodeIdx - 1);
    newNode -> right = buildBinaryTree(inorder, preorder, nodeIdx + 1, endIndex);

    return newNode;
}

int main() {

    string inorder;
    cout << "Enter the inorder traversal list : ";
    cin >> inorder;

    string preorder;
    cout << "Enter the preorder traversal list : ";
    cin >>preorder;

    int len = inorder.length();
    Node *root = buildBinaryTree(inorder, preorder, 0, len - 1);

    cout << "Postorder traversal of the constructed tree is : ";
    postorderTraversal(root);
    cout << '\n';

    return 0;

}

/*
 ~ Time Complexity   : O(h)
 ~ Space Complexity  : O(h)
   where 'h' is the height of the tree.
*/

