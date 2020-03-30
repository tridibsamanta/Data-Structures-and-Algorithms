#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* FindMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* Delete(Node* root, int data) {
    if(root == NULL)
        return root;
    //Node to be deleted is less than root, will be present in left subtree
    else if(data < root->data)
        root->left = Delete(root->left, data);
    //Node to be deleted is greater than root, will be present in right subtree
    else if(data > root->data)
        root->right = Delete(root->right, data);
    //Node to be deleted is found
    else {
        //Node has no child nodes
        if(root->left == NULL && root->right == NULL) {
            //Deallocate space
            delete root;
            root = NULL;
        }
        //Node has only one child node
        else if(root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //Node has 2 child nodes
        else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(Node * root) {
    if(root == NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

Node* Insert(Node * root, int data) {
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

    cout<<"Tree is : "; Inorder(root);

    root = Delete(root,5);
    cout<<"\nTree is : "; Inorder(root);

    root = Delete(root,1);
    cout<<"\nTree is : "; Inorder(root);

    root = Delete(root,11);
    cout<<"\nTree is : "; Inorder(root);
}
