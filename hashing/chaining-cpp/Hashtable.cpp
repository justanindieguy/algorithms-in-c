#include "Hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable()
{
    hashTable = new Node *[10];
    for (int i = 0; i < 10; i++)
        hashTable[i] = nullptr;
}

int HashTable::hash(int key)
{
    return key % 10;
}

void HashTable::insert(int key)
{
    int idx = hash(key);
    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = nullptr;

    // Case: No nodes in the linked list
    if (hashTable[idx] == nullptr)
    {
        hashTable[idx] = newNode;
    }
    else
    {
        Node *front = hashTable[idx];
        Node *rear = hashTable[idx];

        // Traverse to find insert position
        while (front && front->data < key)
        {
            rear = front;
            front = front->next;
        }

        // Case: insert position is first
        if (rear == hashTable[idx])
        {
            newNode->next = hashTable[idx];
            hashTable[idx] = newNode;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
        }
    }
}

void HashTable::traverse(int key)
{
    int idx = hash(key);
    Node *aux = hashTable[idx];

    if (!aux)
    {
        cout << "There are no nodes at this idx" << endl;
        return;
    }

    while (aux)
    {
        cout << aux->data << ", ";
        aux = aux->next;
    }

    cout << endl;
}

int HashTable::search(int key)
{
    int idx = hash(key);
    Node *aux = hashTable[idx];

    while (aux)
    {
        if (aux->data == key)
            return aux->data;
        aux = aux->next;
    }

    return -1;
}

HashTable::~HashTable()
{
    for (int i = 0; i < 10; i++)
    {
        Node *aux = hashTable[i];
        while (hashTable[i])
        {
            hashTable[i] = hashTable[i]->next;
            delete aux;
            aux = hashTable[i];
        }
    }

    delete[] hashTable;
}
