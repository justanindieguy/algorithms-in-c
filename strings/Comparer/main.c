#include <stdio.h>
#include <stdlib.h>

/* -------------- PROTOTYPES -------------- */
void compare(char first[], char second[]);
int comparePalindrome(char first[], char second[]);
void checkPalindrome(char string[]);
char* reverse(char string[]);
int getSize(char string[]);
int getLength(char string[]);

/* -------------- FUNCTIONS -------------- */
void compare(char first[], char second[]) {
    int i, j;

    for (i = 0, j = 0; first[i] != '\0' && second[j] != '\0'; i++, j++) {
        if (first[i] != second[j]) {
            break;
        }
    }

    if (first[i] == second[j]) {
        printf("Both Strings are equals.\n");
    } else if (first[i] < second[j]) {
        printf("First String is smaller.\n");
    } else {
        printf("First String is greater.\n");
    }
}

int comparePalindrome(char first[], char second[]) {
    int i, j;

    for (i = 0, j = 0; first[i] != '\0' && second[i] != '\0'; i++, j++) {
        if (first[i] != second[i]) {
            break;
        }
    }

    if (first[i] == second[j]) {
        return 1;
    } else {
        return 0;
    }
}

void checkPalindrome(char string[]) {
    int i, j;
    int length = getLength(string);

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            break;
        }
    }

    if (string[i] == string[j]) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}

char* reverse(char string[]) {
    int size = getSize(string);
    char *reversed = (char*)malloc(size * sizeof(char));
    int i, j;

    for (i = 0; string[i] != '\0'; i++) {}
    i--;

    for (j = 0; i >= 0; i--, j++) {
        reversed[j] = string[i];
    }
    reversed[j] = '\0';

    return reversed;
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

/* -------------- MAIN FUNCTION -------------- */
int main() {
    char string[] = "madam";
    checkPalindrome(string);

    return 0;
}
