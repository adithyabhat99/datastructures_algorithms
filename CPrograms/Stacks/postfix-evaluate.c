	#include<stdio.h>
#include<ctype.h>
#include<math.h>
struct st
{
    int stack[20];
	int top;
}s;
int cal(int n,int m,char c)
{
	int x=0;
  	if(c=='+') x=n+m;
  	 if(c=='-') x=n-m;
  	 if(c=='*') x=n*m;
  	 if(c=='/') x=n/m;
  	 if(c=='^') x=pow(n,m);
   return x;
}
void push(struct st *s,int c )
{
	(*s).stack[++(*s).top]=c;
}
int pop(struct st *s)
{
	return (*s).stack[(*s).top--];
}
void main()
{
	struct s;
	char ex[20];
	scanf("%s",ex);
	int n1,n2,x,i;
	s.top=-1;
    for(i=0;ex[i]!='\0';i++)
    {
    	if(isdigit(ex[i]))
    	{
    		
    		push(&s,(int)ex[i]-'0'); }
    	else
    	{ 
    		n1=pop(&s);
    		n2=pop(&s);
    	x=cal(n2,n1,ex[i]);
    	push(&s,x);
    }
    }
    printf("%d\n",s.stack[s.top]);
}
