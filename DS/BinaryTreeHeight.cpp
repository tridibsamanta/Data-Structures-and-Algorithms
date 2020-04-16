#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* InsertNode(Node* root, int data) {
	if (root == NULL)
		root = CreateNode(data);
	else if (data <= root->data)
		root->left = InsertNode(root->left, data);
	else
		root->right = InsertNode(root->right, data);
	return root;
}

int FindHeight(Node* root) {
	if (root == NULL)
		return -1;
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int main() {
	Node* root = NULL;

	root = InsertNode(root, 15); root = InsertNode(root, 10);
	root = InsertNode(root, 20); root = InsertNode(root, 8);

    cout << "Height of the tree = " << FindHeight(root);
}
