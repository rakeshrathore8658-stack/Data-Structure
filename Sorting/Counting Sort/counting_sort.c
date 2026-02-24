// Counting Sort 


#include <stdio.h>

void show(int x[], int n)
{
    int i;
    int max = x[0];
    int min = x[0];

    // Find minimum
    for (i = 1; i < n; i++)
    {
        if (min > x[i])
            min = x[i];
    }

    // Make all elements non-negative
    for (i = 0; i < n; i++)
    {
        x[i] = x[i] - min;
    }

    // Find maximum
    for (i = 1; i < n; i++)
    {
        if (max < x[i])
            max = x[i];
    }

    max++;

    int a[max];

    // Initialize count array
    for (i = 0; i < max; i++)
    {
        a[i] = 0;
    }

    // Count frequency
    for (i = 0; i < n; i++)
    {
        a[x[i]]++;
    }

    // Cumulative count
    for (i = 1; i < max; i++)
    {
        a[i] = a[i] + a[i - 1];
    }

    int y[n];

    // Build output array
    for (i = 0; i < n; i++)
    {
        y[--a[x[i]]] = x[i];
    }

    // Copy back with original values
    for (i = 0; i < n; i++)
    {
        x[i] = y[i] + min;
    }
}

int main()
{
    int n = 8;
    int i;

    int x[] = {2, 7, 7, 1, 3, -5, 5, 9};

    show(x, n);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", x[i]);
    }

    return 0;
}



