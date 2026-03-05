#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define CAPACITY 50

void push(char);
char pop();
char peek();
bool isEmpty();
int pr(char);
void reverse(char x[], int n);

char Stack[CAPACITY];
int top = -1;

void main()
{
    int i = 0;
    int k = 0;

    char input[CAPACITY];
    char output[CAPACITY];

    printf("Enter any Expression\n");
    scanf("%s", input);

    int n = strlen(input);

    reverse(input, n);      // Step 1: reverse input
    printf("%s\n", input);

    while(input[i] != '\0')
    {
        if(input[i] == '(')
        {
            push(input[i]);
        }

        else if(input[i] >= 65 && input[i] <= 90)   // A-Z
        {
            output[k++] = input[i];
        }

        else if(input[i] == ')')
        {
            while(peek() != '(')
            {
                output[k++] = pop();
            }
            pop();
        }

        else
        {
            while(pr(peek()) >= pr(input[i]))
            {
                output[k++] = pop();
            }
            push(input[i]);
        }

        i++;
    }

    output[k] = '\0';

    reverse(output, k);   

    printf("%s\n", output);
}

int pr(char ch)
{
    switch(ch)
    {
        case '(':
            return 0;

        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
}

void push(char x)
{
    Stack[++top] = x;
}

char pop()
{
    return Stack[top--];
}

char peek()
{
    return Stack[top];
}

bool isEmpty()
{
    if(top == -1)
        return true;

    return false;
}

void reverse(char x[], int n)
{
    int i=0, j=n-1,k;
    char t;

    while(i < j)
    {
       		
        t = x[i];
        x[i] = x[j];
        x[j] = t;

        i++;
        j--;
    }
	for(k=0;k<n;k++)
	{
		if(x[k] == '(')
            x[k] = ')';
        else if(x[k] == ')')
            x[k] = '(';
	}
}
