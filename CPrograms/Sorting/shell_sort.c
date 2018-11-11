#include<stdio.h>
void ShellSort(int a[],int n)
{
	int temp,gap,i,j;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			temp=a[i];
			for(j=i;j>=gap && a[j-gap]>temp;j-=gap)
				a[j]=a[j-gap];
			a[j]=temp;
		}
	}
}
void main()
{
	int a[10],n,j,i;
	printf("Enter size and elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ShellSort(a,n);
	printf("Sorted array ussing selection sort is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}