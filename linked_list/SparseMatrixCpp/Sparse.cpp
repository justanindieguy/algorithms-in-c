#include <iostream>
#include "Sparse.h"

Sparse::Sparse() {
    this->columns = 0;
    this->rows = 0;
    this->num = 0;
    this->matrix = NULL;
}

Sparse::Sparse(int columns, int rows, int num) {
    this->columns = columns;
    this->rows = rows;
    this->num = num;
    this->matrix = new LinkedList*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new LinkedList;
    }
}

void Sparse::insert() {

    int column, row, value;

    std::cout << "Enter non-zero elements." << std::endl;
    for (int i = 0; i < num; i++) {
        std::cout << "Row | Column | Value: ";
        std::cin >> row >> column >> value;

        matrix[row]->append(column, value);
    }
}

void Sparse::display() {

    Node *aux;

    for (int i = 0; i < rows; i++) {

        aux = matrix[i]->first;

        for (int j = 0; j < columns; j++) {

            if (aux != NULL) {
                if (j == aux->col) {
                    std::cout << aux->value << " ";
                    aux = aux->next;
                } else {
                    std::cout << "0 ";
                }
            } else {
                std::cout << "0 ";
            }
        }

        std::cout << std::endl;
    }
}

Sparse Sparse::add(Sparse sparseTwo) {

    Node *p, *q;
    Sparse sparseSum(columns, rows, num + sparseTwo.num);

    for (int i = 0; i < sparseSum.rows; i++) {
        p = matrix[i]->first;
        q = sparseTwo.matrix[i]->first;

        while (p != NULL && q != NULL) {

            if (p->col < q->col) {
                sparseSum.matrix[i]->append(p->col, p->value);
                p = p->next;
            } else if (p->col > q->col) {
                sparseSum.matrix[i]->append(q->col, q->value);
                q = q->next;
            } else {
                sparseSum.matrix[i]->append(p->col, p->value + q->value);
                p = p->next;
                q = q->next;
            }
        }

        while (p != NULL) {
            sparseSum.matrix[i]->append(p->col, p->value);
            p = p->next;
        }

        while (q != NULL) {
            sparseSum.matrix[i]->append(q->col, q->value);
            q = q->next;
        }
    }

    return sparseSum;
}
