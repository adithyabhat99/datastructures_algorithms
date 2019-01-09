//Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct queue
{
	int data;
	struct queue *link;
};
int f,r,c;
typedef struct queue * node;
void insert(node *head,int item)
{
	node temp=(node)malloc(sizeof(struct queue));
	node p=*head;
	temp->link=NULL;
	temp->data=item;
	if(r==max)
	{
		printf("Queue is full\n");
		return;
	}
	else
	{
		if(*head==NULL)
		{
			*head=temp;
			r++;
			c++;
			return;
		}
		else
		{
			c++;
			r++;
			while(p->link!=NULL)
				p=p->link;
			p->link=temp;
		}
	}
}

void delete(node *head)
{
	node p=*head;
	node q;
	if(c==0)
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		if(p->link==NULL)
		{
			f++;
			c--;
			printf("Deleted element is %d\n",p->data);
			*head=NULL;
		}
		else
		{
			f++;
			c--;
			printf("Deleted element is %d\n",p->data);
			q=p->link;
			*head=q;
			free(p);
		}
	}
	if(f>r || c==0)
	{
		f=r=0;
	}
}

void display(node head)
{
	node p=head;
	if(c==0)
		printf("Queue is empty\n");
	else
	{
		printf("Elements in the queue are\n");
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