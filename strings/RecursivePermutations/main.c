#include <stdio.h>
#include <conio.h>

void printPermutations(char str[], int k)
{
    static int aux[10] = {0};
    static char result[10];

    if (str[k] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
    }
    else
    {
        int i;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (aux[i] == 0)
            {
                result[k] = str[i];
                aux[i] = 1;

                // Recursive call.
                printPermutations(str, k + 1);

                aux[i] = 0;
            }
        }
    }
}

int main()
{
    char str[] = {'A', 'B', 'C', '\0'};
    printPermutations(str, 0);

    return 0;
}
