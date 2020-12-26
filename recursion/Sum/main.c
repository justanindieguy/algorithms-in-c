#include <stdio.h>
#include <stdlib.h>

int sum(int n) {
    return n * (n + 1) / 2;
}

int recursive_sum(int n) {
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

int iterative_sum(int n) {
    int i, sum = 0;

    for(i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

int main() {

    int result, n = 5;

    result = recursive_sum(n);
    printf("The result is: %d", result);

    return 0;

}
