#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* GetNewNode(int data) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* Insert(struct Node* root, int data) {
	if (root == NULL)
		root = GetNewNode(data);
	else if (data < root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

struct Node* FindMin(struct Node* root) {
	while(root->left != NULL)
		root = root->left;
	return root;
}

struct Node* Delete(struct Node* root, int data) {
	if (root == NULL) {
		printf("Tree is empty !\n");
		return NULL;
	}
	//Node to be deleted is less than root, will be present in left subtree
	else if (data < root->data)
		root->left = Delete(root->left, data);
    //Node to be deleted is greater than root, will be present in right subtree
	else if (data > root-> data)
		root->right = Delete(root->right, data);
    //Node to be deleted is found
	else {
        //Node has no child nodes
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
        //Node has only right child
		else if (root->left == NULL) {
			struct Node* temp = root;
			root = root->right;
			free(temp);
		}
		//Node has only left child
		else if (root->right == NULL) {
			struct Node* temp = root;
			root = root->left;
			free(temp);
		}
		//Node has both left and right child
		else {
			struct Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

void InorderTraversal(struct Node* root) {
	if (root == NULL)
		return;
	InorderTraversal(root->left);
	printf("%d ",root->data);
	InorderTraversal(root->right);
}

int main() {
	struct Node* root = NULL;

	root = Insert(root, 12); root = Insert(root, 5);
	root = Insert(root, 15); root = Insert(root, 3);
	root = Insert(root, 7); root = Insert(root, 13);
	root = Insert(root, 17); root = Insert(root, 1);
	root = Insert(root, 9);

	printf("Tree is : ");
	InorderTraversal(root);
    printf("\n");

	int element;
	printf("Enter the node you want to delete : ");
	scanf("%d", &element);
	root = Delete(root, element);

	printf("Tree is : ");
	InorderTraversal(root);
	printf("\n");
}
