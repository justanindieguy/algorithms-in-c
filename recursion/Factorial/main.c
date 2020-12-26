#include <stdio.h>
#include <stdlib.h>

int iterativeFact(int n) {
    int i, fact = 1;

    for(i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int recursiveFact(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return recursiveFact(n - 1) * n;
}

int main() {
    int n = 5, result = 0;

    result = recursiveFact(n);
    printf("The result is: %d", result);

    return 0;
}
