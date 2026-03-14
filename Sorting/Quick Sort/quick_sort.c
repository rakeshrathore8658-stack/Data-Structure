#include <stdio.h>

int show(int x[], int si, int n)
{
    int i, p, pi, t;

    i = p = si;
    pi = x[n];

    for (; i < n; i++)
    {
        if (x[i] < pi)
        {
            t = x[i];
            x[i] = x[p];
            x[p] = t;

            p++;
        }
    }

    x[n] = x[p];
    x[p] = pi;

    return p;
}

void quicksort(int x[], int si, int n)
{
    if (n <= si)
        return;

    int p = show(x, si, n);

    quicksort(x, si, p - 1);
    quicksort(x, p + 1, n);
}

int main()
{
    int x[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = 9;

    quicksort(x, 0, n);

    int i;
    for (i = 0; i <= n; i++)
    {
        printf("%d\n", x[i]);
    }

    return 0;
}


/*
output:-
10
14
19
26
27
31
33
35
42
44


=== Code Execution Successful ===


*/