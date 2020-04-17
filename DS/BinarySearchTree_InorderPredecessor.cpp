#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

//Function to search the target node in BST - O(h)
Node* SearchNode(Node* root, int data) {
    if(root == NULL) return NULL;
    else if(data == root->data) return root;
    else if(data < root->data) return SearchNode(root->left, data);
    else return SearchNode(root->right, data);
}

//Function to find Inorder Predecessor in a BST
Node* GetPredecessor(Node* root, int data) {
    //Check whether the target node is present in BST and assign its address to current
    Node* current = SearchNode(root, data);
    //If node is not found
    if (current == NULL)
        return NULL;
    //If node has a left subtree. We will find the max. element of the left subtree
    if (current->left != NULL) {
        Node* temp = current->left;
        while(temp->right != NULL)
            temp = temp->right;
        return temp;
    }
    //If node does not have a left subtree, go to the nearest ancestor,
    //for which the target node is in the right subtree
    else {
        Node* predecessor = NULL;
        Node* ancestor = root;
        while(ancestor != current) {
            if(current->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return predecessor;
    }
}

//Function for inorder traversal of BST
void Inorder(Node* root) {
    if(root == NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

//Function for inserting nodes into the BST
Node* Insert(Node* root, int data) {
    if(root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int main() {
    Node* root = NULL;

    root = Insert(root, 15); root = Insert(root, 10);
    root = Insert(root, 20); root = Insert(root, 8);
    root = Insert(root, 12); root = Insert(root, 17);
    root = Insert(root, 25); root = Insert(root, 6);
    root = Insert(root, 11); root = Insert(root, 16);
    root = Insert(root, 27);

    /* Sample tree to test the code -

                 15
               /    \
             10     20
            /  \   /  \
           8   12 17  25
          /   /   /     \
         6   11  16     27
    */

    cout<<"Inorder traversal of tree is - ";
    Inorder(root);
    cout<<"\n";

    int target;
    cout << "Enter a node = ";
    cin >> target;

    Node* predecessor = GetPredecessor(root, target);
    if(predecessor == NULL)
        cout << "Node " << target << " has no predecessor !\n";
    else
        cout << "Predecessor of node " << target << " is node " << predecessor->data << "\n";
}
