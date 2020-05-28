/**
 * Title     : Find the Level with Maximum Sum in a Binary Tree
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
    cout << "Tree : ";
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

int LevelWithMaxSum(Node * root) {

    if (!root)
        return 0;

    // Assuming root node is at level 0
    int currSum = 0, maxSum = INT_MIN, currLevel = 0, maxLevel = 0;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node *temp = q.front();
        q.pop();

        if (!temp) {

            if (currSum > maxSum) {
                maxSum = currSum;
                maxLevel = currLevel;
            }

            currSum = 0;
            ++currLevel;

            if (!q.empty())
                q.push(NULL);

        }
        else {

            currSum += temp -> data;

            if (temp -> left)
                q.push(temp -> left);
            if (temp -> right)
                q.push(temp -> right);
        }
    }
    return maxLevel; // Returns the level having maximum sum
    //return maxSum; // Returns the maximum sum
}

int main()
{
    Node *root = NULL;

    root = InsertNode(root, 10);
    root = InsertNode(root, 11);
    root = InsertNode(root, 7);
    root = InsertNode(root, 9);
    root = InsertNode(root, 15);
    root = InsertNode(root, 8);

    TraverseLevelOrder(root);
    cout << endl;

    int level = LevelWithMaxSum(root);
    cout << "Level having maximum sum : " << level << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
