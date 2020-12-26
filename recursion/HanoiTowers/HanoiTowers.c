#include <stdio.h>
#include <stdlib.h>

void towersOfHanoi(int nDisk, int a, int b, int c) {
    if (nDisk > 0) {
        towersOfHanoi(nDisk - 1, a, c, b);
        printf("(%d, %d)\n", a, c);
        towersOfHanoi(nDisk - 1, b, a, c);
    }
}

int main(void) {
    towersOfHanoi(3, 1, 2, 3);
    return 0;
}
