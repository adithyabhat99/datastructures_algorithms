//Stack using Linked List, adding and deleting from rear end
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
void insert(node *head,int item) //Use double ponter to use returntype void
{
	node t=*head;
	node temp=(node)malloc(sizeof(struct stack));
    temp->link=NULL;
    temp->data=item;
	if(c==max)
	{
		printf("Stack is full\n");
	}
	else
	{
		if(*head==NULL)
		{
			c++;
			*head=temp;
		}
		else
		{
			c++;
			while(t->link!=NULL)
				t=t->link;
			t->link=temp;
		}
	}
}

void delete(node *head)
{
	node t=*head;
	node prev=NULL;
	if(c==0 && *head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	if(t->link==NULL)
	{
	  c--;
      printf("Deleted item is %d\n",t->data);
      *head=NULL;
	}	
	else
	{    
		c--;
		while(t->link!=NULL)
		{
			prev=t;
			t=t->link;
		}
		prev->link=NULL;
		printf("\nDeleted item is %d\n",t->data);
		free(t);
	}
}

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