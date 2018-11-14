#include<stdio.h>
void shellsort(int a[],int n)
{
	for(int gap=n/2;gap>0;gap/=2)
		{
			for(int i=gap;i<n;i++)
			{
				int temp=a[i];
				int j;
				for(j=i;j>=gap && a[j-gap]>temp;j-=gap)
					a[j]=a[j-gap];
				a[j]=temp;
			}
		}
}
void printa(int a[],int n)
{
	int i;
	printf("Elements are\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void main()
{
	int a[]={5,4,3,2,1,6},n=6;
	printa(a,n);
	printf("\n");
	shellsort(a,n);
	printa(a,n);
	printf("\n");
}