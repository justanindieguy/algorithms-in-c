#include <stdlib.h>
#include <stdio.h>

void checkAnagram(char first[], char second[]);
void checkAnagramTwo(char first[], char second[]);
int getLength(char string[]);

void checkAnagram(char first[], char second[]) {
    int i;
    int firstLength, secondLength;
    int hash[26] = { 0 };

    firstLength = getLength(first);
    secondLength = getLength(second);

    if (firstLength != secondLength) {
        printf("Not anagram.\n");
        return;
    } else {
        for (i = 0; first[i] != '\0'; i++) {
            hash[first[i] - 97]++;
        }

        for (i = 0; second[i] != '\0'; i++) {
            hash[second[i] - 97]--;
            if (hash[second[i] - 97] < 0) {
                printf("Not anagram.\n");
                break;
            }
        }

        if (second[i] == '\0') {
            printf("It's anagram.\n");
        }
    }
}

void checkAnagramTwo(char first[], char second[]) {
    int i, j;
    int firstLength, secondLength;

    firstLength = getLength(first);
    secondLength = getLength(second);

    if (firstLength != secondLength) {
        printf("Not anagram.\n");
        return;
    } else {
        for (i = 0; first[i] != '\0'; i++) {
            for (j = 0; second[j] != '\0'; j++) {
                if (first[i] == second[j]) {
                    break;
                }
            }
            if (first[i] != second[j]) {
                printf("Not anagram.\n");
                break;
            }
        }
        if (first[i] == '\0') {
            printf("It's anagram.\n");
        }
    }
}

int getLength(char string[]) {
    int i;

    for (i = 0; string[i] != '\0'; i++) {}

    return i;
}

int main() {
    char first[] = "decimal";
    char second[] = "medical";

    checkAnagramTwo(first, second);
}
