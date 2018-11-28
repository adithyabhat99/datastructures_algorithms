#include <stdio.h>
#include <stdlib.h>

 struct stack
{
int * a;
int top;
int maxSize;
};
struct stack s;
void initstack(struct stack * p, int maxSize);
void push(struct stack * p, int item);
int pop(struct stack * p);
int isEmpty(struct stack* p);
void calculateSpan(int *price, int n, int *span);
void printSpan(int *span, int n);


int main()
{
    int *price,n,i,*span;
    printf("Enter the number of days\n");
    scanf("%d",&n);  
    price = (int*)malloc(sizeof(int)*n);
    printf("Enter the stock prices\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",price+i);
    }  
    span = (int*)malloc(sizeof(int)*n);
    span[0]=1;
    calculateSpan(price, n, span);
    printf("Span values\n");
    printSpan(span, n); 
    return 0;
}


void initstack(struct stack * p, int maxSize) {
	//Fill in the code here
    	p->top=-1;
    	p->a=(int *)malloc((sizeof(int))*maxSize);
}

void push(struct stack *p, int item)
{
  	//Fill in the code here
  	p->a[++(p->top)]=item;
}

int isEmpty(struct stack* p)
{
   //Fill in the code here
   if(p->top==-1)
   return 1;
  return 0;
}

int pop(struct stack* p)
{
   //Fill in the code here
   return p->a[(p->top)--];
  return 0;
}

void calculateSpan(int *price, int n, int *span)
{
   //Fill in the code here
   int i;
    initstack(&s,n);
    push(&s,0);
   for(i=1;i<=n;i++)
   {
        span[i]=1;
        while(!isEmpty(&s) && price[i]>=price[s.top])
        {
            pop(&s);
        }
        if(isEmpty(&s))
            span[i]=i+1;
        else
            span[i]=i-(s.a[s.top]);
        push(&s,i);
   }
}


void printSpan(int *span, int n)
{
    int i;
    for (i = 0; i < n; i++)
      printf("%d ",*(span+i));
}
