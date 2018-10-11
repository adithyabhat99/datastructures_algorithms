#include<stdio.h>
#define max 5
struct queue
{
	char q[5];
	int f,r;
};
int count;
void enq(struct queue *s,char item)
{
	if(count==max)
		printf("Queue is full\n");
	else
	{
		s->r=(s->r+1)%max;
		s->q[s->r]=item;
		count++;
	}
}
char deq(struct queue *s)
{
	char c='0';
	if(count==0)
	{
		printf("Queue is empty\n");
		return c;
	}
	else
	{
		c=s->q[s->f];
		s->f=(s->f+1)%max;
		count--;
		return c;
	}
}
void dis(struct queue s)
{
	int i;
	if(count==0)
		printf("Queue is empty\n");
	else
	{
		for(i=s.f;i<=(s.r+count)%max;i++)
			printf("%c ",s.q[i%max]);
	}
}

int main()
{
	char item,c;
	int ch;
	struct queue s;
	s.r=-1;
	s.f=0;
	do
	{
		printf("Enter ch\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			getchar();
			scanf("%c",&item);
			enq(&s,item);
			break;
			case 2:c=deq(&s);
			if(c!='0')
				printf("Deleted item is %c\n",c);
			break;
			case 3:printf("Elements are\n");
			dis(s);
			break;
			default: return 0;
		}
	}while(ch!=4);
	return 0;
}
