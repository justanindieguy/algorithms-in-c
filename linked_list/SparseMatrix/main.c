#include <stdlib.h>
#include <stdio.h>

struct Node {
    int col;
    int value;
    struct Node *next;
};

struct Sparse {
    int rows;
    int columns;
    int num;
    struct Node **matrix;
};

/* --------------- PROTOTYPES --------------- */
struct Sparse* create(int rows, int columns, int num);
struct Node* createNode(int column, int value);
struct Sparse* add(struct Sparse *sparseOne, struct Sparse *sparTwo);
void display(struct Sparse *sparseMatrix);

/* --------------- FUNCTIONS --------------- */
struct Sparse* create(int columns, int rows, int num) {

    int i;
    int row, column, value;
    struct Node *newNode, *lastNode = (struct Node *)malloc(sizeof(struct Node));

    struct Sparse *newMatrix = (struct Sparse *)malloc(sizeof(struct Sparse));
    newMatrix->columns = columns;
    newMatrix->rows = rows;
    newMatrix->num = num;
    newMatrix->matrix = (struct Node *)malloc(rows * sizeof(struct Node));

    for (i = 0; i < rows; i++) {
        newMatrix->matrix[i] = NULL;
    }

    printf("Enter non-zero elements.\n");
    for (i = 0; i < num; i++) {

        printf("Column row value: ");
        scanf_s("%d%d%d", &column, &row, &value);

        newNode = createNode(column, value);

        if (newMatrix->matrix[row] == NULL) {

            newMatrix->matrix[row] = newNode;
            lastNode = newNode;

        } else {

            lastNode = newMatrix->matrix[row];

            while (lastNode->next != NULL) {
                lastNode = lastNode->next;
            }

            lastNode->next = newNode;
            lastNode = newNode;
        }
    }

    return newMatrix;
}

struct Node* createNode(int column, int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->col = column;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

struct Sparse* add(struct Sparse *sparseOne, struct Sparse *sparseTwo) {

    int i;
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    struct Node *newNode;
    struct Node *p, *q;

    struct Sparse *sparseSum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sparseSum->columns = sparseOne->columns;
    sparseSum->rows = sparseOne->rows;
    sparseSum->num = sparseOne->num = sparseTwo->num;
    sparseSum->matrix = (struct Node *)malloc(sparseSum->rows * sizeof(struct Node *));

    for (i = 0; i < sparseSum->rows; i++) {
        sparseSum->matrix[i] = NULL;
    }

    for (i = 0; i < sparseSum->rows; i++) {

        p = sparseOne->matrix[i];
        q = sparseTwo->matrix[i];

        while (p != NULL && q != NULL) {

            if (p->col < q->col) {

                if (sparseSum->matrix[i] == NULL) {

                    sparseSum->matrix[i] = p;
                    last = p;
                    p = p->next;
                    last->next = NULL;

                } else {

                    last->next = p;
                    last = p;
                    p = p->next;
                    last->next = NULL;
                }

            } else if (p->col > q->col) {

                if (sparseSum->matrix[i] == NULL) {

                    sparseSum->matrix[i] = q;
                    last = q;
                    q = q->next;
                    last->next = NULL;

                } else {

                    last->next = q;
                    last = q;
                    q = q->next;
                    last->next = NULL;
                }

            } else {

                newNode = createNode(p->col, p->value + q->value);

                if (sparseSum->matrix[i] == NULL) {
                    
                    sparseSum->matrix[i] = newNode;
                    last = newNode;
                    p = p->next;
                    q = q->next;

                } else {

                    last->next = newNode;
                    last = newNode;
                    p = p->next;
                    q = q->next;
                }
            }
        }

        while (p != NULL) {

            if (sparseSum->matrix[i] == NULL) {
                sparseSum->matrix[i] = p;
                last = p;
                p = p->next;
                last->next = NULL;
            } else {
                last->next = p;
                last = p;
                p = p->next;
                last->next = NULL;
            }
        }

        while (q != NULL) {

            if (sparseSum->matrix[i] == NULL) {
                sparseSum->matrix[i] = q;
                last = q;
                q = q->next;
                last->next = NULL;
            } else {
                last->next = q;
                last = q;
                q = q->next;
                last->next = q;
            }
        }

    }

    return sparseSum;
}

void display(struct Sparse *sparseMatrix) {

    int i, j;
    struct Node *aux;

    for (i = 0; i < sparseMatrix->columns; i++) {

        aux = sparseMatrix->matrix[i];
        for (j = 0; j < sparseMatrix->rows; j++) {

            if (aux != NULL) {

                if (j == aux->col) {
                    printf("%d ", aux->value);
                    aux = aux->next;
                } else {
                    printf("0 ");
                }

            } else {
                printf("0 ");
            }

        }
        printf("\n");
    }
}

/* --------------- MAIN --------------- */
int main() {

    struct Sparse *sparseOne, *sparseTwo, *sum;
    
    printf("Create sparse one.\n\n");
    sparseOne = create(4, 4, 6);

    printf("Create sparse two.\n\n");
    sparseTwo = create(4, 4, 4);

    printf("\nMatrix one:\n");
    display(sparseOne);

    printf("\nMatrix two:\n");
    display(sparseTwo);

    sum = add(sparseOne, sparseTwo);
    printf("\nSum matrix:\n");
    display(sum);

    return 0;
}
