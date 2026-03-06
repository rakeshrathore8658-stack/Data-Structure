#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 50

void push(char);
char pop();
char peek();
bool isEmpty();

char stack[CAPACITY];
int top = -1;

void main()
{
    int i = 0;
    char input[CAPACITY];

    printf("Enter any Expression\n");
    scanf("%s", input);

    while (input[i] != '\0')
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            push(input[i]);
        }

        else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if (isEmpty())
            {
                push('a');
                break;
            }

            if (input[i] == ')')
            {
                if (peek() == '(')
                {
                    pop();
                }
                else break;
            }

            if (input[i] == '}')
            {
                if (peek() == '{')
                {
                    pop();
                }
                else break;
            }

            if (input[i] == ']')
            {
                if (peek() == '[')
                {
                    pop();
                }
                else break;
            }
        }

        i++;
    }

    if (isEmpty())
    {
        printf("correct Expression\n");
    }
    else
    {
        printf("Incorrect Expression\n");
    }
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

bool isEmpty()
{
    if (top == -1)
        return true;

    return false;
}
