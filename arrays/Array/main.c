#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *arr;
    int size;
    int length;
};

/* ---------- PROTOTYPES ---------- */
void display(struct Array arrStruct);
void append(struct Array *arrStruct, int x);
void insert(struct Array *arrStruct, int index, int x);
int delete(struct Array *arrStruct, int index);
void swap(int *firstElement, int *secondElement);
int linearSearch(struct Array arrStruct, int key);
int binarySearch(struct Array arrStruct, int key);
int rBinSearch(int arr[], int low, int high, int key);
int get(struct Array arrStruct, int index);
void set(struct Array *arrStruct, int index, int x);
int maximum(struct Array arrStruct);
int minimum(struct Array arrStruct);
int sum(struct Array arrStruct);
float avg(struct Array arrStruct);
void reverse(struct Array *arrStruct);
void reverseTwo(struct Array *arrStruct);
void leftShift(struct Array *arrStruct);
void leftRotate(struct Array *arrStruct);
void insertSort(struct Array* arrStruct, int x);
int isSorted(struct Array arrStruct);
void rearrange(struct Array *arrStruct);
struct Array* merge(struct Array *firstArr, struct Array *secondArr);
struct Array* unionSorted(struct Array *firstArr, struct Array *secondArr);
struct Array* intersection(struct Array *firstArr, struct Array *secondArr);
struct Array* difference(struct Array* firstArr, struct Array* secondArr);
struct Array* unsortedIntersection(struct Array *firstArr, struct Array *secondArr);
struct Array* unsortedUnion(struct Array *firstArr, struct Array *secondArr);
struct Array* unsortedDifference(struct Array *firstArr, struct Array *secondArr);

/* ----------- FUNCTIONS ----------- */
void display(struct Array arrStruct) {

    int i;
    printf("\nElements are:\n");
    for (i = 0; i < arrStruct.length; i++) {
        printf("[%d] ", arrStruct.arr[i]);
    }
    printf("\n");

}

void append(struct Array *arrStruct, int x) {

    if (arrStruct->length < arrStruct->size) {
        arrStruct->arr[arrStruct->length++] = x;
    }

}

void insert(struct Array *arrStruct, int index, int x) {

    int i;

    if (index >= 0 && index <= arrStruct->length) {

        for (i = arrStruct->length; i > index; i--) {
            arrStruct->arr[i] = arrStruct->arr[i - 1];
        }
        arrStruct->arr[index] = x;
        arrStruct->length++;

    }

}

int delete(struct Array *arrStruct, int index) {

    int x = 0;
    int i;

    if (index >= 0 && index <= arrStruct->length-1) {

        x = arrStruct->arr[index];
        for (i = index; i < arrStruct->length - 1; i++) {
            arrStruct->arr[i] = arrStruct->arr[i + 1];
        }
        arrStruct->length--;

        return x;
    }

    return 0;
}

