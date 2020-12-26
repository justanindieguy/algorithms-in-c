#include <stdio.h>
#include <stdlib.h>

int validate(char *name) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (!(name[i] >= 65 && name[i] <= 90) &&
            !(name[i] >= 97 && name[i] <= 122) &&
            !(name[i] >= 48 && name[i] <= 57)) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int result;
    char string[] = "Anie?21";

    if (validate(string)) {
        printf("The String is valid.\n");
    } else {
        printf("That's not a valid String.\n");
    }

    return 0;
}
