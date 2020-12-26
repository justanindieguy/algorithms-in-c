#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

/* --------------- PROTOTYPES --------------- */
void create(int array[], int n);
void createSecond(int array[], int n);
void display(struct Node *currentNode);
void recursiveDisplay(struct Node *currentNode);
void reverseDisplay(struct Node *currentNode);
int getLength(struct Node *currentNode);
int recursiveCount(struct Node *currentNode);
int sum(struct Node *currentNode);
int recursiveSum(struct Node *currentNode);
int maximum(struct Node *currentNode);
int recursiveMax(struct Node *currentNode);
int minimum(struct Node *currentNode);
int recursiveMin(struct Node *currentNode);
struct Node* linearSearch(struct Node *currentNode, int key);
struct Node* recursiveSearch(struct Node *currentNode, int key);
struct Node* improvedSearch(struct Node *currentNode, int key);
void insert(struct Node *currentNode, int position, int value);
void sortedInsert(struct Node *currentNode, int value);
int delete(struct Node *currentNode, int index);
int isSorted(struct Node *currentNode);
void removeDuplicates(struct Node *currentNode);
void reverseArr(struct Node *currentNode);
void reverseSliding(struct Node *lastNode);
void reverseRecursive(struct Node *prevNode, struct Node *currentNode);
void concat(struct Node *first, struct Node *second);
void merge(struct Node *first, struct Node *second);
int isLoop(struct Node *first);
int getMiddle(struct Node *first);

