/**
 * Title     : Minimum depth of Binary Tree
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

void inorderTraversal(Node *root)
{
    if (!root)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

// ~~~ Level-order Iterative Approach (Efficient) ~~~
int minDepth(Node *root) {

    if (root == NULL)
        return 0;

    int minD = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        ++minD;

        int q_size = q.size();
        for (int i = 0; i < q_size; ++i) {

        Node *currNode = q.front();
        q.pop();

        if (currNode -> left == NULL && currNode -> right == NULL)
            return minD;

        if (currNode -> left)
            q.push(currNode -> left);

        if (currNode -> right)
            q.push(currNode -> right);
        }
    }
}

// ~~~ Depth-wise Recursive Approach ~~~
/*
int minDepth(Node *root) {

    if (root == NULL)
        return 0;

    if (root -> left == NULL && root -> right == NULL)
        return 1;

    if (root -> left == NULL)
        return minDepth(root -> right) + 1;

    if (root -> right == NULL)
        return minDepth(root -> left) + 1;

    return min(minDepth(root -> left), minDepth(root -> right)) + 1;
}
*/

int main()
{
    Node *root = NULL;

    root = insertNode(root, 3); root = insertNode(root, 9); root = insertNode(root, 20);
    root = insertNode(root, 15); root = insertNode(root, 7);

    cout << "Tree is : ";
    inorderTraversal(root);
    cout << endl;

    int md = minDepth(root);
    cout << "Minimum depth is : " << md << '\n';

    return 0;
}

/*
 *** Iterative Approach ***
 ~ Time Complexity              : O(n)
 ~ Auxiliary Space Complexity   : O(n)
 *** Recursive Approach ***
 ~ Time Complexity              : O(n)
 ~ Auxiliary Space Complexity   : O(1)
*/
