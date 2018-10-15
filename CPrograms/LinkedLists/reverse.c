//Reversing Linked List
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
void delete(node *head)
{
	node t=*head;
	node prev=NULL;
	if(*head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(t->link==NULL)
	{
      printf("Deleted item is %d\n",t->data);
      *head=NULL;
	}	
	else
	{    
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

void reverse(node *head)
{
	node curr=*head;
	node prev=NULL;
	node next=curr->link;
	if(*head=NULL)
	{
		printf("Empty\n");
		return;
	}
	while(next!=NULL)
	{
		curr->link=prev;
		prev=curr;
		curr=next;
		next=next->link;
	}
	curr->link=prev;
	*head=curr	;

}


void main()
{
	node head;
	head=NULL;
	int item,ch;
	do
	{
		printf("Enter choice\n1 Insert,2 Sort,3 Display,4 Delete\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			scanf("%d",&item);
			insert(&head,item);
			break;
			case 2:reverse(&head);
			break;
			case 3: display(head);
			break;
			case 4: delete(&head);
			break;
			default:return;
		}
	}while(ch!=4);
}
