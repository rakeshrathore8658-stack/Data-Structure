#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *root =NULL;


struct Node *insert1(struct Node *temp,int x);
void showALL2(struct Node *temp);
void showALL3(struct Node *temp);
void showALL(struct Node *temp);
struct Node *insert1(struct Node *temp,int x)
{
	if(temp == NULL)
	{
		temp=malloc(sizeof(struct Node));
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		
	}
	else if(x < temp->data)
	{
		temp->left = insert1(temp->left,x);
	}
	else 
	{
		temp->right = insert1(temp->right,x);
	}
	return temp;
}

void showALL(struct Node *temp)
{
	if(temp == NULL) return;
	
	showALL(temp->left);
	printf("%d\n",temp->data);
	showALL(temp->right);
}

void showALL3(struct Node *temp)
{
	if(temp == NULL) return;
	
	printf("%d\n",temp->data);
	showALL3(temp->left);
	showALL3(temp->right);
}


void showALL2(struct Node *temp)
{
	if(temp == NULL) return;
	
	showALL2(temp->left);
	showALL2(temp->right);
	printf("%d\n",temp->data);
}

void insert(int x)
{
	if(root == NULL)
	{
		root =insert1(root,x);
	}
	else
	{
		insert1(root,x);
	}
}

void main()
{
	insert(10);
	insert(20);
	insert(50);
	insert(18);
	insert(41);
	showALL(root);
	showALL2(root);
	showALL3(root);
	
}