//N Queen problem 
#include <stdio.h>
#include<stdbool.h> // For boolen Function

void display(int x[4][4])  // For display the matrix  
{
    int i,j;
    for(i=0;i<4;i++) 
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("\n");
}


bool isValid(int x[4][4], int r, int c)  // Checking Queens in matrix
{
    int i,j;
    for(j=c;j>=0;j--)  // row checking  left to right  ⬅️
    {
        if(x[r][j])
        {
            return false;
        }
    }

for(i=r; i>=0;i--)   //  column checking  down to up   ⬆️
{                                      
    if(x[i][c])                        
        {                             
            return false;
        }
}

for(i=r,j=c; i>=0&&j>=0;i--,j--)   // -> Checking on upper left diagonal ↖️
{
    if(x[i][j])
        {
            return false;
        }
}

for(i=r,j=c; i>=0&&j<4;i--,j++)  // -> Checking on upper right diagonal  ↗️
{
    if(x[i][j])
        {
            return false;
        }
}

return true;
}

bool show(int x[4][4],int r) // for every elements of the matrix checking queens
{
    if(r>=4) return true;
    int j;
    for(j=0;j<4;j++)
    {
        if(isValid(x,r,j))
        {
            x[r][j]=1;
             display(x);
            if(show(x,r+1)) return true;
            
            x[r][j]=0;
            display(x);
        }
    }
    return false;
}


void  main() 
{
int x[4][4]={
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};

show(x,0);
display(x);

}

// checking by 4 functions in isValid()  
/*
-> Columns wise Checking 
-> row wise Checking 
-> Checking on upper left diagonal
-> Checking on upper right diagonal
*/


/* output:-

1 0 0 0 
0 0 0 0 
0 0 0 0 
0 0 0 0 


1 0 0 0 
0 0 1 0 
0 0 0 0 
0 0 0 0 


1 0 0 0 
0 0 0 0 
0 0 0 0 
0 0 0 0 


1 0 0 0 
0 0 0 1 
0 0 0 0 
0 0 0 0 


1 0 0 0 
0 0 0 1 
0 1 0 0 
0 0 0 0 


1 0 0 0 
0 0 0 1 
0 0 0 0 
0 0 0 0 


1 0 0 0 
0 0 0 0 
0 0 0 0 
0 0 0 0 


0 0 0 0 
0 0 0 0 
0 0 0 0 
0 0 0 0 


0 1 0 0 
0 0 0 0 
0 0 0 0 
0 0 0 0 


0 1 0 0 
0 0 0 1 
0 0 0 0 
0 0 0 0 


0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 0 0 


0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 


0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

*/
