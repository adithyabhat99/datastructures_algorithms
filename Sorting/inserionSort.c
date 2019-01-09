#include<stdio.h>
void main()
{
	int a[10],n,j,i,key;
	printf("Enter size and elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	printf("Sorted array ussing selection sort is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}