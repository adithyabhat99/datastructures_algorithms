//Deleting a node based on key position
#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *link;
};
int c=-1;
typedef struct list * node;
void insert(node *head,int item) //Use double ponter to use returntype void
{
	node t=*head;
	node temp=(node)malloc(sizeof(struct list));
    temp->link=NULL;
    temp->data=item;
	if(*head==NULL)
		{ c++;
	*head=temp;
	 }
	else
	{
		while(t->link!=NULL)
			t=t->link;
		t->link=temp;
		c++;
	}
}
void display(node head)
{
	node p=head;
	if(head==NULL)
		printf("Linked List is empty\n");
	else
	{
		printf("Elements in the Linked List are\n");
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->link;
		}
		printf("\n");
	}
}

void delete(node *head,int pos)
{
	node p=*head,prev=NULL;
	int x=0;
	if(*head==NULL)
	{
		printf("Empty\n");
		return;
	}
	else if(pos>c || pos<0)
	{
		printf("Not possible\n");
		return;
	}
	else if(pos==0)
	{
		c--;
		printf("Deleted element is %d\n",(*head)->data);
		(*head)=(*head)->link;
		free(p);
	}
	else
	{
		while(x!=pos)
		{
			prev=p;
			p=p->link;
			x++;
		}
		printf("Deleted element is %d\n",p->data);
		prev->link=p->link;
		free(p);
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
			case 2: printf("Enter position to delete\n");
			scanf("%d",&item);
			delete(&head,item);
			break;
			case 3:display(head);
			break;
			default:return;
		}
	}while(ch!=4);
}
