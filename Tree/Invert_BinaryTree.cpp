/**
 * Title     : Mirror (Inverse) of a Binary Tree
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

// ~~~ Recursive ~~~

Node* invertTree(Node *root) {

    if (root) {

    invertTree(root -> left);
    invertTree(root -> right);

    Node *temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    }
    return root;
}

// ~~~ Iterative ~~~
/*
Node* invertTree(Node *root) {

    if (!root)
        return root;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {

        Node * temp = q.front();
        q.pop();

        swap(temp -> left, temp -> right);

        if (temp -> left)
            q.push(temp -> left);
        if (temp -> right)
            q.push(temp -> right);
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

    cout << "Before inversion : ";
    inorderTraversal(root);
    cout << '\n';

    root = invertTree(root);

    /*
             10
           /    \
          15     7
           \    / \
           11  9   4
    */

    cout << "After inversion : ";
    inorderTraversal(root);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
