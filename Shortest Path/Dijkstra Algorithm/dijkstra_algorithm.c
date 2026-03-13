// Dijkstra Algorithm

#include <stdio.h>
#include <stdbool.h>

#define SIZE 5
#define MAX 2147483647

void algo();
void showAll();
int min();

void main()
{
    int x[SIZE][SIZE] =
    {
        {0,6,0,1,0},
        {6,0,5,2,2},
        {0,5,0,0,5},
        {1,2,0,0,1},
        {0,2,5,1,0}
    };

    algo(x,0);
}

void algo(int x[SIZE][SIZE], int s)
{
    int i,j,m;
    int output[SIZE];
    bool b[SIZE];

    for(i=0;i<SIZE;i++)
    {
        output[i]=MAX;
        b[i]=false;
    }

    output[s]=0;

    for(i=0;i<4;i++)
    {
        m=min(output,b);

        b[m]=true;

        for(j=0;j<SIZE;j++)
        {
            if(x[m][j]!=0 && b[j]==false && output[j]>(output[m]+x[m][j]))
            {
                output[j]=output[m]+x[m][j];
            }
        }
    }

    showAll(output);
}

void showAll(int output[SIZE])
{
    int i;

    for(i=0;i<SIZE;i++)
    {
        printf("%d => %d \n",i,output[i]);
    }
}

int min(int output[], bool b[])
{
    int i;
    int min_value = MAX;
    int min_index = -1;

    for(i=0;i<SIZE;i++)
    {
        if(b[i]==false && min_value>output[i])
        {
            min_value=output[i];
            min_index=i;
        }
    }

    return min_index;
}


/*
output:-
0 => 0 
1 => 3 
2 => 7 
3 => 1 
4 => 2 


=== Code Exited With Errors ===


*/