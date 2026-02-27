// XOR Linked List Example

#include <stdio.h>
#include <stdlib.h> // for malloc function (Dynamix memery allocation)
#include <stdint.h>  //for Type casting 

struct Node
{
    char data;
    struct Node *xor;
};

struct Node *start = NULL;
struct Node *end   = NULL;

void insertATE(char);
void showAll();
void showAll2();

void main()
{
    insertATE('A');
    insertATE('B');
    insertATE('C');
    insertATE('D');
    insertATE('E');

    showAll();
    printf("----------\n");
    showAll2();

}


void insertATE(char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    if(start == NULL)
    {
        temp->xor = 0;
        start = end = temp;
        return;
    }

    temp->xor = (struct Node *)((uintptr_t)end ^ (uintptr_t)0);  //(uintptr_t) iska use type casting ke liye kiya hai

    end->xor = (struct Node *)((uintptr_t)end->xor ^ (uintptr_t)temp);

    end = temp;
}


void showAll()
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = start;
    struct Node *prev1 = 0;
    struct Node *prev2;

    while(temp != end)
    {
        printf("%c\n", temp->data);

        prev2 = temp;

        temp = (struct Node *)((uintptr_t)prev1 ^ (uintptr_t)temp->xor);

        prev1 = prev2;
    }

    printf("%c\n", temp->data);
}


void showAll2()
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = end;
    struct Node *prev1 = 0;
    struct Node *prev2;

    while(temp != start)
    {
        printf("%c\n", temp->data);

        prev2 = temp;

        temp = (struct Node *)((uintptr_t)prev1 ^ (uintptr_t)temp->xor);

        prev1 = prev2;
    }

    printf("%c\n", temp->data);
}



/*
output :=
        A
        B
        C
        D
        E
        ----------
        E
        D
        C
        B
        A

*/
