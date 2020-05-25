/**
 * Title     : Check for structurally identical Binary Trees
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

void InorderTraversal(Node *temp)
{
    if (temp == NULL)
        return;

    InorderTraversal(temp -> left);
    cout << temp -> data << ' ';
    InorderTraversal(temp -> right);
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL || r2 == NULL)
        return false;

    return ((r1 -> data == r2 -> data) && isIdentical(r1 -> left, r2 -> left) && isIdentical(r1 -> right, r2 -> right));
}

int main()
{
    Node *r1 = NULL;
    Node *r2 = NULL;

    r1 = InsertNode(r1, 1); r1 = InsertNode(r1, 2); r1 = InsertNode(r1, 3);
    r1 = InsertNode(r1, 4); r1 = InsertNode(r1, 5);

    r2 = InsertNode(r2, 1); r2 = InsertNode(r2, 2); r2 = InsertNode(r2, 3);
    r2 = InsertNode(r2, 4); r2 = InsertNode(r2, 5);

    cout << "Tree A : ";
    InorderTraversal(r1);
    cout << endl;

    cout << "Tree B : ";
    InorderTraversal(r2);
    cout << endl;

    if(isIdentical(r1, r2))
        cout << "Tree A and Tree B are identical\n";
    else
        cout << "Tree A and Tree B are not identical\n";

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
