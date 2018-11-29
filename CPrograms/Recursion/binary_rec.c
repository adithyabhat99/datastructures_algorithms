#include<stdio.h>
void bin(int low,int high,int a[],int item)
{
    if(low<high)
    {
        int mid;
        mid=(low+high)/2;
        if(a[mid]==item)
        {
            printf("Yes\n");
            return;
        }
        if(item<a[mid])
        {
            bin(low,mid,a,item);
        }
        else{
            bin(mid+1,high,a,item);
        }
    }
    else
    printf("Not found\n");
}
void main()
{
    int i,n,item,a[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Item\n");
    scanf("%d",&item);
    bin(0,n,a,item);
}