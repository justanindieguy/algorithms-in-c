#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = arr[i];

        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
    }
}

int main()
{
    int arr[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    int i = 0;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
