//Stack using Linked List, adding and deleting from front end
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct stack
{
	int data;
	struct stack *link;
};
int c;
typedef struct stack* node;
void display(node head)
{
	node p=head;
	if(c==0)
		printf("Stack is empty\n");
	else
	{
		printf("Elements in the stack are\n");
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->link;
		}
		printf("\n");
	}
}
void insert(node *head,int item)
{
   node temp=(node)malloc(sizeof(struct list));
   temp->link=NULL;
   temp->data=item;
   if(c==max)
   {
   	printf("Stack is full\n");
   	return;
   }
   if(*head==NULL)
   {
   	c++;
   	*head=temp;
   	return;
   }
   else
   {
   	c++;
   	temp->link=*head;
   	*head=temp;
   }
}

void delete(node *head)
{
	node p=*head;
	node t;
	if(c==0 && *head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	else
	{
		if(p->link==NULL)
		{
			c--;
			printf("Deleted element is %d\n",p->data);
			*head=NULL;
			return;
		}
		else
		{
		  c--;
		  printf("Deleted elemet is %d\n",p->data);
          t=p->link;
          *head=t;
          free(p);
		}
	}
}


void main()
{
	node head;
	head=NULL;
	int item,ch;
	do
	{
		printf("Enter choice\n1 Insert,2 Delete,3 Display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			scanf("%d",&item);
			insert(&head,item);
			break;
			case 2:delete(&head);
			break;
			case 3:display(head);
			break;
			default:return;
		}
	}while(ch!=4);
}
