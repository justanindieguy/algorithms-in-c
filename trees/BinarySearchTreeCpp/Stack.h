#pragma once
#include <iostream>
#include "Node.h"

class StackNode {
public:
    Node *address;
    StackNode *next;

    StackNode(Node *address) {
        this->address = address;
        next = nullptr;
    }

    StackNode(Node *address, StackNode *next) {
        this->address = address;
        this->next = next;
    }
};

class Stack {
private:
    StackNode *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(Node *address);
    Node *pop();
    Node *getTop();
    int isEmpty();
};

void Stack::push(Node *address) {
    StackNode *temp = new StackNode(address);

    if (temp == NULL) {
        std::cout << "Stack overflow." << std::endl;
    } else {
        temp->next = top;
        top = temp;
    }
}

Node *Stack::pop() {
    Node *address = nullptr;
    StackNode *aux;

    if (top == nullptr) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        aux = top;
        address = top->address;
        top = top->next;
        delete aux;
    }

    return address;
}

Node *Stack::getTop() {
    Node *address = nullptr;

    if (top == nullptr) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        address = top->address;
    }

    return address;
}

int Stack::isEmpty() {
    return top == nullptr;
}
