#include <iostream>
#include "Hashtable.h"

using namespace std;

int main()
{
    int nums[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int numOfElements = sizeof(nums) / sizeof(nums[0]);
    HashTable ht;

    for (int i = 0; i < numOfElements; i++)
        ht.insert(nums[i]);

    int idx = ht.search(25);
    cout << "Key found at: " << idx << endl;

    idx = ht.search(35);
    cout << "Key found at: " << idx << endl;

    return 0;
}
