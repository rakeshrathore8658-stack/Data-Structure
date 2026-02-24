#include<stdio.h>
void show(int a,int b,int n)
{
    if(b>n) return;
    printf("%d ",a);
    if(a==n)
    {
        printf("\n");
        b++;
        a=0;
    }
    show(++a,b,n);
}

void main()
{
  show(1,1,5);
}

/*
output :-
  1 2 3 4 5 
  1 2 3 4 5 
  1 2 3 4 5 
  1 2 3 4 5 
  1 2 3 4 5
  */
