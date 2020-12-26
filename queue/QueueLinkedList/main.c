#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void enqueue(struct Node **front, struct Node **rear, int value);
int dequeue(struct Node **front);
void display(struct Node *front);

void enqueue(struct Node **front, struct Node **rear, int value) {
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

int dequeue(struct Node **front) {
    int value = -1;
    struct Node *temp;

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

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    printf("Deleted value: %d\n", dequeue(&front));

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);

    display(front);

    return 0;
}
