#pragma once

#include <iostream>
#include "Node.h"

class Stack {
private:
    Node **data;
    int size;    
    int top;

public:
    Stack() {
        top = -1;
        size = 10;
        data = new Node * [size];
    }

    Stack(int size) {
        top = -1;
        this->size = size;
        data = new Node * [size];
    }

    void push(Node *address);
    Node *pop();
    int isEmpty();
};

void Stack::push(Node *address) {
    if (top == size - 1) {
        std::cout << "Stack overflow." << std::endl;
    } else {
        top++;
        data[top] = address;
    }
}

Node *Stack::pop() {
    Node *address = NULL;

    if (top == -1) {
        std::cout << "Stack underflow." << std::endl;
    } else {
        address = data[top];
        top--;
    }

    return address;
}

int Stack::isEmpty() {
    return top == -1;
}
