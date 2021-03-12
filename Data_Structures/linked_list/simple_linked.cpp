#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node *next = NULL;	
	
};

class List{
	public:
		Node *head;
			
};


int isEmpty(List *list) {
	return  list->head == NULL;
}


void removeFromList(List *list, int index, int& length) {
	if (index < 1 || index > length) {
		cout << "Bad index" << endl;
		return;
	}
	if (isEmpty(list)){
		cout << "Empty list";
		return;
	}
	if (index == 1) {
		Node *uno = list->head;
		list->head = uno->next;	
		length--;
		delete uno;
		return;
	}

	
	int index_temp = 1;
	Node *temp = list->head;
	while (temp->next != NULL && index_temp < (index-1) ) {
		index_temp++;
		temp = temp->next;
	}


	if (index == length){
		Node *last = temp->next;
		temp->next = NULL;
		delete last;
	} else {
		Node *medium = temp->next;
		temp->next = temp->next->next;
		delete medium;
	}
	
	length--;
}

void removeByValue(List *list, int& value, int& length) {
	if (isEmpty(list)){
		cout << "Empty list" << endl;
		return;
	}

	Node *actualNode = list->head;
	if (actualNode != NULL && actualNode->data == value){
		list->head = actualNode->next;
		delete actualNode;
		length--;
		return;
	}

	Node *previous = NULL;
	while(actualNode != NULL && actualNode->data != value){
		previous = actualNode;
		actualNode = actualNode->next;
	}

	if (actualNode == NULL){
		cout << "Not found" << endl;
		return;
	}

	previous->next = actualNode->next;
	delete actualNode;
	length--;
}

void printList(List *list){
	if (isEmpty(list)) {
		cout << "Empty list" << endl;
		return;
	}
	cout << "List Values: " << endl;
	Node *node = list->head;
	while(node != NULL){
		cout << node->data << " -> ";
		node = node->next;
	}
	cout << "NULL" << endl << endl;
}


void push(List *list, Node *node, int& size){
	if (isEmpty(list)) {
		list->head = node;
		size++;
		return;
	} 

	Node *actualNode = list->head;
	while(actualNode->next != NULL){
		actualNode = actualNode->next;
	}

	actualNode->next = node;
	size++;

}

int getLength(Node *node) {
	if (node == NULL) {
		return 0;
	}

	return 1 + getLength(node->next);
}

int main(int argc, char const *argv[]) {

	List * list = new List();
	list->head = NULL;
	int size = 0;

	int option;
	do {
		cout << "List implementation menu: \n1.-Add to List\n2.-Remove from List\n3.-Print List\n4.-Get Length\n5.-Exit" << endl;
		cin >> option;
		if (option == 1){
			Node *node = new Node();
			cout << "Enter element: ";
			cin >> node->data;
			push(list, node, size);
		} else if (option == 2) {
			cout << "1.-By index\n2.-By value\n ";
			cin >> option;
			if (option == 1){
				int index;
				cout << "Enter index: ";
				cin >> index;
				removeFromList(list, index, size);
			} else {
				int value;
				cout << "Enter value: ";
				cin >> value;
				removeByValue(list, value, size);
			}
		
		} else if (option == 3) {
			printList(list);	
		} else if (option == 4) {
			cout << "Length: " << getLength(list->head) << endl << endl;
		} else if (option != 5) {
			cout << "Wrong option" << endl;

		}
	} while (option != 5);


	return 0;
}