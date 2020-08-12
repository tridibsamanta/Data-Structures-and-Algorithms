/**
 * Title     : Print all root-to-leaf paths where each path's sum equals the given sum
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data) {
    Node *newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* InsertNode(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp -> left != NULL)
            q.push(temp -> left);
        else {
            temp -> left = createNode(data);
            return root;
        }

        if (temp -> right != NULL)
            q.push(temp -> right);
        else {
            temp -> right = createNode(data);
            return root;
        }
    }
}

void TraverseLevelOrder(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty !\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    cout << "Tree is : ";
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp -> data << ' ';
        if (temp -> left != NULL)
            q.push(temp -> left);
        if (temp -> right != NULL)
            q.push(temp -> right);
    }
}

void printPathUtil(Node* root, int sum, vector<int> path) {
    if (!root)
        return;

    path.emplace_back(root -> data);
    sum -= root -> data;

    if (sum == 0 && !root -> left && !root -> right) {
        for (int i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
        cout << '\n';
    }

    printPathUtil(root -> left, sum, path);
    printPathUtil(root -> right, sum, path);
}

void printPath(Node* root, int sum) {
    vector<int> path;
    printPathUtil(root, sum, path);
}

int main()
{
    Node *root = NULL;

    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);

    TraverseLevelOrder(root);
    cout << endl;

    /*
            1
           / \
          2   3
         / \
        4   5

        Path sum    : 8
        Paths       : 1 2 5
    */

    int pathSum = 8;

    cout << "Root-to-leaf paths with path sum " << pathSum << " are : \n";
    printPath(root, pathSum);

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
