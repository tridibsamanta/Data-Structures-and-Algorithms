/**
 * Title     : Vertical Order Traversal of a Binary Tree
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

void getMinMax(Node* root, int &minCol, int &maxCol, int currCol) {

    if (!root)
        return;

    if (currCol < minCol)
        minCol = currCol;
    else if (currCol > maxCol)
        maxCol = currCol;

    getMinMax(root -> left, minCol, maxCol, currCol - 1);
    getMinMax(root -> right, minCol, maxCol, currCol + 1);
}

void printCurrentVertical(Node *root, int targetCol, int currCol) {

    if (!root)
        return;

    if (currCol == targetCol)
        cout << root -> data << ' ';

    printCurrentVertical(root -> left, targetCol, currCol - 1);
    printCurrentVertical(root -> right, targetCol, currCol + 1);
}

void TraverseVerticalOrder(Node *root) {

    int minCol = 0, maxCol = 0;
    getMinMax(root, minCol, maxCol, 0);

    for (int col = minCol; col <= maxCol; ++col) {
        printCurrentVertical(root, col, 0);
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;

    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);
    root = InsertNode(root, 6);
    root = InsertNode(root, 7);

    cout << "Vertical Order Traversal : \n";
    TraverseVerticalOrder(root);
    cout << endl;

    return 0;
}

/*
 ~ Time Complexity   : O(n^2)
 ~ Space Complexity  : O(n)
*/
