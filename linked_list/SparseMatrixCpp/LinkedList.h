#include "Node.h"

#pragma once
class LinkedList {
public:
    Node *first;

    LinkedList();
    ~LinkedList();
    void append(int col, int value);

private:
    Node* createNode(int col, int value);
};

