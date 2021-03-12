#include <iostream>
#include <string>

using namespace std;

struct Node{
	Node *left;
	Node *right;
	int value;

	Node(int value_) {
		value = value_;
		left = NULL;
		right = NULL;
	}
};

void insert(Node *root, int value){
	if (value > root->value){
		if (root->right == NULL)
		{
			root->right = new Node(value);
			return;
		}

		insert(root->right, value);
	} else {
		if (root->left == NULL)
		{
			root->left = new Node(value);
			return;
		}

		insert(root->left, value);
	}
}

void printInOrder(Node *root){
	if (root  == NULL)
	{
		return;
	}
	printInOrder(root->left);
	cout << root->value << " ";
	printInOrder(root->right);
}

int main(int argc, char const *argv[]){
	Node *root = new Node(8);


	insert(root, 3);
	insert(root, 289);
	insert(root, 10);
	
	
	insert(root, 4);
	insert(root, 13);
	insert(root, 10);
	

	insert(root, 1);
	insert(root, 6);
	insert(root, 14);


	insert(root, 7);
	printInOrder(root);
	cout << endl;
	return 0;
}