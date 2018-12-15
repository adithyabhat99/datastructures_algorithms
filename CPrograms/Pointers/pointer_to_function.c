#include<stdio.h>
void dope(int(*p)(),int n)
{
    printf("Square of %d is %d\n",n,(*p)(n));
}
int m(int n)
{
    return n*n;
}
void main()
{
    int n;
    printf("Enter number\n");
    scanf("%d",&n);
    dope(m,n);
}