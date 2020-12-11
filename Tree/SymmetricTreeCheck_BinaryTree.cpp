/**
 * Title     : Check whether a given binary tree is a mirror of itself (symmetric around its center).
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertNode(Node *root, int val) {

    if (!root) {
        root = new Node(val);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node *curr = q.front();
        q.pop();

        if (curr -> left != NULL)
            q.push(curr -> left);
        else {
            curr -> left = new Node(val);
            return root;
        }

        if (curr -> right != NULL)
            q.push(curr -> right);
        else {
            curr -> right = new Node(val);
            return root;
        }
    }
}

// ***** Approach 1 (Iterative) *****
/*
bool isSymmetric(Node *root) {

    if (!root)
        return true;

    queue<Node*> q;
    q.push(root -> left);
    q.push(root -> right);

    while (!q.empty()) {

        Node *curr1 = q.front();
        q.pop();
        Node *curr2 = q.front();
        q.pop();

        if (!curr1 && !curr2)
            continue;

        if (!curr1 || !curr2)
            return false;

        if (curr1 -> data != curr2 -> data)
            return false;

        q.push(curr1 -> left); q.push(curr2 -> right);
        q.push(curr1 -> right); q.push(curr2 -> left);
    }

    return true;
}
*/

// ***** Approach 2 (Recursive) *****

bool isSymmetricUtil(Node *root1, Node *root2) {

    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    if (root1 -> data == root2 -> data)
        return isSymmetricUtil(root1 -> left, root2 -> right) &&
                isSymmetricUtil(root1 -> right, root2 -> left);

    return false;
}

bool isSymmetric(Node *root) {

    if (!root)
        return true;

    return isSymmetricUtil(root -> left, root -> right);
}

void inorderTraversal(Node *root) {

    if (!root)
        return;

    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 4);
    root = insertNode(root, 3);

    cout << "Tree is: ";
    inorderTraversal(root);
    cout << '\n';

    if (isSymmetric(root))
        cout << "Symmetric tree";
    else
        cout << "Not a symmetric tree";

    return 0;
}

/*
 ***** Approach 1 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)

 ***** Approach 2 *****
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/
