// N Queen Problem with only two methods in isValid()

#include<stdio.h>
#include<stdbool.h>
void display(int x[4][4]);

bool isValid(int x[4][4],int r, int c) // checking queens in  matrix
{
  int i,j;

  // Checking for Column in matrix
  for(i=r;i>=0;i--)  
    {
      if(x[i][c])
      {
        return false;
      }
    }

  // checking upper-left diagonal in matrix
  for(i=r, j=c; i>=0 && j>=0 ; i--,j--)
    {
      if(x[i][j])
      {
        return false;
      }
    }
  return true;
}

bool show(int x[4][4],int r)   // checking by isValid() for every elements of the Matrix
{
  if(r>=4) return true;

  int j;
  for(j=0 ; j<4 ; j++)
    {
      if(isValid(x,r,j))
      {
        printf("r=%d\t j=%d\n",r,j);
        x[r][j]=1;
        display(x);

        if(show(x,r+1)) return true;  // recursively Backtracking call

        printf("r=%d\t j=%d\n",r,j);
        x[r][j]=0;
        display(x);
      }
    }
  return false;
}

void display(int x[4][4])  // for display Matrix
{
  int i,j;
  for(i=0;i<4;i++)
    {
      for(j=0 ;j<4 ;j++)
        {
          printf("%d ",x[i][j]);
        }
      printf("\n");
    }

  printf("\n");
}

void main()
{
  int x[4][4]= {
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0}
              };

  display(x);
  show(x,0);
}
