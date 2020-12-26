#include <iostream>

class Node {

public:
    int data;
    Node *next;
};

class LinkedList {

private:
    Node *first;

public:

    LinkedList() {
        first = NULL;
    }

    LinkedList(int array[], int length);
    ~LinkedList();

    void display();
    void insert(int index, int value);
    int remove(int index);
    int length();
};

LinkedList::LinkedList(int array[], int length) {

    Node *temp, *last;

    first = new Node;
    first->data = array[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < length; i++) {
        temp = new Node;
        temp->data = array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

LinkedList::~LinkedList() {

    Node *currentNode = first;

    while (first != NULL) {
        first = first->next;
        delete currentNode;
        currentNode = first;
    }
}

void LinkedList::display() {

    Node *currentNode = first;

    while (currentNode != NULL) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

int LinkedList::length() {

    Node *currentNode = first;
    int len = 0;

    while (currentNode != NULL) {
        len++;
        currentNode = currentNode->next;
    }

    return len;
}

void LinkedList::insert(int index, int value) {

    Node *currentNode = first, *temp;

    if (index < 0 || index > length()) {
        return;
    }

    temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (index == 0) {
        temp->next = first;
        first = temp;
    } else {

        for (int i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }
        
        temp->next = currentNode->next;
        currentNode->next = temp;
    }
}

int LinkedList::remove(int index) {

    Node *currentNode = first;
    Node *aux = NULL;
    int value = -1;

    if (index < 1 || index > length()) {
        return value;
    }

    if (index == 1) {
        aux = first;
        value = first->data;
        first = first->next;
        delete aux;
        return value;
    } else {

        for (int i = 0; i < index; i++) {
            aux = currentNode;
            currentNode = currentNode->next;
        }

        aux->next = currentNode->next;
        value = currentNode->data;
        delete currentNode;
        return value;
    }
}

int main() {

    int array[] = { 10, 20, 30, 40, 50 };
    LinkedList list(array, sizeof(array) / sizeof(array[0]));

    list.display();

    return 0;
}
