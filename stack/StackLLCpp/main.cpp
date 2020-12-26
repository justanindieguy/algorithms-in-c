#include <iostream>

class Node {

public:
    int data;
    Node *next;
};

class Stack {

private:
    Node *top;

public:

    Stack() {
        top = NULL;
    }

    void push(int value);
    int pop();
    void display();
};

void Stack::push(int value) {

    Node *temp = new Node;
    if (temp == NULL) {
        std::cout << "Stack overflow." << std::endl;
    } else {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
}

int Stack::pop() {

    int value = -1;
    Node *aux;

    if (top == NULL) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        aux = top;
        value = top->data;
        top = top->next;
        delete(aux);
    }

    return value;
}

void Stack::display() {

    Node *aux = top;

    while (aux != NULL) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

int main() {

    Stack newStack;

    newStack.push(10);
    newStack.push(20);
    newStack.push(30);

    std::cout << "Stack:" << std::endl;
    newStack.display();

    std::cout << "Pop: " << newStack.pop() << std::endl;

    return 0;
}
