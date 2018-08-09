#include<stdio.h>
#include<stdlib.h>
int *c;
void display(int *a,int n);
void push(int *a,int ele,int n);
void main()
{
	int a[100],ele,n,i,x=1;
	c=&x;

	n=0;
	while(*c==1)
	{
		printf("Enter the element to push\n");
		scanf("%d",&ele);
		push(a,ele,n);
		printf("Enter 1 to continue\n");
		scanf("%d",&x);
		n++;

	}
	if((*c)!=1)
	{
		
		printf("\n");
		display(a,n);
	}

}

void push(int *a,int ele,int n)
{  
	
		*(a+n)=ele;
		printf("%d has been pushed \n",ele);
	}

void display(int *a,int n)
{
	int i;
		printf("\n");
	for(i=0;i<n;i++)

	{
	printf("%d\t",*(a+i));

	}
  printf("\n");
  exit(0);
}