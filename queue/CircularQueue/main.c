#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *data;
};

void create(struct Queue *newQueue, int size);
void enqueue(struct Queue *queue, int value);
int dequeue(struct Queue *queue);
void display(struct Queue queue);

void create(struct Queue *newQueue, int size) {
    newQueue->size = size;
    newQueue->front = newQueue->rear = 0;
    newQueue->data = malloc(newQueue->size * sizeof(int));
}

void enqueue(struct Queue *queue, int value) {
    if ((queue->rear + 1) % queue->size == queue->front) {
        printf("Queue is full.");
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->data[queue->rear] = value;
    }
}

int dequeue(struct Queue *queue) {
    int value = -1;

    if (queue->front == queue->rear) {
        printf("Queue is empty.");
    } else {
        queue->front = (queue->front + 1) % queue->size;
        value = queue->data[queue->front];
    }

    return value;
}

void display(struct Queue queue) {
    int i = queue.front + 1;

    do {
        printf("%d ", queue.data[i]);
        i = (i + 1) % queue.size;
    } while (i != (queue.rear + 1) % queue.size);

    printf("\n");
}

int main() {
    struct Queue queue;
    create(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    display(queue);

    return 0;
}
