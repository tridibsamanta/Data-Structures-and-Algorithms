/**
 * Title     : Print Root to Leaf Paths of a Binary Tree
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

Node* createNode(int data)
{
    Node *newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* InsertNode(Node *root, int data)
{
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

void TraverseLevelOrder(Node *root)
{
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

void RootToLeaf(Node *root, vector<int> path, int pathLen) {

    if (root == NULL)
        return;

    path.push_back(root -> data);
    pathLen++;

    if (root -> left == NULL && root -> right == NULL) {
        cout << "[ ";
        for (int i = 0; i < pathLen ; ++i)
            cout << path[i] << ' ';
        cout << "]\n";
    }
    else {
        RootToLeaf(root -> left, path, pathLen);
        RootToLeaf(root -> right, path, pathLen);
    }
}

void PrintPaths(Node *root) {
    vector<int> path;
    RootToLeaf(root, path, 0);
}

int main()
{
    Node *root = NULL; //Empty tree

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

        Paths : [1 2 4], [1 2 5], [1 3]
    */

    cout << "Root to leaf paths are : \n";
    PrintPaths(root);

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
