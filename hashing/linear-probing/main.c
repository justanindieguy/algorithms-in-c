#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int probe(int hashTable[], int key)
{
    int i = 0;
    int idx = hash(key);

    while (hashTable[(idx + i) % SIZE] != 0)
        i++;

    return (idx + i) % SIZE;
}

void insert(int hashTable[], int key)
{
    int idx = hash(key);

    if (hashTable[idx] != 0)
        idx = probe(hashTable, key);

    hashTable[idx] = key;
}

int search(int hashTable[], int key)
{
    int i = 0;
    int idx = hash(key);

    while (hashTable[(idx + i) % SIZE] != key)
    {
        if (hashTable[(idx + i) % SIZE] == 0)
            return -1;
        i++;
    }

    return (idx + i) % SIZE;
}

int main()
{
    int hashTable[10] = {0};

    insert(hashTable, 12);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 26);

    printf("\nKey found at index: %d\n", search(hashTable, 26));
    return 0;
}
