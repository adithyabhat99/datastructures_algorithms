#include<stdio.h>
#include<stdlib.h>
void main()

{
	int *a,n,i,sum=0;
	printf("Enter size\n");
	scanf("%d",&n);
	a =(int *)malloc(n*(sizeof(int)));
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
		sum+=*(a+i);
	}
    printf("Sum is %d\n",sum );
		free(a);

}