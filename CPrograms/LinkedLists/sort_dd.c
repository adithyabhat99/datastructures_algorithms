#include<stdio.h>
#include<stdlib.h>
struct DD
{
	int data;
	struct DD *r;
	struct DD *l;
};
typedef struct DD * node;
void insert(node *head,int item)
{
	node p=*head;
	node temp=(node)malloc(sizeof(struct DD));
	temp->data=item;
	temp->r=NULL;
	temp->l=NULL;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	while(p->r!=NULL)
		p=p->r;
	p->r=temp;
	temp->l=p;
}
void delete(node *head)
{
	node p=*head;
	node prev=NULL;
	if(*head==NULL)
	{
		printf("Empty\n");
		return;
	}
	while(p->r!=NULL)
	{
		prev=p;
		p=p->r;
	}
	prev->r=NULL;
	free(p);
}
void display(node head)
{
	if(head==NULL)
	{
		printf("Empty\n");
		return;
	}
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->r;
	}
	printf("\n");
}
void sort(node *head)
{
	node t=*head;
	node prev=NULL;
	node next=t->r;
	int x;
	if(*head==NULL)
	{
		printf("Empty\n");
		return;
	}
	while(t->r!=NULL)
	{
		prev=t;
		next=t->r;
		while(next!=NULL)
		{
			if(prev->data>next->data)
			{
				x=prev->data;
				prev->data=next->data;
				next->data=x;
			}
			next=next->r;
		}
		t=t->r;
	}
}

void main()
{
	node head;
	head=NULL;
	int item,ch;
	do
	{
		printf("Enter choice\n1 Insert,2 Sort,3 Display,4 Delete,5 Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			scanf("%d",&item);
			insert(&head,item);
			break;
			case 2:sort(&head);
			break;
			case 3: display(head);
			break;
			case 4: delete(&head);
			break;
			default:return;
		}
	}while(ch!=5);
}