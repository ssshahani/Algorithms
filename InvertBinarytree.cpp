#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* addNode(int data){
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inOrder(Node* root){
	if(root == NULL)
		return;

	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}

void mirror(Node* root){
	if(root == NULL)
		return;
	else{
		Node* temp = NULL;

		// Once both recursive call return, the call returns from leaf node to parent node
		mirror(root->left);
		mirror(root->right);

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}
int main(){
	Node *root = addNode(1);
	root->left = addNode(2);
	root->right = addNode(3);
	root->left->left = addNode(4);
	root->left->right = addNode(5);

	inOrder(root);
	printf("\n");
	mirror(root);
	printf("\n");
	inOrder(root);
	return 0;
}
