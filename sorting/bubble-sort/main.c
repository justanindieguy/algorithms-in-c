#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    int flag;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            flag = 0;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

int main()
{
    int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
