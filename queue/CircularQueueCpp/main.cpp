#include <iostream>

class Queue {
private:
    int front;
    int rear;
    int size;
    int *data;

public:
    Queue() {
        front = rear = 0;
        size = 10;
        data = new int[size];
    }

    Queue(int size) {
        front = rear = 0;
        this->size = size;
        data = new int[this->size];
    }

    void enqueue(int value);
    int dequeue();
    void display();
};

void Queue::enqueue(int value) {
    if ((rear + 1) % size == front) {
        std::cout << "Queue is full." << std::endl;
    } else {
        rear = (rear + 1) % size;
        data[rear] = value;
    }
}

int Queue::dequeue() {
    int value = -1;

    if (front == rear) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        front = (front + 1) % size;
        value = data[front];
    }

    return value;
}

void Queue::display() {
    int i = front + 1;

    do {
        std::cout << data[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);

    std::cout << std::endl;
}

int main() {
    Queue myQueue(5);

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    myQueue.display();

    return 0;
}