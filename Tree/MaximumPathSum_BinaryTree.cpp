/**
 * Title     : Maximum Path Sum in a Binary Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = new Node(data);
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
            temp -> left = new Node(data);
            return root;
        }
        if (temp -> right != NULL)
            q.push(temp -> right);
        else {
            temp -> right = new Node(data);
            return root;
        }
    }
}

void inorderTraversal(Node *root) {
    if (!root)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

int maxPathSumUtil(Node *root, int &res) {

    if (!root)
        return 0;

    int left = maxPathSumUtil(root -> left, res);
    int right = maxPathSumUtil(root -> right, res);

    int max1 = max(root -> data, max(left, right) + root -> data);
    int max2 = max(max1, left + right + root -> data);

    res = max(res, max2);

    return max1;
}

int maxPathSum(Node *root) {

    int res = INT_MIN;
    maxPathSumUtil(root, res);

    return res;
}

int main()
{
    Node *root = NULL;

    root = insertNode(root, 10); root = insertNode(root, 8); root = insertNode(root, 2);
    root = insertNode(root, -3); root = insertNode(root, 5);

    cout << "Tree is : ";
    inorderTraversal(root);
    cout << endl;

    int maxSum = maxPathSum(root);
    cout << "Maximum Path Sum is : " << maxSum << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/
