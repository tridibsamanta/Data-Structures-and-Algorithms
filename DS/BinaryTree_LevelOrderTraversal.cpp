#include<iostream>
#include<cstdio>
#include<queue>
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
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}

void LevelOrder(Node* root) {
    if(root == NULL) {
        printf("Tree is empty !\n");
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    printf("Elements in the tree are : ");
    //As long as there is at-least one discovered node in queue
    while(!Q.empty()) {
        //Print data of front node address (discovered node)
        Node* current = Q.front();
        printf("%c ",current->data);
        //Remove the visited (printed) node address
        Q.pop();
        //Push the immediate left child node address
        if(current->left != NULL)
            Q.push(current->left);
        //Push the immediate right child node address
        if(current->right != NULL)
            Q.push(current->right);
    }
    printf("\n");
}

int main() {
    Node* root = NULL; //Empty tree
    int c;
    do {
    printf("1. Insert element\n2. Display tree\n");
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
            LevelOrder(root);
            break;
        }
    default:
        printf("Incorrect choice !\n");
    }
    printf("Want to continue ? (1. Yes 2. No)\n");
    scanf("%d",&c);
    } while(c == 1);
}
