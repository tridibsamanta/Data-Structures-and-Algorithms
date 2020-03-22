#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(int data) {
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data) {
    if(root == NULL)
        root = GetNewNode(data);
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);

    return root;
}

bool Search(struct BstNode* root, int data) {
    if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data <= root->data)
        return Search(root->left,data);
    else
        return Search(root->right,data);
}

int main() {
    struct BstNode* root = NULL;
    int c;
    do {
    printf("1. Insert element\n2. Search element\n");
    printf("Enter your choice ? \n");
    int ch;
    scanf("%d",&ch);
    switch(ch) {
    case 1:
        {
            int data;
            printf("Enter the element to be inserted ?\n");
            scanf("%d",&data);
            root = Insert(root,data);
            break;
        }
    case 2:
        {
            int number;
            printf("Enter the element to be searched ?\n");
            scanf("%d",&number);
            if(Search(root,number))
                printf("Element found\n");
            else
                printf("Element not found\n");
            break;
        }
    default:
        printf("Incorrect choice !\n");
    }
    printf("Want to continue ? (1. Yes 2. No)\n");
    scanf("%d",&c);
    } while(c == 1);

    return 0;
}
