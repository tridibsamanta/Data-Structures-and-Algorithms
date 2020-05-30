/**
 * Title     : Root to leaf path sum equal to a given sum
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

bool CheckPathSum(Node *root, int sum) {

    if (root == NULL)
        return (sum == 0) ? true : false;

    if (root -> data == sum && root -> right == NULL && root -> left == NULL)
        return true;

    return CheckPathSum(root -> left, sum - (root->data)) || CheckPathSum(root -> right, sum - (root -> data));

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

        Paths       : [1 2 4], [1 2 5], [1 3]
        Path Sum    : 7, 8 and 4 respectively
    */

    int pathSum = 8;

    if (CheckPathSum(root, pathSum))
        cout << "Path with sum " << pathSum << " exists\n";
    else
        cout << "Path with sum " << pathSum << " does not exist\n";

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
