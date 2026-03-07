#include<stdio.h>
int linearSearch(int x[],int n,int se)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(se == x[i])
		{
			return i; // return index
		}
	}
	return -1; //not found element
}

void main()
{
	int i;
	int n=10;
	int x[]={12,58,88,55,11,23,18,75,22,2};
	printf("%d\n",linearSearch(x,n,22));
}

/*
output:- 8
*/
