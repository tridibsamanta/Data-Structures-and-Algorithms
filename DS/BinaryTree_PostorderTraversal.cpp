/*
Postorder Traversal of a Binary Tree

Example -
              F
            /   \
           D     J
          / \   / \
         B   E G   K
        / \     \
       A   C     I

Postorder Traversal - A C B E D I G K J F
*/

#include<iostream>
#include<cstdio>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
};

Node* GetNewNode(char data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, char data) {
	if(root == NULL)
		root = GetNewNode(data);
	else if(data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

void PostorderTraversal(Node* root) {
	if(root == NULL)
		return;
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%c ", root->data);
}

int main() {
    Node* root = NULL; //Empty tree
    int c;
    do {
    printf("1. Insert element\n2. Display tree (Postorder) \n");
    printf("Enter your choice ? \n");
    int ch;
    scanf("%d",&ch);
    switch(ch) {
    case 1:
        {
            char data;
            printf("Enter the node value ?\n");
            fflush(stdin);
            data = getchar();
            root = Insert(root,data);
            break;
        }
    case 2:
        {
            printf("Tree is : ");
            PostorderTraversal(root);
            printf("\n");
            break;
        }
    default:
        printf("Incorrect choice !\n");
    }
    printf("Want to continue ? (1. Yes 2. No)\n");
    scanf("%d",&c);
    } while(c == 1);
}

