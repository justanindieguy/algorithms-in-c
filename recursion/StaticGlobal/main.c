#include <stdio.h>
#include <stdlib.h>

int fun(int n) {

    static int x = 0;

    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }

    return 0;
}

int main() {

    int result;
    result = fun(5);
    printf("The result is: %d\n", result);

    return 0;
}
