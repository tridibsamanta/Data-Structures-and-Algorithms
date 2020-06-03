/**
 * Title   : Vertical sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/vertical-sum/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void verticalSum(Node *root);
int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        verticalSum(root);
        cout<<endl;
    }
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

void getVerticalSum(Node *root, int column, map<int, int> &hm) {

    if (!root)
        return;

    getVerticalSum(root -> left, column - 1, hm);
    hm[column] += root -> data;
    getVerticalSum(root -> right, column + 1, hm);
}

void verticalSum(Node *root) {

    map<int, int> hm;

    int column = 0;
    getVerticalSum(root, column, hm);

    map<int, int> :: iterator it;
    for (it = hm.begin(); it != hm.end(); ++it)
        cout << it -> second << ' ';
}
