#include <stdio.h>
#include <stdlib.h>

void toggleCase(char *string);

void toggleCase(char *string) {

    int i;

    for (i = 0; string[i] != '\0'; i++) {

        if (string[i] >= 65 && string[i] <= 90) {
            string[i] += 32;
        } else if (string[i] >= 97 && string[i] <= 122) {
            string[i] -= 32;
        }

    }
}

int main() {

    char string[] = "welcome";

    toggleCase(&string);

    printf("%s", string);

    return 0;
}
