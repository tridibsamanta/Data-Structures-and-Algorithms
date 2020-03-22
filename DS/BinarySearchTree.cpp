#include<iostream>
using namespace std;

//Definition of Node for BST
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

//Creating a new Node in heap
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//To insert an element in BST and return address of root node
BstNode* Insert(BstNode* root, int data) {
    //Tree is empty
    if(root == NULL) {
        root = GetNewNode(data);
        return root;
    }
    //If element is lesser or equal to the root element, insert in left subtree
    else if(data <= root->data) {
        root->left = Insert(root->left, data);
    }
    //Element is greater than root element, insert in right subtree
    else {
        root->right = Insert(root->right, data);

    }
    return root;
}

//To Search an element in BST and return true if element is found else return false
bool Search(BstNode* root, int data) {
    //Tree is empty
    if(root == NULL)
        return false;
    //If root element is equal to the element we are searching
    else if(root->data == data)
        return true;
    //If the element we are searching, is less or equal to the root element, search left subtree
    else if(data <= root->data)
        return Search(root->left, data);
    //The element we are searching, is greater than the root element, search right subtree
    else
        return Search(root->right, data);
}

int main() {
    BstNode* root = NULL; //Tree is empty
    string c;
    do {
    cout<<"1. Insert element\n2. Search element\n";
    cout<<"Enter your choice ? \n";
    int ch;
    cin>>ch;
    switch(ch) {
    case 1:
        {
            int data;
            cout<<"Enter the element to be inserted ?\n";
            cin>>data;
            root = Insert(root,data);
            break;
        }
    case 2:
        {
            int number;
            cout<<"Enter the element to be searched ?\n";
            cin>>number;
            if(Search(root,number) == true)
                cout<<"Element found\n";
            else
                cout<<"Element not found\n";
            break;
        }
    default:
        cout<<"Incorrect choice !\n";
    }
    cout<<"Want to continue ? (Y/N)\n";
    cin>>c;
    } while(c == "Y" || c == "y");
}
