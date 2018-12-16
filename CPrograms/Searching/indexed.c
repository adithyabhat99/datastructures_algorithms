//hashed serach,Re hashing for collissions
#include<stdio.h>
struct table
{
    int data;
    int taken;
}s[10];
void input(int i)
{
    int p;
    p=p%10;
    while(s[p].taken)
    {
        p=(p+1)%10;
    }
    s[p].data=i;
    s[p].taken=1;
}
void search(int key)
{
    int p=key,c=0;
    while(s[p].data!=key && c<10) {  
    p=(p+1)%20;
    c++; //to avoid infinite loop
    }
    if(c>=10)
    printf("Not found\n");
    else 
    printf("Found in position %d\n",p);
}
void main()
{
    int i,c=0;
    for(i=0;i<10;i++)
        s[i].taken=0;
    printf("Enter 10 elements\n");
    while(c<10)
    {
        scanf("%d",&i);
        c++;
        input(i);
    }
    printf("Enter key value\n");
    scanf("%d",&i);
    search(i);
}