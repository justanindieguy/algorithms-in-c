#ifndef HASHTABLE_H
#define HASHTABLE_H
#define SIZE 10

class HashTable
{
public:
    void insert(int key);
    int search(int key);

private:
    int hashTable[10] = {0};
    int hash(int key);
    int linearProbe(int key);
};

#endif
