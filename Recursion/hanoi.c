#include<stdio.h>
void hanoi(int n,char source,char temp,char dest)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,source,dest);
        return;
    }
    hanoi(n-1,source,dest,temp);
    printf("Move disk %d from %c to %c\n",n,source,dest);
    hanoi(n-1,temp,source,dest);
}
void main()
{
    int n;
    char a='A',b='B',c='C';
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    hanoi(n,a,b,c);
}