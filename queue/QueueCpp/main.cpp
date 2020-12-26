#include <iostream>

class Queue {
private:
    int front;
    int rear;
    int size;
    int *data;

public:
    Queue() {
        front = rear = -1;
        size = 10;
        data = new int[size];
    }

    Queue(int size) {
        front = rear = -1;
        this->size = size;
        data = new int[this->size];
    }

    void enqueue(int value);
    int dequeue();
    void display();
    int isEmpty();
};

void Queue::enqueue(int value) {
    if (rear == size - 1) {
        std::cout << "Queue is full." << std::endl;
    } else {
        rear++;
        data[rear] = value;
    }
}

int Queue::dequeue() {
    int value = -1;

    if (front == rear) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        front++;
        value = data[front];
    }

    return value;
}

void Queue::display() {
    for (int i = front + 1; i <= rear; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}

int Queue::isEmpty() {
    int isEmpty = 0;

    if (front == rear) {
        isEmpty = 1;
    }

    return isEmpty;
}

int main() {
    Queue myQueue(5);

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    std::cout << "Deleted element: " << myQueue.dequeue() << std::endl;

    myQueue.display();

    return 0;
}
