#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	int value;
} Node;

void printInOrder(Node *curr){
	if(curr == NULL) {
		return;
	}

	printInOrder(curr->left);
	printf("%d ", curr->value);
	printInOrder(curr->right);
}

int main(int argc, char const *argv[]){
	
	Node *root = (Node *) malloc(sizeof(Node));
	root->value = 1;

	root->left = (Node *) malloc(sizeof(Node));
	root->left->value = 2;

	root->right = (Node *) malloc(sizeof(Node));
	root->right->value = 3;

	root->left->left = (Node *) malloc(sizeof(Node));
	root->left->left->value = 4;

	root->left->right = (Node *) malloc(sizeof(Node));
	root->left->right->value = 5;

	root->right->right = (Node *) malloc(sizeof(Node));
	root->right->right->value = 6;

	printf("In order Binary tree\n");
	printInOrder(root);
	printf("\n");
	return 0;
}