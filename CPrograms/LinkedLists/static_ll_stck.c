//Stacks using array implementation of linked list
#include<stdio.h>
struct stack
{
	int data;
	int link;
}s[10];
int avail,top,c=-1,prev;
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
	s[top].link=p;
	prev=top;
	top=p;
	c++;

}
void delete()
{
	if(c==-1)
	{
		printf("Empty\n");
		return;
	}
	avail=top;
	printf("Deleted element is %d\n",s[top].data);
	top=prev;
	c--;
	
}
void display()
{
	int i,j;
	if(c==-1)
	{
		printf("Empty\n");
		return;
	}
	for(i=0,j=0;j<=c;j++,i=s[i].link)
		printf("%d ",s[i].data);
	printf("\n");
}
void main()
{
	int i,ch,item;
	for(i=0;i<9;i++)
		s[i].link=i+1;
	s[i].link=-1;
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