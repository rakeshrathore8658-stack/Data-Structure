#include<stdio.h>
#include<stdbool.h>
#define CAPACITY 50

void push(char);
char pop();
char peek();
bool isEmpty();
int pr(char);


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
	
    
	
    while(input[i] != '\0')
    {
        if(input[i] == '(')        // opening bracket
        {
            push(input[i]);
        }

        else if(input[i] >= 65 && input[i] <= 90)   // char A to Z
        {
            output[k++] = input[i];
        }

        else if(input[i] == ')')    // closing bracket
        {
            while(peek() != '(')
            {
                output[k++] = pop();
            }
            pop();
        }

        else        // operators
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
    printf("%s\n", output);
}

int pr(char ch)  //operators priority check
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
