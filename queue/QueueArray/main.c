#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *data;
};

void create(struct Queue *newQueue, int size) {
    newQueue->size = size;
    newQueue->front = newQueue->rear = -1;
    newQueue->data = malloc(newQueue->size * sizeof(int));
}

void enqueue(struct Queue *queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full.");
    } else {
        queue->rear++;
        queue->data[queue->rear] = value;
    }
}

int dequeue(struct Queue *queue) {
    int value = -1;

    if (queue->front == queue->rear) {
        printf("Queue is empty.");
    } else {
        queue->front++;
        value = queue->data[queue->front];
    }

    return value;
}

void display(struct Queue queue) {
    int i;

    for (i = queue.front + 1; i <= queue.rear; i++) {
        printf("%d ", queue.data[i]);
    }

    printf("\n");
}

int main() {
    struct Queue queue;
    create(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(queue);

    printf("Deleted value: %d", dequeue(&queue));

    return 0;
}
