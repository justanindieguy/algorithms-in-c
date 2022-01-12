#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }

        swap(&arr[i], &arr[k]);
    }
}

int main()
{
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    int i;
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
