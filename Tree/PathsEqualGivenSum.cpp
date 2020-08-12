/**
 * Title     : Print all paths in a binary tree where each path's sum equals the given sum
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

void printPathUtil(Node *root, int sum, int &pathCount, vector<int> path){
    if (!root)
        return;

    path.emplace_back(root -> data);

    printPathUtil(root -> left, sum, pathCount, path);
    printPathUtil(root -> right, sum, pathCount, path);

    int currPathSum = 0;
    for (int i = path.size() - 1; i >= 0; --i) {
        currPathSum += path[i];
        if (currPathSum == sum) {
            ++pathCount;
            for (int j = i; j < path.size(); ++j)
                cout << path[j] << ' ';
            cout << '\n';
        }
    }
}

void printPath(Node *root, int sum) {
    int pathCount = 0;
    vector<int> path;
    cout << "Paths having path sum " << sum << " are : \n";
    printPathUtil(root, sum, pathCount, path);
    cout << "Number of paths having path sum " << sum << " are = " << pathCount << '\n';
}

int main()
{
    Node *root = NULL;

    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);
    root = InsertNode(root, 3);
    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);

    TraverseLevelOrder(root);
    cout << endl;

    int pathSum = 6;
    printPath(root, pathSum);

    return 0;
}

/*
 ~ Time Complexity   : O(n^2)
 ~ Space Complexity  : O(n)
*/
