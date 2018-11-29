#include<stdio.h>
int fibo(int n)
{
    if(n<=0)
    return 0;
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    return (fibo(n-1)+fibo(n-2));
}
void main()
{
    int n;
    scanf("%d",&n);
    printf("%d ",fibo(n));
    printf("\n");
}