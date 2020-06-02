/**
 * Title     : Zigzag Traversal of a Binary Tree
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

void zigzagTraversal(Node *root) {

    if (!root)
        return;

    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    currentLevel.push(root);

    int current_Direction = 1; // 1 -> left to right , 0 -> right to left

    while(!currentLevel.empty()) {

        Node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp) {
            cout << temp -> data << ' ';

            if (current_Direction) {
                if (temp -> left)
                    nextLevel.push(temp -> left);
                if (temp -> right)
                    nextLevel.push(temp -> right);
            }
            else {
                if (temp -> right)
                    nextLevel.push(temp -> right);
                if (temp -> left)
                    nextLevel.push(temp -> left);
            }
        }
        if (currentLevel.empty()) {
            swap(currentLevel, nextLevel);
            current_Direction = 1 - current_Direction;
        }
    }
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

    cout << "Inorder traversal : ";
    inorderTraversal(root);
    cout << '\n';

    cout << "Zigzag traversal  : ";
    zigzagTraversal(root);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n) + O(n) = O(n)
*/
