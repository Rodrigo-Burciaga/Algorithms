#include <iostream>

using namespace std;

struct Node{
	int  digit;
	Node *next;
};

struct List{
	Node *head;
};

int isEmpty(List *list){
	return list->head == NULL;
}

void add(List *list, int value){
	Node *newNode = new Node();
	newNode->digit = value;
	newNode->next = NULL;
	if (isEmpty(list)){
		list->head = newNode;
		return;
	}

	Node *current = list->head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

void printListRecursive(Node *current) {
	if (current == NULL){
		cout << "NULL" << endl << endl;
		return;
	}

	cout << current->digit << " -> ";
	printListRecursive(current->next);
}

void printListReverseRecursive(Node * current) {
	if (current == NULL){
		return;
	}
	printListReverseRecursive(current->next);
	cout << current->digit << " -> ";
}

Node* reverse(Node *current) {
	if (current == NULL || current->next == NULL){
		return current;
	}

	Node *head = reverse(current->next);
	current->next->next = current;
	current->next= NULL;
	return head;
}

int main(int argc, char const *argv[]){
	List list;
	list.head = NULL;

	add(&list, 1);
	add(&list, 2);
	add(&list, 3);
	add(&list, 4);
	add(&list, 5);
	add(&list, 6);
	cout << "Original list" << endl;
	printListRecursive(list.head);
	cout << "Print reverse Recursive" << endl;
	printListReverseRecursive(list.head); 
	cout <<  "NULL" << endl << endl;
	cout << "Reversed" << endl;
	list.head = reverse(list.head);
	printListRecursive(list.head);

	return 0;
}