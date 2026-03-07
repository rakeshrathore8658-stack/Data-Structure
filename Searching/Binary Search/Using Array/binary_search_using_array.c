#include<stdio.h>
int BinarySearch(int x[],int n,int se)
{
	
	int si = 0; //starting I=index
	int mid;
	while(si<=n)
	{
		mid = (si + n)/2;
		printf("%d\n",mid);
		if(se == x[mid])
		{
			return mid;
		}
		else if(se < x[mid])
		{
			n = mid -1;
		}
		else
		{
			si = mid +1;
		}
		
	}
	return -1;
}

void main()
{
	int i;
	int n=10;
	int x[]={2,5,8,10,12,15,18,50,80,90};
	printf("%d\n",BinarySearch(x,n,80));
	
}

/*
output:-
  5
  8
  8
*/

