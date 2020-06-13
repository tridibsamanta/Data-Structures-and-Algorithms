/**
 * Title     : Determine if a binary tree is height balanced
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

int isBalancedUtil(Node *root) {
    if (!root)
        return 0;

    int lh = isBalancedUtil(root -> left);
    if (lh == -1)
        return -1;

    int rh = isBalancedUtil(root -> right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

bool isBalanced(Node *root) {
    return (isBalancedUtil(root) == -1 ? false : true);
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

int main()
{
    Node *root = NULL;

    /* Sample tree : (Not Height Balanced)
               1
              / \
             2   3
            /
           4
            \
             5
    */

    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> left -> right = new Node(5);

    cout << "Tree is : ";
    inorderTraversal(root);
    cout << endl;

    if (isBalanced(root))
        cout << "Tree is height balanced";
    else
        cout << "Tree is not height balanced";

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
