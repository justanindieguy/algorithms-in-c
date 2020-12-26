#include <iostream>
using namespace std;

class Array {

private:
    int *arr;
    int size;
    int length;

    void swap(int* firstElement, int* secondElement);

public:
    Array() {
        size = 10;
        length = 0;
        arr = new int[size];
    }

    Array(int size) {
        this->size = size;
        length = 0;
        arr = new int[this->size];
    }

    ~Array() {
        delete []arr;
    }

    int getLength();
    void display();
    void append(int x);
    void insert(int index, int x);
    int del(int index);
    int linearSearch(int key);
    int binarySearch(int key);
    int get(int index);
    void set(int index, int x);
    int maximum();
    int minimum();
    int sum();
    float avg();
    void reverse();
    void reverseTwo();
    void leftShift();
    void leftRotate();
    void insertSort(int x);
    int isSorted();
    void rearrange();
    Array* merge(Array *secondArr);
    Array* unionSorted(Array *secondArr);
    Array* intersection(Array *secondArr);
    Array* difference(Array *secondArr);
    Array* unsortedIntersection(Array *secondArr);
    Array* unsortedUnion(Array *secondArr);
    Array* unsortedDifference(Array *secondArr);
    int findMissingElementOne();
    int findMissingElementTwo();
    void findMissingElements();
    void findMissingElementsTwo();
    void findDuplicateElements();
    void findDuplicateHash();
    void findDuplicateUnsorted();
    void findPairSum(int k);
    void findPairSumHash(int k);
    void findPairSumSorted(int k);
    void findMaxMin();
};

int Array::getLength() {
    return length;
}

