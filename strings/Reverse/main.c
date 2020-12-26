#include <stdio.h>
#include <stdlib.h>

void reverseInPlace(char *string);
char* reverse(char string[], int length);
int getSize(char string[]);
int getLength(char string[]);

void reverseInPlace(char *string) {
    int i, j;
    char temp;

    for (j = 0; string[j] != '\0'; j++) {}
    j--;

    for (i = 0; i < j; i++, j--) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

char* reverse(char string[], int length) {
    int i, j;
    char* reverseString = (char*)malloc(length * sizeof(char));

    for (i = 0; string[i] != '\0'; i++) {}
    i--;

    for (j = 0; i >= 0; i--, j++) {
        reverseString[j] = string[i];
    }
    reverseString[j] = '\0';

    return reverseString;
}

int getSize(char string[]) {
    int i;
    for (i = 0; string[i] != '\0'; i++) {}
    return i + 1;
}

int getLength(char string[]) {
    int i;
    for (i = 0; string[i] != '\0'; i++) {}
    return i;
}

int main() {
    char string[] = "Python";

    reverseInPlace(string);
    printf("The reversed String is: %s\n", string);

    return 0;
}