/* --------------- FUNCTIONS --------------- */
void create(int array[], int length) {

    int i;
    struct Node *temp, *last;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = array[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < length; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void createSecond(int array[], int length) {

    int i;
    struct Node *temp, *last;

    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = array[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < length; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = array[i];
        temp->next = NULL;
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

void recursiveDisplay(struct Node *currentNode) {

    if (currentNode != NULL) {
        printf("%d ", currentNode->data);
        recursiveDisplay(currentNode->next);
    } else if (currentNode == NULL) {
        printf("\n");
    }
}

void reverseDisplay(struct Node *currentNode) {

    if (currentNode != NULL) {
        reverseDisplay(currentNode->next);

        if (currentNode != first) {
            printf("%d ", currentNode->data);
        } else {
            printf("%d\n", currentNode->data);
        }
        
    }
}

int getLength(struct Node *currentNode) {

    int counter = 0;

    while (currentNode != NULL) {
        counter++;
        currentNode = currentNode->next;
    }

    return counter;
}

int recursiveCount(struct Node *currentNode) {

    if (currentNode == NULL) {
        return 0;
    } else {
        return recursiveCount(currentNode->next) + 1;
    }
}

int sum(struct Node *currentNode) {

    int sum = 0;

    while (currentNode != NULL) {
        sum += currentNode->data;
        currentNode = currentNode->next;
    }

    return sum;
}

int recursiveSum(struct Node *currentNode) {

    if (currentNode == NULL) {
        return 0;
    } else {
        return recursiveSum(currentNode->next) + currentNode->data;
    }
}

int maximum(struct Node *currentNode) {

    int max = INT_MIN;

    while (currentNode != NULL) {

        if (currentNode->data > max) {
            max = currentNode->data;
        }

        currentNode = currentNode->next;
    }

    return max;
}

int recursiveMax(struct Node *currentNode) {

    int aux = 0;

    if (currentNode == NULL) {
        return INT_MIN;
    }

    aux = recursiveMax(currentNode->next);
    return aux > currentNode->data ? aux : currentNode->data;
}

int minimum(struct Node *currentNode) {

    int min = INT_MAX;

    while (currentNode != NULL) {

        if (currentNode->data < min) {
            min = currentNode->data;
        }

        currentNode = currentNode->next;
    }

    return min;
}

int recursiveMin(struct Node *currentNode) {

    int aux = 0;

    if (currentNode == NULL) {
        return INT_MAX;
    }

    aux = recursiveMin(currentNode->next);
    return aux < currentNode->data ? aux : currentNode->data;
}

struct Node* linearSearch(struct Node *currentNode, int key) {

    while (currentNode != NULL) {

        if (key == currentNode->data) {
            return currentNode;
        }

        currentNode = currentNode->next;
    }

    return NULL;
}

struct Node* recursiveSearch(struct Node *currentNode, int key) {

    if (currentNode == NULL) {
        return NULL;
    }

    if (key == currentNode->data) {
        return currentNode;
    } else {
        return recursiveSearch(currentNode->next, key);
    }
}

struct Node* improvedSearch(struct Node *currentNode, int key) {

    struct Node *previous = (struct Node*)malloc(sizeof(struct Node));

    while (currentNode != NULL) {

        if (key == currentNode->data) {
            previous->next = currentNode->next;
            currentNode->next = first;
            first = currentNode;
            return currentNode;
        }

        previous = currentNode;
        currentNode = currentNode->next;
    }

    return NULL;
}

void insert(struct Node *currentNode, int index, int value) {

    struct Node *temp;
    int i;

    if (index < 0 || index > getLength(currentNode)) {
        return;
    }

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    if (index == 0) {
        temp->next = first;
        first = temp;
    } else {

        for (i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }

        temp->next = currentNode->next;
        currentNode->next = temp;
    }
}

void sortedInsert(struct Node *currentNode, int value) {

    struct Node *newNode, *aux;

    aux = (struct Node*)malloc(sizeof(struct Node));

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (first == NULL) {

        first = newNode;

    } else {

        while (currentNode && currentNode->data < value) {
            aux = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode == first) {
            newNode->next = first;
            first = newNode;
        } else {
            newNode->next = aux->next;
            aux->next = newNode;
        }
    }
}

int delete(struct Node *currentNode, int index) {

    struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
    int value = -1, i;

    if (index < 1 || index > getLength(currentNode)) {
        return value;
    }

    if (index == 1) {

        aux = first;
        value = first->data;
        first = first->next;
        free(aux);
        return value;

    } else {

        for (i = 0; i < index - 1; i++) {
            aux = currentNode;
            currentNode = currentNode->next;
        }

        aux->next = currentNode->next;
        value = currentNode->data;
        free(currentNode);
        return value;
    }
}

int isSorted(struct Node *currentNode) {

    int value = INT_MIN;

    while (currentNode != NULL) {

        if (currentNode->data < value) {
            return 0;
        }

        value = currentNode->data;
        currentNode = currentNode->next;
    }

    return 1;
}

void removeDuplicates(struct Node *currentNode) {

    struct Node *nextNode = currentNode->next;

    while (nextNode != NULL) {

        if (currentNode->data != nextNode->data) {
            currentNode = nextNode;
            nextNode = nextNode->next;
        } else {
            currentNode->next = nextNode->next;
            free(nextNode);
            nextNode = (struct Node*)malloc(sizeof(struct Node));
            nextNode = currentNode->next;
        }
    }
}

void reverseArr(struct Node *currentNode) {

    int i = 0;
    int *auxArr = (int *)malloc(getLength(currentNode) * sizeof(int));

    while (currentNode != NULL) {
        auxArr[i] = currentNode->data;
        currentNode = currentNode->next;
        i++;
    }

    currentNode = first;
    i--;

    while (currentNode != NULL) {
        currentNode->data = auxArr[i];
        currentNode = currentNode->next;
        i--;
    }
}

void reverseSliding(struct Node *lastNode) {

    struct Node *prevNode = NULL;
    struct Node *midNode = NULL;

    while (lastNode != NULL) {
        prevNode = midNode;
        midNode = lastNode;
        lastNode = lastNode->next;
        midNode->next = prevNode;
    }

    first = midNode;
}

void reverseRecursive(struct Node *prevNode, struct Node *currentNode) {

    if (currentNode != NULL) {
        reverseRecursive(currentNode, currentNode->next);
        currentNode->next = prevNode;
    } else {
        first = prevNode;
    }
}

void concat(struct Node *first, struct Node *second) {

    third = first;

    while (first->next != NULL) {
        first = first->next;
    }

    first->next = second;
}

void merge(struct Node* first, struct Node* second) {

    struct Node *last;

    if (first->data < second->data) {
        third = last = first;
        first = first->next;
        last->next = NULL;
    } else {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first != NULL && second != NULL) {

        if (first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first) {
        last->next = first;
    } else {
        last->next = second;
    }
}

int isLoop(struct Node *first) {

    struct Node *p, *q;
    p = q = first;

    do {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    } while ((p != NULL && q != NULL) && (p != q));

    if (p == q) {
        return 1;
    } else {
        return 0;
    }
}

int getMiddle(struct Node *currentNode) {

    struct Node *aux = first;

    while (currentNode != NULL) {

        currentNode = currentNode->next;

        if (currentNode != NULL) {
            currentNode = currentNode->next;
        }

        if (currentNode != NULL) {
            aux = aux->next;
        }
    }

    return aux->data;
}

/* --------------- MAIN --------------- */
int main() {

    int arrayOne[] = { 10, 20, 30, 40, 50 };
    create(arrayOne, sizeof(arrayOne) / sizeof(arrayOne[0]));

    display(first);

    printf("\nMiddle node: %d\n", getMiddle(first));

    return 0;
}
