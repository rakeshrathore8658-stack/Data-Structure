#include<stdio.h>

void main()
{
    int n = 7;
    int a[n][n];
    int num = 1;

    for(int layer=0; layer<(n+1)/2; layer++)
    {
        // top row
        for(int j= layer; j< n-layer ; j++)
          {  
              a[layer][j] = num++;
          }
        // right column
        for(int i= layer+1 ; i < n-layer; i++)
         {
             a[i][n-layer-1] = num++;
         }
        // bottom row
        for(int j= (n-layer-2); j >= layer ; j--)
        {
            a[n-layer-1][j] = num++;
        }

        // left column
        for(int i= (n-layer-2) ; i> layer ; i--)
        {
            a[i][layer] = num++;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
}



/*
output:=


   1    2    3    4    5    6    7 
  24   25   26   27   28   29    8 
  23   40   41   42   43   30    9 
  22   39   48   49   44   31   10 
  21   38   47   46   45   32   11 
  20   37   36   35   34   33   12 
  19   18   17   16   15   14   13 


=== Code Exited With Errors ===
  */

