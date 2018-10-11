//Delete all values based on key value
#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *link;
};
typedef struct list * node;
void insert(node *head,int item) //Use double ponter to use returntype void
{
	node t=*head;
	node temp=(node)malloc(sizeof(struct list));
    temp->link=NULL;
    temp->data=item;
	if(*head==NULL)
	*head=temp;
	else
	{
		while(t->link!=NULL)
			t=t->link;
		t->link=temp;
	}
}
void delete_all(node *head,int key)
{
	node temp=*head;
	node prev=NULL;
	int c=0;
	while(temp->data==key && temp!=NULL)
	{
		c++;
		*head=temp->link;
		free(temp);
		temp=*head;
	}
	prev=temp;
	temp=temp->link;
	while(temp!=NULL)
	{
		while(temp!=NULL && temp->data!=key)
		{
			prev=temp;
			temp=temp->link;
		}
		if(temp==NULL)
		{
			return;
		}
		c++;
		prev->link=temp->link;
		free(temp);
		temp=prev->link;
	}
	if(c==0)
		printf("Not found\n");\
	else
		printf("Deleted %d nodes\n",c);
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
			case 2: printf("Enter element to delete\n");
			scanf("%d",&item);
			delete_all(&head,item);
			break;
			case 3:display(head);
			break;
			default:return;
		}
	}while(ch!=4);
}