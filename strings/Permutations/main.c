#include <stdio.h>
#include <stdlib.h>

void swap(char* string, int posOne, int posTwo);
void getPermutations(char string[], int k);

void swap(char* string, int posOne, int posTwo) {
    int temp;
    temp = string[posOne];
    string[posOne] = string[posTwo];
    string[posTwo] = temp;
}

void getPermutations(char string[], int k) {
    static int hash[10] = { 0 };
    static char res[10];
    int i;

    if (string[k] == '\0') {
        res[k] = '\0';
        printf("%s\n", res);
    } else {
        for (i = 0; string[i] != '\0'; i++) {
            if (hash[i] == 0) {
                res[k] = string[i];
                hash[i] = 1;
                getPermutations(string, k + 1);
                hash[i] = 0;
            }
        }
    }
}

void permutationsSwap(char* string, int low, int high) {
    int i;
    if (low == high) {
        printf("%s\n", string);
    } else {
        for (i = low; i <= high; i++) {
            swap(string, low, i);
            permutationsSwap(string, low + 1, high);
            swap(string, low, i);
        }
    }
}

int main() {
    char string[] = "ABC";
    permutationsSwap(string, 0, 2);

    return 0;
}
