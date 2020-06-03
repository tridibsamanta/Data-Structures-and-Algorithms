/**
 * Title     : Vertical sum in a Binary Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data <= root -> data)
        root -> left = insertNode(root -> left, data);
    else
        root -> right = insertNode(root -> right, data);
    return root;
}

void inorderTraversal(Node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

void getVerticalSum(Node *root, int column, map<int, int> &hm) {

    if (root == NULL)
        return;

    getVerticalSum(root -> left, column - 1, hm);
    hm[column] += root -> data;
    getVerticalSum(root -> right, column + 1, hm);
}

void verticalSum(Node *root) {

    map<int, int> hm;

    int initialColumn = 0;
    getVerticalSum(root, initialColumn, hm);

    map<int, int> :: iterator it;
    for (it = hm.begin(); it != hm.end(); ++it)
        cout << it -> second << ' ';
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 11);
    root = insertNode(root, 4);

    /*
      Column : (We assume root column as 0)
               -2 -1   0    1
              |  |  |  10 |   |
              |  |  |/   \|   |
              |  | 7|     |15 |
              |  |/ |\   /|   |
              | 4|  | 9 11|   |

         Sum : 4   7   30   15
    */

    cout << "Tree : ";
    inorderTraversal(root);
    cout << '\n';

    cout << "Vertical sums : ";
    verticalSum(root);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
