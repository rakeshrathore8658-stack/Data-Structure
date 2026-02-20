
// This is the steps for the program N-Queen problem 
#include <stdio.h>
#include <stdbool.h>

bool isValid(int x[4][4], int r, int c)
{
    int i, j;

    // Check row on left side
    for (j = c; j >= 0; j--)
    {
        if (x[r][j])
        {
            return false;
        }
    }

    // Check column above
    for (i = r; i >= 0; i--)
    {
        if (x[i][c])
        {
            return false;
        }
    }

    // Check upper-left diagonal
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (x[i][j])
        {
            return false;
        }
    }

    // Check upper-right diagonal
    for (i = r, j = c; i >= 0 && j < 4; i--, j++)
    {
        if (x[i][j])
        {
            return false;
        }
    }

    return true;
}

void main()
{
    int i, j;
    int x[4][4] = 
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (isValid(x, i, j))
            {
                x[i][j] = 1;
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }

}