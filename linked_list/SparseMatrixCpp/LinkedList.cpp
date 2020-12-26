#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    first = NULL;
}

LinkedList::~LinkedList() {
    Node *currentNode = first;

    while (first != NULL) {
        first = first->next;
        delete currentNode;
        currentNode = first;
    }
}

Node* LinkedList::createNode(int col, int value) {
    Node *createdNode = new Node;

    createdNode->col = col;
    createdNode->value = value;
    createdNode->next = NULL;

    return createdNode;
}

void LinkedList::append(int col, int value) {
    Node *newNode, *lastNode;

    newNode = createNode(col, value);

    if (first == NULL) {
        first = newNode;
    } else {
        lastNode = first;

        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }
}
