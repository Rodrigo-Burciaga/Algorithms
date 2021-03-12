#include <stdlib.h>
#include <stdio.h>


/***
    Type of list implemented




             Node           Node            Node
             +---+---+     +----+----+     +-----+----+ 
         --> | 1 | o-----> | 2  |   o----->| 3   |NULL|  
         |   +---+---+     +----+----+     +-----+----+  
         |
         |
         |
       +---+   
List ->| o | head
       +---+

**/

typedef struct nodo {
    int digit;
    struct nodo *next;
} Nodo;

typedef struct list{
    Nodo *head;
} List;

int isEmpty(List *list) {
    return list->head == NULL;
}


void removeFirstElement(List *list) {
    Nodo *head = list->head;
    list->head = list->head->next;
    free(head);
}

void removeLastElement(List *list, int listSize) {
    int index = 1; 
    Nodo *actualNode = list->head;
    while(actualNode->next != NULL && index < (listSize - 1) ) {
        actualNode = actualNode->next;
        ++index;
    }
    Nodo *last = actualNode->next;
    actualNode->next = NULL;
    free(last);
}

void removeMediumElement(List *list, int index) {
    int indexBefore = index - 1;
    Nodo *actualNode = list->head;
    Nodo *beforeNode;
    for (int i = 1; i < index; ++i) {
        if (i == indexBefore) {
            beforeNode = actualNode;
        } 
        actualNode = actualNode->next;
    }
    beforeNode->next = actualNode->next;
    actualNode->next = NULL;
    free(actualNode);
}

void removeElementAtIndex(int index, List *list, int *listSize) {
    if (isEmpty(list) || index > *listSize || index < 1){
        printf("Impossible\n");
        return;
    }

    if (index == 1) {
        (*listSize)--;
        removeFirstElement(list);
        return;
    }
    if (index == *listSize) {
        removeLastElement(list, *listSize);
        (*listSize)--;
        return;
    } 

    removeMediumElement(list, index);
    
}

void removeElemetByValue(List *list , int valueToBrowse, int *listSize) {
    if (isEmpty(list)){
        printf("Empty list\n");
        return;
    }
    Nodo *actualNode = list->head;
    if (actualNode != NULL && actualNode->digit == valueToBrowse){
        list->head = actualNode->next;
        free(actualNode);
        (*listSize)--;
        return;
    }

    Nodo *previous = NULL;
    while(actualNode != NULL && actualNode->digit != valueToBrowse) {
        previous = actualNode;
        actualNode = actualNode->next;
    }

    if (actualNode == NULL){
        printf("Not found value\n");
        return;
    }

    previous->next = actualNode->next;
    free(actualNode);
    (*listSize)--;
}

void addToList(Nodo *nodo, List *list) {
    Nodo *aux = (Nodo *) malloc(sizeof(Nodo));
    aux->digit = nodo->digit;
    aux->next = NULL;
    if (isEmpty(list)){
        list->head = aux;
        return;
    } 

    Nodo *last = list->head;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = aux;
    aux = NULL;
}


void printList(List *list) {
   if (isEmpty(list)) {
       printf("\nEmpty list\n");
       return;
   }
   printf("\n List Values \n");
   Nodo *nodo = list->head;
   while(nodo != NULL) {
        printf("%d -> ", nodo->digit);
        nodo = nodo->next;
   }
   printf("NULL\n\n");
}


void initializeList(List *list) {
    list->head = NULL;
}

int getLength(Nodo *node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + getLength(node->next);
}


int main(int argc, char const *argv[]) {

    printf("List implementation");
    int option; 
    List list;
    initializeList(&list);
    int listSize = 0;


    do {
        printf("Menu:\n1.-Add to list\n2.-Remove from list\n3.-Print list\n4.-Get Length\n5.-Exit\n");
        scanf("%d", &option);
        if (option == 1) {
            Nodo nodo;
            printf("Enter Value of element: ");
            scanf("%d", &nodo.digit);
            addToList(&nodo, &list);
            listSize++;
            printf("listSize %d\n", listSize);
        } else if (option == 2) {
            printf("1.-By index\n2.-By value\n");
            scanf("%d", &option);
            if (option == 1) {
                printf("Enter index: ");
                int index;
                scanf("%d", &index);
                removeElementAtIndex(index, &list, &listSize);
            } else {
                printf("Enter value\n");
                int value;
                scanf("%d", &value);
                removeElemetByValue(&list, value, &listSize);
            }
            
        } else if (option == 3) {
            printList(&list);
        } else if (option == 4) {
            printf("%d\n", getLength(list.head));
        } else if (option != 5) {
            printf("Invalid option\n");
        }

    } while (option!=5);

    return 0;
}