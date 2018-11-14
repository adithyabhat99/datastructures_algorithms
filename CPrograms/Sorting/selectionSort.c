#include<stdio.h>
void main()
{
	int a[10],i,min,j,n,x;
	printf("Enter size and elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		x=a[i];
		a[i]=a[min];
		a[min]=x;
	}
	printf("Sorted array ussing selection sort is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}