#include <stdlib.h>
#include <stdio.h>

void findDuplicates(char word[]);
void findDuplicatesLower(char word[]);
void duplicatesBitwise(char word[]);

void duplicatesBitwise(char word[]) {
    long int i, hash = 0, x = 0;

    for (i = 0; word[i] != '\0'; i++) {

        x = 1;
        x = x << (word[i] - 97);

        if ((x & hash) > 1) {
            printf("%c is duplicate.\n", word[i]);
        } else {
            hash = x | hash;
        }

    }
}

void findDuplicates(char word[]) {
    int i;
    int hash[122] = { 0 };

    for (i = 0; word[i] != '\0'; i++) {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)) {
            hash[word[i] - 65]++;
        }
    }

    for (i = 0; i < 122; i++) {
        if (hash[i] > 1) {
            printf("Char %c is appearing %d times.\n", i + 65, hash[i]);
        }
    }
}

void findDuplicatesLower(char word[]) {
    int i;
    int hash[26] = { 0 };

    for (i = 0; word[i] != '\0'; i++) {
        hash[word[i] - 97]++;
    }

    for (i = 0; i < 26; i++) {
        if (hash[i] > 1) {
            printf("Char %c is appearing %d times.\n", i + 97, hash[i]);
        }
    }
}

int main() {
    char word[] = "finding";

    duplicatesBitwise(word);

    return 0;
}
