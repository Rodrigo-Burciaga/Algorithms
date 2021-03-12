#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int digit;
	struct Node *next;
}Node;

typedef struct List{
	Node *head;
}List;

int isEmpty(List *list) {
	return list->head == NULL;
}

void add(List *list, int value){
	Node *newNode = (Node *) malloc(sizeof(Node));
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

	current->next=newNode;
}


void printList(List *list) {
	if (isEmpty(list)){
		printf("Empty list\n");
		return;
	}
	Node *current = list->head;
	while(current != NULL){
		printf("%d -> ", current->digit);
		current = current->next;
	}

	printf("NULL\n\n");
}


Node* reverse(Node *current) {
	if (current == NULL){
		return current;
	}

	Node *prev = NULL;
	Node *next = NULL;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev=current;
		current = next;
	}

	return prev;
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
	printf("Original List:\n");
	printList(&list);

	printf("Reversed:\n");
	list.head = reverse(list.head);
	printList(&list);


	return 0;
}