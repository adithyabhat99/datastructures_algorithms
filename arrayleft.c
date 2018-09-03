#include<stdio.h>
void main()
{    moves the array elements to left by given value
	long int d,n,a[100000],b[100000],i,c=0;
	printf("Enter array size and value of d\n");
    scanf("%ld%ld",&n,&d);
    printf("Enter array\n");
    for(i=0;i<n;i++)
    	scanf("%ld",&a[i]);
    for(i=0;i<d;i++)
    	b[i]=a[i];
    for(i=d;i<n;i++)
    	a[i-d]=a[i];
    for(i=n-d;i<n;i++)
    { 
    	a[i]=b[c];
    	c++;
    }
    printf("Left moved array is \n");
    for(i=0;i<n;i++)
    	printf("%ld\t",a[i]);
    printf("\n");

}
