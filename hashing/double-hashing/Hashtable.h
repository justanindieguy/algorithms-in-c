#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
public:
    void insert(int key);
    int search(int key);

protected:
private:
    int ht[10] = {0};
    int hash(int key);
    int primeHash(int key);
    int doubleHash(int key);
};

#endif
