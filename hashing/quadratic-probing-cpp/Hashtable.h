#ifndef Hashtable_h
#define Hashtable_h
#define SIZE 10

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

int HashTable::hash(int key)
{
    return key % SIZE;
}

int HashTable::quadraticProbe(int key)
{
    int idx = hash(key);
    int i = 0;

    while (ht[(idx + i * i) % SIZE] != 0)
        i++;

    return (idx + i * i) % SIZE;
}

void HashTable::insert(int key)
{
    int idx = hash(key);

    if (ht[idx] != 0)
        idx = quadraticProbe(idx);

    ht[idx] = key;
}

int HashTable::search(int key)
{
    int idx = hash(key);
    int i = 0;

    while (ht[(idx + i * i) % SIZE] != key)
    {
        i++;
        if (ht[(idx + i * i) % SIZE] == 0)
            return -1;
    }

    return (idx + i * i) % SIZE;
}

#endif
