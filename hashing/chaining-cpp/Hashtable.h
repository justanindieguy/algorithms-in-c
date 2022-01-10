#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"

class HashTable
{
public:
    Node **hashTable;
    HashTable();
    int hash(int key);
    void insert(int key);
    void traverse(int key);
    int search(int key);
    ~HashTable();
};

#endif
