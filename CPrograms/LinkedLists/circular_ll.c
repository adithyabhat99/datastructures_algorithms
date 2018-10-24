#include<stdio.h>
#include<stdlib.h>
struct ll
{
	int data;
	struct ll *link;
};
int c;
typedef struct ll * node;
void insert_r(node *last,int item)
{
	node temp=(node)malloc(sizeof(struct ll));
	temp->link=temp;
	temp->data=item;
	if(*last==NULL)
	{
		(*last)=temp;
		c++;
		return;
	}
	temp->link=(*last)->link;
	(*last)->link=temp;
	(*last)=temp;
	c++;
}
void insert_f(node *last,int item)
{
	node temp=(node)malloc(sizeof(struct ll));
	temp->data=item;
	temp->link=temp;
	if(*last==NULL)
	{
		(*last)=temp;
		c++;
		return;
	}
	temp->link=(*last)->link;
	(*last)->link=temp;
	c++;
}
void display(node last)
{
	node p=last;
	if(c==0	)
	{
		printf("Empty\n");
		return;
	}
	while(p->link!=last)
	{
		p=p->link;
		printf("%d ",p->data);
	}
	p=p->link;
	printf("%d ",p->data);
	printf("\n");
}
void delete_r(node *last)
{
	node prev=NULL;
	node t=*last;
	if(c==0)
	{
		printf("Empty\n");
		return;
	}
	if((*last)->link==NULL)
	{
		printf("Deleteted element is %d\n",(*last)->data);
		*last=NULL;
		c--;
		free(*last);
		return;
	}
	while(t->link!=(*last))
	{
		t=t->link;		
	}
	t->link=(*last)->link;
	printf("Deleted element is %d\n",(*last)->data);
	c--;
	free(*last);
	(*last)=t;
}
void delete_f(node *last)
{
	node p;
	if(c==0)
	{
		printf("Empty\n");
		return;
	}
	if((*last)->link==NULL)
	{
		printf("Deleteted element is %d\n",(*last)->data);
		*last=NULL;
		c--;
		return;
	}
	p=(*last)->link;
	(*last)->link=(*last)->link->link;
	printf("Deleted element is %d\n",p->data);
	free(p);
	c--;
}
void main()
{
	int item,ch;
	node last=NULL;
	do
	{
		printf("Enter choice  1 Insert_r,2 insert_f,  3 Delete_r  4Delete_f  5 Display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			scanf("%d",&item);
			insert_r(&last,item);
			break;
			case 2:printf("Entre item\n");
			scanf("%d",&item);
			insert_f(&last,item);
			break;
			case 3:delete_r(&last);
			break;
			case 4:delete_f(&last);
			break;
			case 5:display(last);
			break;
			default:return;
		}
	}while(ch);
}
