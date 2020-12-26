#include "LinkedList.h"

#pragma once
class Sparse {
public:
    int columns;
    int rows;
    int num;
    LinkedList **matrix;

    Sparse();
    Sparse(int columns, int rows, int num);
    void insert();
    void display();
    Sparse add(Sparse sparseTwo);
};

