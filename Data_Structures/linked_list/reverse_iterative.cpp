#include <iostream>

using namespace std;

struct Node{
	int digit;
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
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newNode;

}

void printList(List *list){
	if (isEmpty(list)){
		cout << "Empty list" << endl;
		return;
	}

	cout << "List Values:" << endl;
	Node *current = list->head;
	while(current != NULL){
		cout << current->digit << " -> ";
		current = current->next;
	}
	cout << "NULL" << endl << endl;
}

Node  *reverse(Node *current) {
	if (current == NULL){
		return current;
	}

	Node *prev = NULL;
	Node *next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

int main(int argc, char const *argv[]){
	List *list = new List();
	list->head = NULL;

	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	add(list, 5);
	add(list, 6);

	printList(list);
	list->head = reverse(list->head);
	cout << "Reversed" << endl;
	printList(list);
	return 0;
}