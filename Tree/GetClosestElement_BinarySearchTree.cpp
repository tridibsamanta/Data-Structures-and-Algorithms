/**
 * Title     : Find the closest element to a given key in a BST
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

// Approach 1 : (Using Level-order Traversal)
/*
Node *getClosestElement(Node *root, int key) {

    if (!root)
        return NULL;

    Node *element;
    int min_diff = INT_MAX;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node *temp = q.front();
        q.pop();

        if (abs(temp -> data - key) < min_diff) {
            min_diff = abs(temp -> data - key);
            element = temp;
        }

        if (temp -> left)
            q.push(temp -> left);
        if (temp -> right)
            q.push(temp -> right);

    }
    return element;
}
*/

// Approach 2 : (Exploiting BST properties)

void getClosestElementUtil(Node *root, int key, int &min_diff, Node* &element) {
    if (!root)
        return;
    if (root -> data == key) {
        min_diff = 0;
        element = root;
        return;
    }
    if (min_diff > abs(root -> data - key)) {
        min_diff = abs(root -> data - key);
        element = root;
    }
    if (key < root -> data)
        getClosestElementUtil(root -> left, key, min_diff, element);
    else
        getClosestElementUtil(root -> right, key, min_diff, element);
}

Node *getClosestElement(Node *root, int key) {
    int min_diff = INT_MAX;
    Node *element = NULL;
    getClosestElementUtil(root, key, min_diff, element);
    return element;
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 9);  root = insertNode(root, 4);  root = insertNode(root, 3);
    root = insertNode(root, 6);  root = insertNode(root, 5);  root = insertNode(root, 7);
    root = insertNode(root, 17); root = insertNode(root, 22); root = insertNode(root, 20);

    cout << "Tree is : ";
    inorderTraversal(root);
    cout << '\n';

    int key;
    cout << "Enter the key : ";
    cin >> key;

    Node *res = getClosestElement(root, key);
    cout << "Closest element to " << key << " in BST is : " << res -> data << '\n';

    return 0;
}

/*
 *** Approach 1 ***
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)

 *** Approach 2 ***
 ~ Time Complexity  : O(log n)
 ~ Space Complexity : O(log n)

 If the tree is skewed (Worst Case),
 T.C. & S.C. of Approach 2 will be the same as Approach 1.
*/
