#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head;

/* --------------- PROTOTYPES --------------- */
void create(int array[], int length);
void display(struct Node *currentNode);
void recursiveDisplay(struct Node *currentNode);
int getLength(struct Node *currentNode);
void insert(struct Node *currentNode, int index, int value);
int del(struct Node *currentNode, int index);
int sum(struct Node *currentNode);
int maximum(struct Node *currentNode);
struct Node* linearSearch(struct Node *currentNode, int key);
struct Node* recursiveSearch(struct Node *currentNode, int key);
struct Node* improvedSearch(struct Node *currentNode, int key);

/* --------------- FUNCTIONS --------------- */
void create(int array[], int length) {

    int i;
    struct Node *temp, *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = array[0];
    head->next = head;
    last = head;

    for (i = 1; i < length; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = array[i];
        temp->next = last->next;
        last->next = temp;
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

void recursiveDisplay(struct Node *currentNode) {

    static int flag = 0;

    if (currentNode != head || flag == 0) {
        flag = 1;
        printf("%d ", currentNode->data);
        recursiveDisplay(currentNode->next);
    } else if (currentNode == head && flag != 0) {
        printf("\n");
    }

    flag = 0;
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

        } else {

            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }

            currentNode->next = temp;
            temp->next = head;
            head = temp;
        }
    } else {

        for (i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = currentNode->next;
        currentNode->next = temp;
    }
}

int del(struct Node *currentNode, int index) {

    struct Node *aux;
    int i, value;

    if (index < 1 || index > getLength(currentNode)) {
        return -1;
    }

    if (index == 1) {

        while (currentNode->next != head) {
            currentNode = currentNode->next;
        }

        value = head->data;

        if (currentNode == head) {
            free(head);
            head = NULL;
        } else {
            currentNode->next = head->next;
            free(head);
            head = currentNode->next;
        }

    } else {

        for (i = 0; i < index - 2; i++) {
            currentNode = currentNode->next;
        }

        aux = currentNode->next;
        currentNode->next = aux->next;
        value = aux->data;
        free(aux);
    }

    return value;
}

int sum(struct Node *currentNode) {

    int sum = 0;

    if (currentNode == NULL) {
        return -1;
    }

    do {
        sum += currentNode->data;
        currentNode = currentNode->next;
    } while (currentNode != head);

    return sum;
}

int recursiveSum(struct Node *currentNode) {

    static int flag = 0;

    if (currentNode == head && flag != 0) {
        return 0;
    } else if (currentNode != head || flag == 0) {
        flag = 1;
        return recursiveSum(currentNode->next) + currentNode->data;
    } else {
        return -1;
    }

    flag = 0;
}

int maximum(struct Node *currentNode) {

    int max = INT_MIN;

    do {

        if (currentNode->data > max) {
            max = currentNode->data;
        }

        currentNode = currentNode->next;
    } while (currentNode != head);

    return max;
}

struct Node* linearSearch(struct Node *currentNode, int key) {

    do {

        if (currentNode->data == key) {
            return currentNode;
        }

        currentNode = currentNode->next;

    } while (currentNode != head);

    return NULL;
}

struct Node* recursiveSearch(struct Node *currentNode, int key) {

    static int flag = 0;

    if (currentNode == head && flag != 0) {
        return NULL;
    }

    if (currentNode != head || flag == 0) {
        
        flag = 1;

        if (currentNode->data == key) {
            return currentNode;
        } else {
            return recursiveSearch(currentNode->next, key);
        }

    }

    flag = 0;
}

struct Node* improvedSearch(struct Node *currentNode, int key) {

    struct Node *previous = (struct Node *)malloc(sizeof(struct Node));
    struct Node *aux = currentNode;
    int length = getLength(head);
    int count = 1;

    do {

        if (currentNode->data == key) {

            if (count == length) {

                currentNode->next = head;
                head = currentNode;
                previous->next = currentNode;
                return currentNode;

            } else if (count > 1 && count < length) {

                while (aux->next != head) {
                    aux = aux->next;
                }

                previous->next = currentNode->next;
                currentNode->next = head;
                head = currentNode;
                aux->next = currentNode;
                return currentNode;

            } else {
                return currentNode;
            }

        }

        count++;
        previous = currentNode;
        currentNode = currentNode->next;

    } while (currentNode != head);

    return NULL;
}

/* --------------- MAIN --------------- */
int main() {

    int numbers[] = { 2, 3, 4, 5, 6 };
    create(numbers, sizeof(numbers) / sizeof(numbers[0]));

    printf("Node found at: %p\n", improvedSearch(head, 2));

    display(head);

    return 0;
}
