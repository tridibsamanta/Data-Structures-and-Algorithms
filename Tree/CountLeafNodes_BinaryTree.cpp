/**
 * Title     : Count leaf nodes in a Binary Tree
 * Author    : Tridib Samanta
**/

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* CreateNode(int data)
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
        root = CreateNode(data);
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
            temp -> left = CreateNode(data);
            return root;
        }

        if (temp -> right != NULL)
            q.push(temp -> right);
        else {
            temp -> right = CreateNode(data);
            return root;
        }
    }
}

void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp -> left);
    cout << temp -> data << ' ';
    inorder(temp -> right);
}

// ~~~ Recursive approach ~~~

unsigned int leafNodeCount(Node *root) {
    if (root == NULL)
        return 0;
    // A leaf node has no children
    if (root -> left == NULL && root -> right == NULL)
        return 1;
    return leafNodeCount(root -> left) + leafNodeCount(root -> right);
}

// ~~~ Iterative approach ~~~
/*
unsigned int leafNodeCount(Node *root) {

    if (root == NULL)
        return 0;

    unsigned int leafCount = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp -> left != NULL)
            q.push(temp -> left);
        if (temp -> right != NULL)
            q.push(temp -> right);

        // A leaf node has no children
        if (temp -> left == NULL && temp -> right == NULL)
            ++leafCount;
    }

    return leafCount;
}
*/

int main()
{
    Node *root = NULL;

    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);

    /* Sample Tree:
            1
          /   \
         2     3
        / \
       4   5
       Number of leaf nodes = 3
    */

    cout << "Tree : ";
    inorder(root);
    cout << endl;

    unsigned int result = leafNodeCount(root);
    cout << "Number of leaf nodes = " << result << endl;

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/


