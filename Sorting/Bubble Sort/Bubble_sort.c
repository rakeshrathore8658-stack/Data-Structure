#include <stdio.h>

void main()
{
    int x[] = {5, 4, 3, 2, 1};
    int n = 5;
    int i, j, k, t;

    // Print Original Array
    for (k = 0; k < n; k++)
    {
        printf("%d ", x[k]);
    }

    printf("\n");

    // Bubble Sort
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)   
        {
            if (x[j] > x[j + 1])
            {
                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }

    // Print Sorted Array
    for (k = 0; k < n; k++)
    {
        printf("%d ", x[k]);
    }
}

/*
whole Process :-

step 1 :-
          5 4 3 2 1 
          4 5 3 2 1 
          4 3 5 2 1 
          4 3 2 5 1 
step 2 :-          
          4 3 2 1 5 
          3 4 2 1 5 
          3 2 4 1 5 
step 3 :-         
          3 2 1 4 5 
          2 3 1 4 5 
step 4 :-          
          2 1 3 4 5 
Final step  :-          
          1 2 3 4 5 

*/
