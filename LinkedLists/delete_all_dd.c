//delete all nodes based on a key in doubly linked list
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
void delete(node *head,int key)
{
	int c=0;
	node p=*head,next;
	node t=*head,prev;
	if(*head=NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(p->data==key && p!=NULL)
	{
		*head=p->r;
		p->l=NULL;
		free(p);
		p=*head;
		c++;
	}
	while(p!=NULL)
	{
		t=p;
		if(p->data==key)
		{
			prev=p->l;;
			next=p->r;
			prev->r=next;
			next->l=prev;
			free(p);
			c++;
		}
		p=p->r;
	}
	if(c==0)
		printf("Key not found\n");
	else
		printf("Deleted %d nodes\n",c);
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

void main()
{
	node head;
	head=NULL;
	int item,ch;
	do
	{
		printf("Enter choice\n1 Insert,2 Delete,3 Display,4 Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: { printf("Enter item\n");
					scanf("%d",&item);
					insert(&head,item);
					break; }
			case 2: { printf("Enter the key\n");
			        scanf("%d",&item);
			        delete(&head,item);
					break; }
			case 3: { display(head);
					break; }
			default:return;
		}
	}while(ch!=4);
}