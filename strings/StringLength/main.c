#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i;
    char *someString = "welcome";

    for (i = 0; someString[i] != '\0'; i++) {}

    printf("The length is: %d", i);

    return 0;
}
