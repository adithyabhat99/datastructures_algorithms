//Queue using array implementation of linked list
#include<stdio.h>
struct queue
{
	int data;
	int link;
}s[10];
int avail,f,r,c=-1;
void reset()
{
	int i;
	for(i=0;i<9;i++)
		s[i].link=i+1;
	s[i].link=-1;
	r=f=0;
}
int getnode()
{
	int p;
	p=avail;
	avail=s[p].link;
	return p;
}
void insert(int item)
{
	int p;
	if(c==9)
	{
		printf("Full\n");
		return;
	}
	p=getnode();
	s[p].data=item;
	s[r].link=p;
	r=p;
	c++;
}
void delete()
{
	int p;
	if(c==-1)
	{
		printf("Empty\n");
		return;
	}
	c--;
	printf("Deleted element is %d\n",s[f].data);
	p=f;
	f=s[f].link;
	s[p].link=avail;
	avail=p;
	if(c==-1) reset();
}
void display()
{
	int i,j;
	if(c==-1)
	{
		printf("Empty\n");
		return;
	}
	for(i=f,j=0;j<=c;j++,i=s[i].link)
		printf("%d ",s[i].data);
	printf("\n");
}
void main()
{
	int ch,item;
	reset();
	do
	{
		printf("Enter choice\n1 Insert,2 Delete,3 Display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			scanf("%d",&item);
			insert(item);
			break;
			case 2:delete();
			break;
			case 3:display();
			break;
			default:return;
		}
	}while(ch!=4);
}
