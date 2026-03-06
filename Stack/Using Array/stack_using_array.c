
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CAPACITY 50

void push(int);
int pop();
int peek();
bool isEmpty();
int Stack[CAPACITY];
int top=-1;

void push(int x)
{
	if(top == CAPACITY -1)
	{
		printf("No Space\n");
		return ;
	}
	Stack[++top]=x;
}

int pop()
{
	if(isEmpty())
	{
		printf("Stack is Empty\n");
		exit(0);  // std lib me rakha hua  hai
	}
	return Stack[top--];
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack is Empty\n");
		exit(0);
	}
	return Stack[top];
}


bool isEmpty()
{
	if(top == -1)
		return true;
	return false;
}

void main()
{
	printf("%s\n",isEmpty()? "Queue is Empty":"Queue is not Empty");
	push(10);
	push(20);
	push(30);
	printf("%s\n",isEmpty()? "Queue is Empty":"Queue is not Empty");
	printf("%d\n ",pop());
	printf("%d\n ",peek());
	printf("%d\n ",peek());
}


/*
output :-
      Queue is Empty
      Queue is not Empty
      30
      20
      20
*/


