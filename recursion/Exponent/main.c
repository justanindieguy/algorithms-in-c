#include <stdio.h>
#include <stdlib.h>

int power(int m, int n) {
    if(n == 0)
        return 1;
    return power(m, n - 1) * m;
}

int power1(int m, int n) {
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return power1(m * m, n / 2);
    return m * power1(m * m, (n - 1) / 2);
}

int iPower(int m, int n) {
    int i, power = 1;

    for(i = 1; i <= n; i++) {
        power *= m;
    }

    return power;
}

int main() {
    int m = 2, n = 8, result = 0;

    result = power1(m, n);
    printf("The result is: %d", result);

    return 0;
}
