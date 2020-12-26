#include <stdio.h>
#include <stdlib.h>

int fact(int n);
int nCr(int n, int r);
int rnCr(int n, int r);

int fact(int n) {
    int i, factorial = 1;
    for (i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int nCr(int n, int r) {
    int num, dem;
    num = fact(n);
    dem = fact(r) * fact(n - r);
    return num / dem;
}

int rnCr(int n, int r) {

    if (r == 0 || r == n)
        return 1;
    return rnCr(n - 1, r - 1) + rnCr(n - 1, r);

}

int main(void) {
    printf("The no. of combinations is: %d\n", rnCr(4, 2));
    return 0;
}
