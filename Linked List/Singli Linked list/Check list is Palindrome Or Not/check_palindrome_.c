#include<stdio.h>
#include<stdlib.h>
struct Node *start=NULL;
void showAll();
void insertAtE(int x);
struct Node
{
        int data;
        struct Node *next;
};

struct Node *left;

int checkPalindrome(struct Node *right)
{
    if(right == NULL)
        return 1;

    int result = checkPalindrome(right->next);

    if(result == 0)
        return 0;

    if(left->data != right->data)
        return 0;

    left = left->next;

    return 1;
}

int isPalindrome()
{
    left = start;
    return checkPalindrome(start);
}



void insertAtB(int x)
{
        struct Node *temp=malloc(sizeof(struct Node));
        if(temp == NULL) 
        {
                printf("No Space\n");
                return;
        }
        temp -> data=x;
        temp -> next = start;
        start = temp;
}

void showAll()
{
        if(start==NULL)
        {
                printf("list is empty\n");
                return;
        }
        struct Node *temp1=start;

        while(temp1!=NULL)
        {
                printf("%d \n",temp1 -> data);
                temp1=temp1 ->next;
        }
}

void insertAtE(int x)
{
        if(start==NULL)
        {
                insertAtB(x);
                return;
        }
        struct Node *temp=malloc(sizeof(struct Node));

        temp -> data=x;
        temp -> next=NULL;
        struct Node *temp1 =start;
        while(temp1 -> next!=NULL)
        {
                temp1 =temp1 ->next;
        }
                temp1 ->next = temp;


}


void main()
{
    insertAtB(1);
    insertAtB(2);
    insertAtB(3);
    insertAtB(6);
    insertAtB(1);

    showAll();

    if(isPalindrome())
        printf("List is Palindrome\n");
    else
        printf("List is Not Palindrome\n");
}