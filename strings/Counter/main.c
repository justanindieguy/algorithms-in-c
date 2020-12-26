#include <stdio.h>
#include <stdlib.h>

void vowelCounter(char string[]);
void wordCounter(char string[]);

void vowelCounter(char string[]) {

    int i, vowelCounter = 0, consonantCounter = 0;

    for (i = 0; string[i] != '\0'; i++) {

        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i'
            || string[i] == 'o' || string[i] == 'u' || string[i] == 'A'
            || string[i] == 'E' || string[i] == 'I' || string[i] == 'O'
            || string[i] == 'U') {

            vowelCounter++;

        } else if ((string[i] >= 65 && string[i] <= 90)
            || (string[i] >= 97 && string[i] <= 122)) {

            consonantCounter++;

        }

    }

    printf("Number of vowels: %d\n", vowelCounter);
    printf("Number of consonants: %d\n", consonantCounter);
}

void wordCounter(char string[]) {

    int i, nWords = 0;

    for (i = 0; string[i] != '\0'; i++) {

        if (string[i] == ' ' && string[i - 1] != ' ') {
            nWords++;
        }

    }

    nWords++;
    printf("Number of words: %d\n", nWords);
}

int main() {

    char string[] = "How are you";

    vowelCounter(string);
    wordCounter(string);

    return 0;
}
