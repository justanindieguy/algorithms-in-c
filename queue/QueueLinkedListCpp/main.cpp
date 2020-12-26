#include <iostream>

struct Node {
    int data;
    Node *next;
};

class Queue {
public:
    Node *front, *rear;

    Queue() {
        front = rear = NULL;
    }

    ~Queue() {
        while (front) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }

    void enqueue(int value);
    int dequeue();
    void display();
};

void Queue::enqueue(int value) {
    Node *temp = new Node;

    if (temp == NULL) {
        std::cout << "Queue is full." << std::endl;
        return;
    } else {
        temp->data = value;
        temp->next = NULL;

        if (front == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
}

int Queue::dequeue() {
    int value = -1;
    Node *temp;

    if (front == NULL) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        value = front->data;
        temp = front;
        front = front->next;
        delete temp;
    }

    return value;
}

void Queue::display() {
    Node *aux = front;

    while (aux) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    std::cout << "Deleted element: " << myQueue.dequeue() << std::endl;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    return 0;
}