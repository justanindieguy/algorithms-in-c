#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *head;

/* --------------- PROTOTYPES --------------- */
void create(int array[], int length);
void display(struct Node *currentNode);
int getLength(struct Node *currentNode);
void insert(struct Node *currentNode, int index, int value);
int del(struct Node *currentNode, int index);

/* --------------- FUNCTIONS --------------- */
void create(int array[], int length) {

    struct Node *temp, *last;
    int i;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = array[0];
    head->prev = head;
    head->next = head;

    last = head;

    for (i = 1; i < length; i++) {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = array[i];

        last->next = temp;
        temp->prev = last;

        head->prev = temp;
        temp->next = head;

        last = temp;
    }
}

void display(struct Node *currentNode) {

    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);

    printf("\n");
}

int getLength(struct Node *currentNode) {

    int len = 0;

    do {
        
        len++;
        currentNode = currentNode->next;

    } while (currentNode != head);

    return len;
}

void insert(struct Node *currentNode, int index, int value) {

    struct Node *temp;
    int i;

    if (index < 0 || index > getLength(currentNode)) {
        return;
    }

    if (index == 0) {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;

        if (head == NULL) {
            
            head = temp;
            head->next = head;
            head->prev = head;

        } else {

            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;

            head = temp;
        }

    } else {

        for (i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;

        currentNode->next->prev = temp;
        temp->next = currentNode->next;
        currentNode->next = temp;
        temp->prev = currentNode;
    }
}

int del(struct Node *currentNode, int index) {

    struct Node *aux;
    int value = -1;
    int i;

    if (index < 1 || index > getLength(currentNode)) {
        return value;
    }

    if (index == 1) {

        aux = head;
        head = head->next;
        aux->prev->next = head;
        head->prev = aux->prev;

        value = aux->data;
        free(aux);

    } else {

        aux = (struct Node *)malloc(sizeof(struct Node));

        for (i = 0; i < index - 1; i++) {
            aux = currentNode;
            currentNode = currentNode->next;
        }

        aux->next = currentNode->next;
        currentNode->next->prev = aux;

        value = currentNode->data;
        free(currentNode);
    }

    return value;
}

/* --------------- MAIN --------------- */
int main() {

    int numbers[] = { 6, 9, 3, 7, 2 };
    create(numbers, sizeof(numbers) / sizeof(numbers[0]));

    printf("Deleted value: %d\n", del(head, 6));

    printf("\nLinked List:\n");
    display(head);

    printf("\nLength: %d\n", getLength(head));

    return 0;
}
