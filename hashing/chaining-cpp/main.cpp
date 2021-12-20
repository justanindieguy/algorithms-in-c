#include <iostream>
#include "Hashtable.h"
using namespace std;

int main()
{
    int nums[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int totalElements = sizeof(nums) / sizeof(nums[0]);
    HashTable ht;
    for (int i = 0; i < totalElements; i++)
    {
        ht.insert(nums[i]);
    }

    cout << "Successful Search" << endl;
    int key = 6;
    int value = ht.search(key);
    cout << "Key: " << key << ", Value: " << value << endl;

    cout << "Unsuccessful Search" << endl;
    key = 95;
    value = ht.search(key);
    cout << "Key: " << key << ", Value: " << value << endl;

    return 0;
}
