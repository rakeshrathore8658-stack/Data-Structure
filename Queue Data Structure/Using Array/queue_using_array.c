
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5

void enqueue(int);
int dequeue();
int peek();
bool isFull();
bool isEmpty();
void showAll();

int queue[CAPACITY];
int f = -1;  // front 
int r = -1;  //queue 


void enqueue(int x)
{
    if(isFull())
    {
        printf("queue is full\n");
        return;
    }

    if(f == -1) f++;

    queue[++r] = x;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        exit(0);
    }
	if(f>r)
	{
		f=r=-1;
	}
    return queue[f++];
}

int peek()
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        exit(0);
    }

    return queue[f];
}

bool isEmpty()
{
    if(f == -1 || f > r)
    {
        return true;
    }

    return false;
}

bool isFull()
{
    if(r >= CAPACITY - 1)
    {
        return true;
    }

    return false;
}

void showAll()
{
    int i;

    for(i = f; i <= r; i++)
    {
        printf("%d\n", queue[i]);
    }
}
void main()
{
    printf("%s\n", isEmpty() ? "true" : "false");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    printf("%d\n", dequeue());
    printf("%d\n", peek());

    showAll();
}


/*

output ==
          true
          queue is full
          10
          20
          20
          30
          40
          50

*/
