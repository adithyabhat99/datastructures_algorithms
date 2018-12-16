#include<stdio.h>
struct ll
{
    int data;
    int link;
}s[10];
int avail,top,c=-1;
int getnode()
{
    int p;
    p=avail;
    avail=s[p].link;
    return p;
}
void insert(int i)
{
    int p,prev;
    if(c==9)
    {
        printf("Full\n");
        return;
    }
    p=getnode();
    s[p].data=i;
    s[top].link=p; //previos top link to newnode
    top=p; //top updated to newnode
    c++;
}
void delete()
{
    int x=0;
    if(c==-1)
    {
        printf("Empty\n");
        return;
    }
    //traverse untill previous element to top
    while(s[x].link!=top)
	x=s[x].link;
    s[x].link=s[top].link;
    avail=top; //avail is updated
    printf("Deleted element is %d\n",s[top].data);
    top=x; //previous position becomes top
    c--;
}
void display()
{
    int i,j;
    if(c==-1)
    {
        printf("Empty\n");
        return;
    }
    for(i=0,j=0;j<=c;i=s[i].link,j++)  
    {
        printf("%d ",s[i].data);
    }
    printf("\n");
}
void main()
{
    int i,ch;
    for(i=0;i<9;i++) {
        s[i].link=i+1; //default link
    }
    s[i].link=-1; //last node
    do
	{
		printf("Enter choice\n1 Insert,2 Delete,3 Display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter item\n");
			scanf("%d",&i);
			insert(i);
			break;
			case 2:delete();
			break;
			case 3:display();
			break;
			default:return;
		}
	}while(ch!=4);
}
