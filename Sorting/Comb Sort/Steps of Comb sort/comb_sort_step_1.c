#include<stdio.h>
void show(int x[],int n)
{
	int i;
	int t;
	int g=n/1.3;
	while(g>=1)
	{
		for(i=0 ; i < n-g ;i++)
		{
			if(x[i] > x[i+g])
			{
				t=x[i];
				x[i]=x[i+g];
				x[i+g]=t;
			}
		}
		g=g/1.3; // This represents gap 
	}
}

void main()
{
	int i;
  int n=10;
	int x[]={5,0,3,2,7,1,8,4,9,6};
	
	show(x,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d\n",x[i]);
	}
}
