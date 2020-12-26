#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *polyOne = NULL, *polyTwo = NULL;

void create();
void createTwo();
void display(struct Node *polynomial);
long evaluate(struct Node *polynomial, int x);
struct Node* add(struct Node *firstPoly, struct Node *secondPoly);

void create() {
    
    struct Node *temp;
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    int i, num;

    printf("Enter number of terms: ");
    scanf_s("%d", &num);

    printf("Enter each term with coefficient and exponent.\n");
    for (i = 0; i < num; i++) {

        temp = (struct Node *)malloc(sizeof(struct Node));

        printf("Term no. %d: ", i + 1);
        scanf_s("%d%d", &temp->coeff, &temp->exp);
        temp->next = NULL;

        if (polyOne == NULL) {
            polyOne = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
}

void createTwo() {

    struct Node *temp;
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    int i, num;

    printf("Enter number of terms: ");
    scanf_s("%d", &num);

    printf("Enter each term with coefficient and exponent.\n");
    for (i = 0; i < num; i++) {

        temp = (struct Node *)malloc(sizeof(struct Node));

        printf("Term no. %d: ", i + 1);
        scanf_s("%d%d", &temp->coeff, &temp->exp);
        temp->next = NULL;

        if (polyTwo == NULL) {
            polyTwo = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
}

void display(struct Node *polynomial) {

    while (polynomial != NULL) {
        
        if (polynomial->next != NULL) {
            
            if (polynomial->exp == 0) {
                printf("%d + ", polynomial->coeff);
            } else {
                printf("%dx^%d + ", polynomial->coeff, polynomial->exp);
            }

        } else {

            if (polynomial->exp == 0) {
                printf("%d", polynomial->coeff);
            } else {
                printf("%dx^%d", polynomial->coeff, polynomial->exp);
            }

        }

        polynomial = polynomial->next;
    }

    printf("\n");
}

long evaluate(struct Node *polynomial, int x) {

    long result = 0;

    while (polynomial != NULL) {

        result += polynomial->coeff * pow(x, polynomial->exp);
        polynomial = polynomial->next;
    }

    return result;
}

struct Node* add(struct Node *firstPoly, struct Node *secondPoly) {

    struct Node *addition = NULL;
    struct Node *aux;
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));

    while (firstPoly != NULL && secondPoly != NULL) {

        aux = (struct Node *)malloc(sizeof(struct Node));
        aux->next = NULL;

        if (firstPoly->exp > secondPoly->exp) {

            aux->coeff = firstPoly->coeff;
            aux->exp = firstPoly->exp;

            if (addition == NULL) {
                addition = last = aux;
            } else {
                last->next = aux;
                last = aux;
            }

            firstPoly = firstPoly->next;

        } else if (firstPoly->exp < secondPoly->exp) {

            aux->coeff = secondPoly->coeff;
            aux->exp = secondPoly->exp;

            if (addition == NULL) {
                addition = last = aux;
            } else {
                last->next = aux;
                last = aux;
            }

            secondPoly = secondPoly->next;

        } else {

            aux->coeff = firstPoly->coeff + secondPoly->coeff;
            aux->exp = firstPoly->exp;

            if (addition == NULL) {
                addition = last = aux;
            } else {
                last->next = aux;
                last = aux;
            }

            firstPoly = firstPoly->next;
            secondPoly = secondPoly->next;
        }
    }

    while (firstPoly != NULL) {

        aux = (struct Node *)malloc(sizeof(struct Node));
        aux->coeff = firstPoly->coeff;
        aux->exp = firstPoly->exp;
        aux->next = NULL;

        if (addition == NULL) {
            addition = last = aux;
        } else {
            last->next = aux;
            last = aux;
        }

        firstPoly = firstPoly->next;
    }

    while (secondPoly != NULL) {

        aux = (struct Node *)malloc(sizeof(struct Node));
        aux->coeff = secondPoly->coeff;
        aux->exp = secondPoly->exp;
        aux->next = NULL;

        if (addition == NULL) {
            addition = last = aux;
        } else {
            last->next = aux;
            last = aux;
        }

        secondPoly = secondPoly->next;
    }

    return addition;
}

int main() {

    struct Node *addition;
    
    printf("First Polynomial:\n");
    create();

    printf("\nSecond Polynomial:\n");
    createTwo();

    addition = add(polyOne, polyTwo);

    printf("\nFirst Polynomial:\n");
    display(polyOne);

    printf("\nSecond Polynomial:\n");
    display(polyTwo);

    printf("\nAddition Polynomial:\n");
    display(addition);

    return 0;
}
