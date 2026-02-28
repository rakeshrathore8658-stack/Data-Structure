/* shell sort */

#include <stdio.h>

void csort(int x[], int n, int g)
{
    if (g <= 1) return;

    int i;
    int t;

    for (i = 0; i < n - g; i++)
    {
        if (x[i] > x[i + g])
        {
            t = x[i];
            x[i] = x[i + g];
            x[i + g] = t;
        }
    }

    csort(x, n, g / 2);
}

void isort(int x[], int n)
{
    int i, j;
    int value;

    for (i = 1; i < n; i++)
    {
        value = x[i];

        for (j = i; j > 0 && value < x[j - 1]; j--)
        {
            x[j] = x[j - 1];
        }

        x[j] = value;
    }
}

void ssort(int x[], int n)
{
    csort(x, n, n / 2);
    isort(x, n);
}

void main()
{
    int i;
    int n = 10;

    int x[] = {4, 0, 3, 2, 7, 1, 8, 5, 9, 6};

    ssort(x, n);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", x[i]);
    }
}