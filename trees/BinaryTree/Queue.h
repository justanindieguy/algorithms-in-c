#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **data;
};

void createQueue(struct Queue *newQueue, int size) {
    newQueue->size = size;
    newQueue->front = newQueue->rear = 0;
    newQueue->data = (struct Node **) malloc(newQueue->size * sizeof(struct Node *));
}

void enqueue(struct Queue *queue, struct Node *address) {
    if ((queue->rear + 1) % queue->size == queue->front) {
        printf("Queue is full.");
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->data[queue->rear] = address;
    }
}

struct Node * dequeue(struct Queue *queue) {
    struct Node *address = NULL;

    if (queue->front == queue->rear) {
        printf("Queue is empty.");
    } else {
        queue->front = (queue->front + 1) % queue->size;
        address = queue->data[queue->front];
    }

    return address;
}

int isEmpty(struct Queue queue) {
    return queue.front == queue.rear;
}
