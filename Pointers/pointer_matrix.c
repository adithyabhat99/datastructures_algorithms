#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **a,i,j;
    int m,n;
    printf("Size\n");
    scanf("%d%d",&m,&n);
    a=(int **)malloc(sizeof(int *)*m);  
//can also use malloc(m*n*sizeof(int)), access element by *(a+m*i+j)
    for(i=0;i<m;i++)
    a[i]=(int *)malloc(n*sizeof(int));
    printf("Enter\n");
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",*(*(a+i)+j));
        printf("\n");
    }
}