void swap(int *firstElement, int *secondElement) {

    int temp;

    temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

int linearSearch(struct Array arrStruct, int key) {

    int i;

    for (i = 0; i < arrStruct.length; i++) {
        if (key == arrStruct.arr[i]) {
            return i;
        }
    }

    return -1;
}

int binarySearch(struct Array arrStruct, int key) {

    int low, mid, high;
    low = 0;
    high = arrStruct.length - 1;

    while (low <= high) {

        mid = (low + high) / 2;
        if (key == arrStruct.arr[mid])
            return mid;
        else if (key < arrStruct.arr[mid])
            high = mid - 1;
        else
            low = mid + 1;

    }

    return -1;
}

int rBinSearch(int arr[], int low, int high, int key) {

    int mid;

    if (low <= high) {

        mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return rBinSearch(arr, low, mid - 1, key);
        else
            return rBinSearch(arr, mid + 1, high, key);

    }

    return -1;
}

int get(struct Array arrStruct, int index) {

    if (index >= 0 && index < arrStruct.length)
        return arrStruct.arr[index];
    return -1;
}

void set(struct Array *arrStruct, int index, int x) {
    
    if (index >= 0 && index < arrStruct->length)
        arrStruct->arr[index] = x;
}

int maximum(struct Array arrStruct) {

    int max = arrStruct.arr[0];
    int i;

    for (i = 1; i < arrStruct.length; i++) {
        if (arrStruct.arr[i] > max)
            max = arrStruct.arr[i];
    }
    return max;
}

int minimum(struct Array arrStruct) {

    int min = arrStruct.arr[0];
    int i;

    for (i = 1; i < arrStruct.length; i++) {
        if (arrStruct.arr[i] < min)
            min = arrStruct.arr[i];
    }
    return min;
}

int sum(struct Array arrStruct) {

    int total = 0;
    int i;

    for (i = 0; i < arrStruct.length; i++)
        total += arrStruct.arr[i];
    return total;
}

float avg(struct Array arrStruct) {

    return (float)sum(arrStruct) / arrStruct.length;
}

void reverse(struct Array *arrStruct) {

    int *auxArr;
    int i, j;

    auxArr = (int *)malloc(arrStruct->length * sizeof(int));

    for (i = arrStruct->length - 1, j = 0; i >= 0; i--, j++)
        auxArr[j] = arrStruct->arr[i];
    for (i = 0; i < arrStruct->length; i++)
        arrStruct->arr[i] = auxArr[i];

    auxArr = NULL;
}

void reverseTwo(struct Array *arrStruct) {

    int i, j;

    for (i = 0, j = arrStruct->length - 1; i < j; i++, j--)
        swap(&arrStruct->arr[i], &arrStruct->arr[j]);

}

void leftShift(struct Array *arrStruct) {

    int i, length;

    for (i = 0; i < arrStruct->length; i++)
        arrStruct->arr[i] = arrStruct->arr[i + 1];

    arrStruct->arr[arrStruct->length - 1] = 0;
    arrStruct->length--;

}

void leftRotate(struct Array *arrStruct) {

    int i, temp, length;
    length = arrStruct->length;
    temp = arrStruct->arr[0];

    for (i = 0; i < length; i++)
        arrStruct->arr[i] = arrStruct->arr[i + 1];

    arrStruct->arr[length - 1] = temp;

}

void insertSort(struct Array *arrStruct, int x) {

    int i = arrStruct->length - 1;

    if (arrStruct->length == arrStruct->size)
        return;

    while (i >= 0 && arrStruct->arr[i] > x) {
        arrStruct->arr[i + 1] = arrStruct->arr[i];
        i--;
    }

    arrStruct->arr[i + 1] = x;
    arrStruct->length++;
}

int isSorted(struct Array arrStruct) {

    int i;

    for (i = 0; i < arrStruct.length - 1; i++) {
        if (arrStruct.arr[i] > arrStruct.arr[i + 1])
            return 0;
    }

    return 1;
}

void rearrange(struct Array *arrStruct) {

    int i, j;
    i = 0;
    j = arrStruct->length - 1;

    while (i < j) {
        
        while (arrStruct->arr[i] < 0) {
            i++;
        }

        while (arrStruct->arr[j] >= 0) {
            j--;
        }

        if (i < j) {
            swap(&arrStruct->arr[i], &arrStruct->arr[j]);
        }

    }
}

struct Array* merge(struct Array *firstArr, struct Array *secondArr) {

    int i = 0, j = 0, k = 0;
    struct Array *thirdArr = (struct Array*)malloc(sizeof(struct Array));

    while (i < firstArr->length && j < secondArr->length) {
        
        if (firstArr->arr[i] < secondArr->arr[j])
            thirdArr->arr[k++] = firstArr->arr[i++];
        else
            thirdArr->arr[k++] = secondArr->arr[j++];

    }

    for (; i < firstArr->length; i++)
        thirdArr->arr[k++] = firstArr->arr[i];

    for (; j < secondArr->length; j++)
        thirdArr->arr[k++] = secondArr->arr[j];

    thirdArr->length = firstArr->length + secondArr->length;
    thirdArr->size = 10;

    return thirdArr;
}

struct Array* unionSorted(struct Array *firstArr, struct Array *secondArr) {

    int i = 0, j = 0, k = 0;
    struct Array * thirdArr = (struct Array*)malloc(sizeof(struct Array));

    while (i < firstArr->length && j < secondArr->length) {

        if (firstArr->arr[i] < secondArr->arr[j]) {
            thirdArr->arr[k++] = firstArr->arr[i++];
        } else if (secondArr->arr[j] < firstArr->arr[i]) {
            thirdArr->arr[k++] = secondArr->arr[j++];
        } else {
            thirdArr->arr[k++] = firstArr->arr[i++];
            j++;
        }
            

    }

    for (; i < firstArr->length; i++)
        thirdArr->arr[k++] = firstArr->arr[i];

    for (; j < secondArr->length; j++)
        thirdArr->arr[k++] = secondArr->arr[j];

    thirdArr->length = k;
    thirdArr->size = 10;

    return thirdArr;
}

struct Array* intersection(struct Array *firstArr, struct Array *secondArr) {

    int i = 0, j = 0, k = 0;
    struct Array * thirdArr = (struct Array*)malloc(sizeof(struct Array));

    while (i < firstArr->length && j < secondArr->length) {

        if (firstArr->arr[i] < secondArr->arr[j]) {
            i++;
        } else if (secondArr->arr[j] < firstArr->arr[i]) {
            j++;
        } else if (firstArr->arr[i] == secondArr->arr[j]) {
            thirdArr->arr[k++] = firstArr->arr[i++];
            j++;
        }

    }

    thirdArr->length = k;
    thirdArr->size = 10;

    return thirdArr;
}

struct Array* difference(struct Array *firstArr, struct Array *secondArr) {

    int i = 0, j = 0, k = 0;
    struct Array* thirdArr = (struct Array*)malloc(sizeof(struct Array));

    while (i < firstArr->length && j < secondArr->length) {

        if (firstArr->arr[i] < secondArr->arr[j]) {
            thirdArr->arr[k++] = firstArr->arr[i++];
        } else if (secondArr->arr[j] < firstArr->arr[i]) {
            j++;
        } else {
            i++;
            j++;
        }

    }

    for (; i < firstArr->length; i++)
        thirdArr->arr[k++] = firstArr->arr[i];

    thirdArr->length = k;
    thirdArr->size = 10;

    return thirdArr;
}

struct Array* unsortedIntersection(struct Array *firstArr, struct Array *secondArr) {

    int i, j = 0;
    int search, result;
    struct Array* thirdArr = (struct Array*)malloc(sizeof(struct Array));

    for (i = 0; i < firstArr->length; i++) {

        search = firstArr->arr[i];
        result = linearSearch(*secondArr, search);

        if (result != -1) {
            thirdArr->arr[j] = search;
            j++;
        }

    }

    thirdArr->length = j;
    thirdArr->size = 10;

    return thirdArr;
}

struct Array* unsortedUnion(struct Array *firstArr, struct Array *secondArr) {

    int i, j = 0;
    int search, result;
    struct Array* thirdArr = (struct Array*)malloc(sizeof(struct Array));

    for (i = 0; i < firstArr->length; i++) {

        thirdArr->arr[j] = firstArr->arr[i];
        j++;

    }

    for (i = 0; i < secondArr->length; i++) {

        search = secondArr->arr[i];
        result = linearSearch(*firstArr, search);

        if (result == -1) {
            thirdArr->arr[j] = search;
            j++;
        }

    }

    thirdArr->length = j;
    thirdArr->size = 10;

    return thirdArr;
}

struct Array* unsortedDifference(struct Array *firstArr, struct Array *secondArr) {

    int i, j = 0;
    int search, result;
    struct Array* thirdArr = (struct Array*)malloc(sizeof(struct Array));

    for (i = 0; i < firstArr->length; i++) {

        search = firstArr->arr[i];
        result = linearSearch(*secondArr, search);

        if (result == -1) {
            thirdArr->arr[j] = search;
            j++;
        }

    }

    thirdArr->length = j;
    thirdArr->size = 10;

    return thirdArr;
}

int main(void) {

    int choice;
    int value, index;
    struct Array newArray;

    printf("Enter size of array: ");
    scanf_s("%d", &newArray.size);
    newArray.arr = (int*)malloc(newArray.size * sizeof(int));
    newArray.length = 0;

    do {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf_s("%d", &value);
                printf("Enter its index: ");
                scanf_s("%d", &index);
                insert(&newArray, index, value);
                system("cls");
                break;
            case 2:
                printf("Enter an index: ");
                scanf_s("%d", &index);
                value = delete(&newArray, index);
                printf("Deleted element is: %d\n", value);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Enter an element to search: ");
                scanf_s("%d", &value);
                index = linearSearch(newArray, value);
                printf("Element index: %d\n", index);
                system("pause");
                system("cls");
                break;
            case 4:
                printf("Sum is: %d\n", sum(newArray));
                system("pause");
                system("cls");
                break;
            case 5:
                display(newArray);
                system("pause");
                system("cls");
                break;
        }
    } while (choice < 6);

    return 0;
}
