#include<stdio.h>
#include<stdlib.h>
void printm(int *a,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",*(a+i*m+j));
        printf("\n");
    }
}
void transpose(int *a,int *b,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    (*(b+n*j+i))=(*(a+m*i+j));
    printf("Transpose of matrix is \n");
    printm(b,n,m);
}
void main()
{
    int *a,j,i,m,n;
    printf("Enter size of matrix\n");
    scanf("%d%d",&m,&n);
    a=(int *)malloc(sizeof(int)*m*n);
    int *b=(int *)malloc(sizeof(int)*m*n);
    printf("Enter the matrix\n");
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",(a+i*m+j));
    printf("Elements in the matrix are\n");
    printm(a,m,n);
    transpose(a,b,m,n);
    free(a);
    free(b);
}