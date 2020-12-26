#pragma once

#include <iostream>
#include "Node.h"

class Queue {
private:
    int front;
    int rear;
    int size;
    Node **data;

public:
    Queue() {
        front = rear = 0;
        size = 10;
        data = new Node *[size];
    }

    Queue(int size) {
        front = rear = 0;
        this->size = size;
        data = new Node *[this->size];
    }

    void enqueue(Node *address);
    Node * dequeue();
    int isEmpty();
};

void Queue::enqueue(Node *address) {
    if ((rear + 1) % size == front) {
        std::cout << "Queue is full." << std::endl;
    } else {
        rear = (rear + 1) % size;
        data[rear] = address;
    }
}

Node * Queue::dequeue() {
    Node *address = NULL;

    if (rear == front) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        front = (front + 1) % size;
        address = data[front];
    }

    return address;
}

int Queue::isEmpty() {
    return front == rear;
}
