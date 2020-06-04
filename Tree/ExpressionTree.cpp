/**
 * Title     : Expression Tree
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct ExpTreeNode {
    char data;
    ExpTreeNode *left, *right;

    ExpTreeNode(char value) {
        data = value;
        left = right = NULL;
    }
};

void inorderTraversal(ExpTreeNode *root) {
    if (!root)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << ' ';
    inorderTraversal(root -> right);
}

bool checkOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? true : false;
}

ExpTreeNode * buildExpTree(string postfix, int len) {

    stack<ExpTreeNode *> s;

    for (int i = 0; i < len; ++i) {

        if (!checkOperator(postfix[i])) {
            ExpTreeNode *opnd = new ExpTreeNode(postfix[i]);
            s.push(opnd);
        }
        else {
            ExpTreeNode *optr = new ExpTreeNode(postfix[i]);

            ExpTreeNode *opnd1 = s.top(); s.pop();
            ExpTreeNode *opnd2 = s.top(); s.pop();

            optr -> left = opnd2;
            optr -> right = opnd1;

            s.push(optr);
        }
    }

    ExpTreeNode *root = s.top();
    s.pop();

    return root;
}

int main() {

    ExpTreeNode *root = NULL;

    /*
        Postfix Expression - ABC*+D/
        Infix Expression - (A+B*C)/D

                /
              /   \
             +     D
            / \
           A   *
              / \
             B   C
    */

    string postfix = "ABC*+D/";
    int len = postfix.length();

    root = buildExpTree(postfix, len);

    printf("Inorder traversal (Infix expression) : ");
    inorderTraversal(root);
    cout << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
