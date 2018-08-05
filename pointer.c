#include<stdio.h>
void array(int *a);

int i;

void out(int *a)
{
for(i=0;i<100;i++)
{
printf("%d\t",*a);
a++;
}
}

void main()
{
int a[100],x=1;
for(i=0;i<100;i++)
{
a[i]=x;
x++;
}
out(a);	
printf("\n");
array(a);
printf("\n");
out(a);
printf("\n");
}

void array(int *a)
{
for(i=0;i<100;i++)
{
	(*a)=(*a)+1;
	a++;
}
}
