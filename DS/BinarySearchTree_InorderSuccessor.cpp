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

//Function to find inorder successor in a BST
Node* GetSuccessor(Node* root, int data) {
    //Check whether the target node is present in BST and assign its address to current
    Node* current = SearchNode(root, data);
    //If node is not found
    if(current == NULL) return NULL;
    //If node has a right subtree. Go down to left-most node in right subtree - O(h)
    if(current->right != NULL) {
        Node* temp = current->right;
        while(temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    //If node does not have a right subtree.
    //Go to the nearest ancestor, for which the target node is in the left subtree - O(h)
    else {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current) {
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
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

    root = Insert(root,5); root = Insert(root,10);
    root = Insert(root,3); root = Insert(root,4);
    root = Insert(root,1); root = Insert(root,11);

    /* Sample tree to test the code -

                5
			   / \
			  3   10
			 / \   \
			1   4   11
    */

    cout<<"Inorder traversal of tree is = ";
    Inorder(root);
    cout<<"\n";

    Node* successor = GetSuccessor(root, 4);
    if(successor == NULL)
        cout<<"No successor present\n";
    else
        cout<<"Successor is = "<<successor->data<<"\n";
}
