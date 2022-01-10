#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
public:
    void insert(int key);
    int search(int key);

private:
    int ht[10] = {0};
    int hash(int key);
    int quadraticProbe(int key);
};

#endif
