#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int digit;
	struct Node* next;
} Node;


typedef struct List{
	Node *head;
} List;


int isEmpty(List *list) {
	return list->head == NULL;
}


void add(List *list, int value){
	Node *aux = (Node *) malloc(sizeof(Node));
	aux->digit = value;
	aux->next = NULL;

	if (isEmpty(list)) {
		list->head = aux;
		return;
	}

	Node *current = list->head;
	while(current->next != NULL) {
		current = current->next;
	}

	current->next = aux;
}

void printListRecursive(Node *current) {
	if (current == NULL) {
		printf("NULL\n\n");
		return;
	}

	printf("%d -> ", current->digit);
	printListRecursive(current->next);
}


void printReverseRecursive(Node *current) {
	if (current == NULL) {
		return;
	}

	printReverseRecursive(current->next);
	printf("%d -> ", current->digit);
}

Node* reverse(Node *current) {
	if (current == NULL || current->next == NULL) {
		return current;
	}

	Node *head = reverse(current->next);
	current->next->next=current;
	current->next = NULL;

	return head;

}


int main(int argc, char const *argv[]) {
	List list;
	list.head = NULL;

	add(&list, 2);
	add(&list, 5);
	add(&list, 190);
	add(&list, 13);
	add(&list, 584);
	add(&list, 67);
	
	printf("Original list\n");
	printListRecursive(list.head);

	printf("Print reverse recursive\n");
	printReverseRecursive(list.head);
	printf("NULL\n\n");


	printf("After reversed\n");
	list.head = reverse(list.head);
	printListRecursive(list.head);


	return 0;
}