void Array::display() {

    int i;
    cout << "\nElements are:\n";
    for (i = 0; i < length; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << "\n";
}

void Array::append(int value) {

    if (length < size) {
        arr[length++] = value;
    }
}

void Array::insert(int index, int value) {

    int i;

    if (index >= 0 && index <= length) {

        for (i = length; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        length++;

    }
}

int Array::del(int index) {

    int x = 0;
    int i;

    if (index >= 0 && index <= length - 1) {

        x = arr[index];
        for (i = index; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        length--;

        return x;
    }
    return 0;
}

void Array::swap(int *firstElement, int *secondElement) {

    int temp;

    temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

int Array::linearSearch(int key) {

    int i;

    for (i = 0; i < length; i++) {
        if (key == arr[i]) {
            return i;
        }
    }
    return -1;
}

int Array::binarySearch(int key) {

    int low, mid, high;
    low = 0;
    high = length - 1;

    while (low <= high) {

        mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;

    }
    return -1;
}

int Array::get(int index) {

    if (index >= 0 && index < length)
        return arr[index];
    return -1;
}

void Array::set(int index, int value) {

    if (index >= 0 && index < length)
        arr[index] = value;
}

int Array::maximum() {

    int max = arr[0];
    int i;

    for (i = 1; i < length; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int Array::minimum() {

    int min = arr[0];
    int i;

    for (i = 1; i < length; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int Array::sum() {

    int total = 0;
    int i;

    for (i = 0; i < length; i++) {
        total += arr[i];
    }
    return total;
}

float Array::avg() {
    return (float)sum() / length;
}

void Array::reverse() {

    int *auxArr;
    int i, j;

    auxArr = new int[length];

    for (i = length - 1, j = 0; i >= 0; i--, j++)
        auxArr[j] = arr[i];
    for (i = 0; i < length; i++)
        arr[i] = auxArr[i];

    auxArr = NULL;
}

void Array::reverseTwo() {

    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
        swap(&arr[i], &arr[j]);
}

void Array::leftShift() {

    int i;

    for (i = 0; i < length; i++)
        arr[i] = arr[i + 1];

    arr[length - 1] = 0;
    length--;

}

void Array::leftRotate() {

    int i, temp;
    temp = arr[0];

    for (i = 0; i < length; i++)
        arr[i] = arr[i + 1];

    arr[length - 1] = temp;

}

void Array::insertSort(int value) {

    int i = length - 1;

    if (length == size)
        return;

    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = value;
    length++;
}

int Array::isSorted() {

    int i;

    for (i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1])
            return 0;
    }

    return 1;
}

void Array::rearrange() {

    int i, j;
    i = 0;
    j = length - 1;

    while (i < j) {

        while (arr[i] < 0) {
            i++;
        }

        while (arr[j] >= 0) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }

    }
}

Array* Array::merge(Array *secondArr) {

    int i = 0, j = 0, k = 0;
    Array *thirdArr = new Array(length + secondArr->length);

    while (i < length && j < secondArr->length) {

        if (arr[i] < secondArr->arr[j])
            thirdArr->arr[k++] = arr[i++];
        else
            thirdArr->arr[k++] = secondArr->arr[j++];

    }

    for (; i < length; i++)
        thirdArr->arr[k++] = arr[i];

    for (; j < secondArr->length; j++)
        thirdArr->arr[k++] = secondArr->arr[j];

    thirdArr->length = length + secondArr->length;
    thirdArr->size = 10;

    return thirdArr;
}

Array* Array::unionSorted(Array *secondArr) {

    int i = 0, j = 0, k = 0;
    Array *thirdArr = new Array(length + secondArr->length);

    while (i < length && j < secondArr->length) {

        if (arr[i] < secondArr->arr[j]) {
            thirdArr->arr[k++] = arr[i++];
        } else if (secondArr->arr[j] < arr[i]) {
            thirdArr->arr[k++] = secondArr->arr[j++];
        } else {
            thirdArr->arr[k++] = arr[i++];
            j++;
        }


    }

    for (; i < length; i++)
        thirdArr->arr[k++] = arr[i];

    for (; j < secondArr->length; j++)
        thirdArr->arr[k++] = secondArr->arr[j];

    thirdArr->length = k;
    thirdArr->size = 10;

    return thirdArr;
}

Array* Array::intersection(Array *secondArr) {

    int i = 0, j = 0, k = 0;
    Array* thirdArr = new Array(length + secondArr->length);

    while (i < length && j < secondArr->length) {

        if (arr[i] < secondArr->arr[j]) {
            i++;
        } else if (secondArr->arr[j] < arr[i]) {
            j++;
        } else if (arr[i] == secondArr->arr[j]) {
            thirdArr->arr[k++] = arr[i++];
            j++;
        }

    }

    thirdArr->length = k;
    thirdArr->size = 10;

    return thirdArr;
}

Array* Array::difference(Array *secondArr) {

    int i = 0, j = 0, k = 0;
    Array * thirdArr = new Array(length + secondArr->length);

    while (i < length && j < secondArr->length) {

        if (arr[i] < secondArr->arr[j]) {
            thirdArr->arr[k++] = arr[i++];
        } else if (secondArr->arr[j] < arr[i]) {
            j++;
        } else {
            i++;
            j++;
        }

    }

    for (; i < length; i++)
        thirdArr->arr[k++] = arr[i];

    thirdArr->length = k;
    thirdArr->size = 10;

    return thirdArr;
}

Array* Array::unsortedIntersection(Array *secondArr) {

    int i, j = 0;
    int search, result;
    Array* thirdArr = new Array(length + secondArr->length);

    for (i = 0; i < length; i++) {

        search = arr[i];
        result = secondArr->linearSearch(search);

        if (result != -1) {
            thirdArr->arr[j] = search;
            j++;
        }

    }

    thirdArr->length = j;
    thirdArr->size = 10;

    return thirdArr;
}

Array* Array::unsortedUnion(Array *secondArr) {

    int i, j = 0;
    int search, result;
    Array* thirdArr = new Array(length + secondArr->length);

    for (i = 0; i < length; i++) {

        thirdArr->arr[j] = arr[i];
        j++;

    }

    for (i = 0; i < secondArr->length; i++) {

        search = secondArr->arr[i];
        result = secondArr->linearSearch(search);

        if (result == -1) {
            thirdArr->arr[j] = search;
            j++;
        }

    }

    thirdArr->length = j;
    thirdArr->size = 10;

    return thirdArr;
}

Array* Array::unsortedDifference(Array *secondArr) {

    int i, j = 0;
    int search, result;
    Array* thirdArr = new Array(length + secondArr->length);

    for (i = 0; i < length; i++) {

        search = arr[i];
        result = secondArr->linearSearch(search);

        if (result == -1) {
            thirdArr->arr[j] = search;
            j++;
        }

    }

    thirdArr->length = j;
    thirdArr->size = 10;

    return thirdArr;
}

int Array::findMissingElementOne() {

    int series, result;
    int n = arr[length - 1];
    int sum;

    sum = this->sum();

    series = n * (n + 1) / 2;
    result = series - sum;

    return result;
}

int Array::findMissingElementTwo() {

    int i;
    int low, diff;

    low = arr[0];
    diff = low - 0;

    for (i = 0; i < length; i++) {
        if (arr[i] - i != diff) {
            return i + diff;
        }
    }

    return -1;
}

void Array::findMissingElements() {

    int i;
    int low, diff, mValue;

    low = arr[0];
    diff = low - 0;

    for (i = 0; i < length; i++) {
        if (arr[i] - i != diff) {
            while (diff < arr[i] - i) {
                mValue = i + diff;
                cout << "The value " << mValue << " is missing.\n";
                diff++;
            }
        }
    }
}

void Array::findMissingElementsTwo() {

    int i, low, high;
    low = minimum();
    high = maximum();

    int* bitSet = new int[high + 1];

    // Filling the array with 0s.
    for (i = 0; i <= high; i++) {
        bitSet[i] = 0;
    }

    // Assigning 1 to the position of the elements found.
    for (i = 0; i < length; i++) {
        bitSet[arr[i]] = 1;
    }

    // If bitSet[i] is 0 then the element "i" wasn't found.
    for (i = low; i <= high; i++) {
        if (bitSet[i] == 0) {
            cout << "The value " << i << " is missing.\n";
        }
    }

    delete[] bitSet;
}

void Array::findDuplicateElements() {

    int i, j;
    int appearances;
    
    for (i = 0; i < length - 1; i++) {

        if (arr[i] == arr[i + 1]) {
            j = i + 1;
            while (arr[j] == arr[i]) {
                j++;
            }
            appearances = j - i;
            cout << arr[i] << " is appearing " << appearances << " times.\n";
            i = j - 1;
        }

    }
}

void Array::findDuplicateHash() {

    int i;
    int low, high;
    int* hashTable;

    low = minimum();
    high = maximum();

    hashTable = new int[high + 1];

    for (i = 0; i <= high; i++) {
        hashTable[i] = 0;
    }

    for (i = 0; i < length; i++) {
        hashTable[arr[i]]++;
    }

    for (i = low; i <= high; i++) {
        if (hashTable[i] > 1) {
            cout << i << " is appearing " << hashTable[i] << " times.\n";
        }
    }

    delete[] hashTable;
}

void Array::findDuplicateUnsorted() {

    int i, j;
    int count;
    int* arrCopy = new int[length];

    // Making the copy of the original array.
    for (i = 0; i < length; i++) {
        arrCopy[i] = arr[i];
    }

    // Searching for duplicate elements;
    for (i = 0; i < length - 1; i++) {

        count = 1;
        if (arrCopy[i] != -1) {

            for (j = i + 1; j < length; j++) {

                if (arrCopy[i] == arrCopy[j]) {
                    count++;
                    arrCopy[j] = -1;
                }

            }

            if (count > 1) {
                cout << arrCopy[i] << " is appearing " << count << " times.\n";
            }
        }
    }

    delete[] arrCopy;
}

void Array::findPairSum(int k) {

    int i, j;

    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[i] + arr[j] == k) {
                cout << arr[i] << " + " << arr[j] << " = " << k << "\n";
            }
        }
    }
}

void Array::findPairSumHash(int k) {

    int i;
    int diff, low, high;
    int* hashTable;

    low = minimum();
    high = maximum();
    hashTable = new int[high + 1];

    for (i = 0; i <= high; i++) {
        hashTable[i] = 0;
    }

    for (i = 0; i < length; i++) {
        hashTable[arr[i]]++;
    }

    cout << "\nPairs are:\n";
    for (i = 0; i < length; i++) {

        diff = k - arr[i];
        if (hashTable[diff] != 0 && diff >= 0) {
            cout << arr[i] << " + " << k - arr[i] << " = " << k << "\n";
        }
        hashTable[arr[i]] = 1;
    }

    delete[] hashTable;
}

void Array::findPairSumSorted(int k) {

    int i = 0, j = length - 1;

    cout << "\nPairs are:\n";
    while (i < j) {

        if (arr[i] + arr[j] == k) {
            cout << arr[i] << " + " << arr[j] << " = " << k << "\n";
            i++;
            j--;
        } else if (arr[i] + arr[j] < k) {
            i++;
        } else {
            j--;
        }

    }
}

void Array::findMaxMin() {

    int i;
    int min = arr[0], max = arr[0];

    for (i = 1; i < length; i++) {

        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }

    }

    cout << "\nValues\n";
    cout << "Minimum: " << min << "\n";
    cout << "Maximum: " << max << "\n";
}

int main(void) {

    int choice;
    int size, value, index;
    Array *newArray;

    cout << "Enter size of array: ";
    cin >> size;
    newArray = new Array(size);

    do {
        cout << "\nMenu\n";
        cout << " 1. Insert\n";
        cout << " 2. Append\n";
        cout << " 3. Delete\n";
        cout << " 4. Search\n";
        cout << " 5. Sum\n";
        cout << " 6. Find missing element (1-n)\n";
        cout << " 7. Find missing element (m-n)\n";
        cout << " 8. Find missing elements\n";
        cout << " 9. Find missing elements (method two)\n";
        cout << "10. Find duplicate elements\n";
        cout << "11. Find duplicate elements (hash)\n";
        cout << "12. Find duplicate elements - unsorted array\n";
        cout << "13. Find a pair with sum k\n";
        cout << "14. Find a pair with sum k (hash)\n";
        cout << "15. Find a pair with sum k (sorted array)\n";
        cout << "16. Find maximum and minimum value.\n";
        cout << "17. Display\n";
        cout << "18. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element: ";
                cin >> value;
                cout << "Enter its index: ";
                cin >> index;
                newArray->insert(index, value);
                system("cls");
                break;
            case 2:
                cout << "Enter an element: ";
                cin >> value;
                newArray->append(value);
                system("cls");
                break;
            case 3:
                cout << "Enter an index: ";
                cin >> index;
                value = newArray->del(index);
                cout << "Deleted element is: " << value << "\n";
                system("pause");
                system("cls");
                break;
            case 4:
                cout << "Enter an element to search: ";
                cin >> value;
                index = newArray->linearSearch(value);
                cout << "Element index: " << index << "\n";
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "Sum is: " << newArray->sum() << "\n";
                system("pause");
                system("cls");
                break;
            case 6:
                value = newArray->findMissingElementOne();
                cout << "The missing element is: " << value << "\n";
                system("pause");
                system("cls");
                break;
            case 7:
                value = newArray->findMissingElementTwo();
                cout << "The missing element is: " << value << "\n";
                system("pause");
                system("cls");
                break;
            case 8:
                newArray->findMissingElements();
                system("pause");
                system("cls");
                break;
            case 9:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    newArray->findMissingElementsTwo();
                }
                system("pause");
                system("cls");
                break;
            case 10:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    newArray->findDuplicateElements();
                }
                system("pause");
                system("cls");
                break;
            case 11:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    newArray->findDuplicateHash();
                }
                system("pause");
                system("cls");
                break;
            case 12:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    newArray->findDuplicateUnsorted();
                }
                system("pause");
                system("cls");
                break;
            case 13:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    cout << "Enter result to find: ";
                    cin >> value;
                    newArray->findPairSum(value);
                }
                system("pause");
                system("cls");
                break;
            case 14:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    cout << "Enter the result to find: ";
                    cin >> value;
                    newArray->findPairSumHash(value);
                }
                system("pause");
                system("cls");
                break;
            case 15:
                if (newArray->getLength() == 0) {
                    cout << "Nothing to find.\n";
                } else {
                    if (newArray->isSorted() != 1) {
                        cout << "You need to enter a sorted array.\n";
                    } else {
                        cout << "Enter the result to find: ";
                        cin >> value;
                        newArray->findPairSumSorted(value);
                    }                    
                }
                system("pause");
                system("cls");
                break;
            case 16:
                if (newArray->getLength() == 0) {
                    cout << "Nothing no find.\n";
                } else {
                    newArray->findMaxMin();
                }
                system("pause");
                system("cls");
                break;
            case 17:
                newArray->display();
                system("pause");
                system("cls");
                break;
        }
    } while (choice < 18);

    return 0;
}
