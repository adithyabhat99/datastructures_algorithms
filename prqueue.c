#include<stdio.h>
#define max 5
struct  queue
{
	int q[5];
	int r,f;
};
void insert(struct queue *s,int item)
{
	int i,j;
	if(s->r==max) { printf("Queue is full\n"); return ; }
	else
	{
	if(item<=s->q[s->r])
	{	s->r=s->r+1;
		s->q[s->r]=item; return; }
	for(i=s->f;i<=s->r;i++)
	{
		if(s->q[i]<item)
		{
			for(j=s->r;j>=i;j--)
				s->q[j+1]=s->q[j];
			s->r=s->r+1;
			s->q[i]=item;
			return;
		}

	} 
   }
   if(s->r==-1)
	{
		s->r=s->r+1;
	s->q[s->r]=item; 
	}
}

int deq(struct queue *s)
{
	int c;
	c=0;
	if(s->r==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{

		c= s->q[s->f];
		s->f=s->f+1;
	}
	if(s->f>s->r) //reset queue
	{
		s->f=0;
		s->r=-1;
	}
	return c;
}
void dis(struct queue s)
{
	int i;
if(s.r==-1)
	{
		printf("Queue is empty\n");	
	}
	else
	{
      for(i=s.f;i<=s.r;i++)
      	printf("%d ",s.q[i]);
	}
}

int main()
{
	int ch,item,c;
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
			scanf("%d",&item);
			insert(&s,item);
			break;
			case 2:c=deq(&s);
			if(c!=0)
				printf("Deleted item is %d\n",c);
			break;
			case 3:printf("Elements are\n");
			dis(s);
			break;
			default: return 0;
		}
	}while(ch);
	return 0;
}
