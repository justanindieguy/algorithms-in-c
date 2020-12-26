#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertRear(struct Node **front, struct Node **rear, int value);
void insertFront(struct Node **front, struct Node **rear, int value);
int deleteFront(struct Node **front);
int deleteRear(struct Node *front, struct Node **rear);
void display(struct Node *front);

void insertRear(struct Node **front, struct Node **rear, int value) {
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Queue is full.\n");
    } else {
        temp->data = value;
        temp->next = NULL;

        if ((*front) == NULL) {
            (*front) = (*rear) = temp;
        } else {
            (*rear)->next = temp;
            (*rear) = temp;
        }
    }
}

void insertFront(struct Node **front, struct Node **rear, int value) {
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Queue is full.\n");
    } else {
        temp->data = value;
        temp->next = NULL;

        if (*front == NULL) {
            (*front) = (*rear) = temp;
        } else {
            temp->next = (*front);
            (*front) = temp;
        }
    }
}

int deleteFront(struct Node **front) {
    struct Node *temp;
    int value = -1;

    if ((*front) == NULL) {
        printf("Queue is empty.\n");
    } else {
        value = (*front)->data;
        temp = (*front);
        (*front) = (*front)->next;
        free(temp);
    }

    return value;
}

int deleteRear(struct Node *front, struct Node **rear) {
    struct Node *temp = front;
    struct Node *aux = (*rear);
    int value = -1;

    if ((*rear) == NULL) {
        printf("Queue is empty.\n");
    } else {
        value = (*rear)->data;

        while (temp->next != (*rear)) {
            temp = temp->next;
        }

        temp->next = NULL;
        value = (*rear)->data;
        (*rear) = temp;
        free((aux));
    }

    return value;
}

void display(struct Node *front) {
    struct Node *aux = front;

    while (aux) {
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

int main() {
    struct Node *front = NULL;
    struct Node *rear = NULL;

    insertRear(&front, &rear, 10);
    insertRear(&front, &rear, 20);
    insertFront(&front, &rear, 30);

    display(front);
    
    printf("Deleted value: %d\n", deleteRear(front, &rear));
    display(front);

    return 0;
}