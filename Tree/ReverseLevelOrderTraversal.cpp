/**
 * Title     : Bottom-up Level Order Traversal of a Binary Tree
 * Author    : Tridib Samanta
**/

#include<iostream>
#include<queue>
#include<stack>
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
    cout << "Level order traversal : ";
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

void ReverseLevelOrder(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty !\n";
        return;
    }
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    Node *temp = NULL;

    while (!q.empty()) {

        temp = q.front();
        q.pop();
        s.push(temp);

        // Visit right subtree first, before left subtree
        if (temp -> right != NULL)
            q.push(temp -> right);

        if (temp -> left != NULL)
            q.push(temp -> left);
    }

    cout << "Reverse level order traversal : ";
    while (!s.empty()) {
        temp = s.top();
        s.pop();
        cout << temp -> data << ' ';
    }
}

int main()
{
    Node *root = NULL; //Empty tree

    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);
    root = InsertNode(root, 6);
    root = InsertNode(root, 7);

    TraverseLevelOrder(root);
    cout << endl;

    ReverseLevelOrder(root);
    cout << endl;

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
