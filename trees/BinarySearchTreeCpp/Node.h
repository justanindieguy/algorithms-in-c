#pragma once
#include <iostream>

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node(int data) {
        this->data = data;
        lchild = rchild = nullptr;
    }
};
