#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

/* --------------- PROTOTYPES --------------- */
void create(int array[], int length);
void display(struct Node *currentNode);
int getLength(struct Node *currentNode);
void insert(struct Node *currentNode, int index, int value);
int del(struct Node *currentNode, int index);
void reverse(struct Node *currentNode);

/* --------------- FUNCTIONS --------------- */
void create(int array[], int length) {
    
    struct Node *temp, *last;
    int i;

    // First node initialization.
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = array[0];
    first->prev = NULL;
    first->next = NULL;

    last = first;

    for (i = 1; i < length; i++) {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = array[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *currentNode) {

    while (currentNode != NULL) {

        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

int getLength(struct Node *currentNode) {

    int len = 0;

    while (currentNode != NULL) {

        len++;
        currentNode = currentNode->next;
    }

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
        temp->next = first;
        temp->prev = NULL;
        first->prev = temp;
        first = temp;

    } else {

        for (i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;

        temp->prev = currentNode;
        temp->next = currentNode->next;

        if (currentNode->next) {
            currentNode->next->prev = temp;
        }

        currentNode->next = temp;
    }
}

int del(struct Node *currentNode, int index) {

    int i, value = -1;

    if (index < 1 || index > getLength(currentNode)) {
        return value;
    }

    if (index == 1) {

        first = first->next;
        
        if (first) {
            first->prev = NULL;
        }

        value = currentNode->data;
        free(currentNode);

    } else {

        for (i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }

        currentNode->prev->next = currentNode->next;

        if (currentNode->next) {
            currentNode->next->prev = currentNode->prev;
        }

        value = currentNode->data;
        free(currentNode);
    }

    return value;
}

void reverse(struct Node *currentNode) {

    struct Node *temp;

    while (currentNode != NULL) {
        
        temp = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = temp;

        currentNode = currentNode->prev;

        if (currentNode != NULL && currentNode->next == NULL) {
            first = currentNode;
        }
    }
}

/* --------------- MAIN --------------- */
int main() {

    int numbers[] = { 10, 20, 30, 40, 50 };
    create(numbers, sizeof(numbers) / sizeof(numbers[0]));

    reverse(first);

    printf("Linked list is:\n");
    display(first);

    return 0;
}
