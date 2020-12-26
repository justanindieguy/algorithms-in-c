#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int *array;
    int n;
};

void set(struct Matrix *m, int i, int j, int x);
int get(struct Matrix m, int i, int j);
void display(struct Matrix m);

void set(struct Matrix *m, int i, int j, int x) {
    if (i >= j) {
        m->array[i * (i - 1) / 2 + j - 1] = x;
    }
}

int get(struct Matrix m, int i, int j) {
    if (i >= j) {
        return m.array[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

void display(struct Matrix m) {
    int i, j;
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            if (i >= j) {
                printf("%d ", m.array[(i * (i - 1) / 2) + j - 1]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int i, j, x;

    printf("Enter dimension: ");
    scanf_s("%d", &m.n);
    m.array = (int*)malloc((m.n * (m.n + 1) / 2) * sizeof(int));

    printf("Enter all elements.\n");
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            scanf_s("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\n\n");
    display(m);

    return 0;
}
