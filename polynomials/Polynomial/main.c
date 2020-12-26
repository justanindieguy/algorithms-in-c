#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term {
    int coeff;
    int exp;
};

struct Polynomial {
    int n;
    struct Term *terms;
};

void create(struct Polynomial *poly);
void display(struct Polynomial poly);
struct Polynomial* add(struct Polynomial polyOne, struct Polynomial polyTwo);
int evaluate(struct Polynomial poly, int x);

void create(struct Polynomial *poly) {

    int i;

    printf("Enter no. of terms: ");
    scanf_s("%d", &poly->n);
    poly->terms = (struct Term*)malloc(poly->n * sizeof(struct Term));

    printf("Enter terms:\n");
    for (i = 0; i < poly->n; i++) {
        scanf_s("%d%d", &poly->terms[i].coeff, &poly->terms[i].exp);
    }
    printf("\n");
}

void display(struct Polynomial poly) {

    int i;

    printf("The polynomial is:\n");
    for (i = 0; i < poly.n; i++) {

        if (i == poly.n - 1) {
            if (poly.terms[i].exp == 1) {
                printf("%dx", poly.terms[i].coeff);
            } else if (poly.terms[i].exp == 0) {
                printf("%d", poly.terms[i].coeff);
            } else {
                printf("%dx^%d", poly.terms[i].coeff, poly.terms[i].exp);
            }     
        } else {
            if (poly.terms[i].exp == 1) {
                printf("%dx + ", poly.terms[i].coeff);
            } else if (poly.terms[i].exp == 0) {
                printf("%d + ", poly.terms[i].coeff);
            } else {
                printf("%dx^%d + ", poly.terms[i].coeff, poly.terms[i].exp);
            }
        }
    }
    printf("\n");
}

struct Polynomial* add(struct Polynomial polyOne, struct Polynomial polyTwo) {

    int i, j, k;
    struct Polynomial *sum;
    i = j = k = 0;

    sum = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    sum->terms = (struct Term*)malloc((polyOne.n + polyTwo.n) * sizeof(struct Term));

    while (i < polyOne.n && j < polyTwo.n) {

        if (polyOne.terms[i].exp > polyTwo.terms[j].exp) {
            sum->terms[k++] = polyOne.terms[i++];
        } else if (polyOne.terms[i].exp < polyTwo.terms[j].exp) {
            sum->terms[k++] = polyTwo.terms[j++];
        } else {
            sum->terms[k].exp = polyOne.terms[i].exp;
            sum->terms[k++].coeff = polyOne.terms[i++].coeff + polyTwo.terms[j++].coeff;
        }
    }

    for (; i < polyOne.n; i++) {
        sum->terms[k++] = polyOne.terms[i];
    }

    for (; j < polyTwo.n; j++) {
        sum->terms[k++] = polyTwo.terms[j];
    }

    sum->n = k;

    return sum;
}

int evaluate(struct Polynomial poly, int x) {

    int i;
    int sum = 0;

    for (i = 0; i < poly.n; i++) {
        sum += poly.terms[i].coeff * pow(x, poly.terms[i].exp);
    }

    return sum;
}

int main() {

    struct Polynomial polyOne, polyTwo, *sumPoly;
    int sum;

    printf("First polynomial.\n");
    create(&polyOne);
    display(polyOne);
    printf("\n");

    printf("Second polynomial.\n");
    create(&polyTwo);
    display(polyTwo);
    printf("\n");

    printf("Sum polynomial.\n");
    sumPoly = add(polyOne, polyTwo);
    display(*sumPoly);
    printf("\n");

    return 0;
}
