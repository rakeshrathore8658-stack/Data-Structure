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



int isPalindrome()
{
    struct Node *slow = start;
    struct Node *fast = start;

    // middle find
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // second half reverse
    struct Node *prev = NULL;
    struct Node *curr = slow->next;
    struct Node *next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // compare
    struct Node *p1 = start;
    struct Node *p2 = prev;

    while(p2 != NULL)
    {
        if(p1->data != p2->data)
            return 0;

        p1 = p1->next;
        p2 = p2->next;
    }

    return 1;
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
        insertAtB(2);
        insertAtB(3);
        showAll();
        
        if(isPalindrome())
    printf("Palindrome\n");
else
    printf("Not Palindrome\n");
}




/*
//second approach


int isPalindrome()
{
    if(start == NULL || start->next == NULL)
        return 1;

    struct Node *slow = start;
    struct Node *fast = start;

    // middle find
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    struct Node *prev = NULL;
    struct Node *curr = slow;
    struct Node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // compare
    struct Node *first = start;
    struct Node *second = prev;

    while(second != NULL)
    {
        if(first->data != second->data)
            return 0;

        first = first->next;
        second = second->next;
    }

    return 1;
}


*/