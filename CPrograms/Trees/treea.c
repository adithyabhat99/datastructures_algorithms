#include<stdio.h>
struct tree
{
    int data;
    int used;
}s[10];
int m;
void maketree(int x)
{
    int i;
    s[0].data=x;
    s[0].used=1;
    m++;
    for(i=1;i<10;i++)
    {
        s[i].used=0;
    }
}
void insert()
{
    int x,c,p;
    if(m==9)
    {
        printf("Full\n");
        return;
    }
    printf("Enter item\n");
    scanf("%d",&x);
    if(m==0)
    {
        maketree(x);
        return;
    }
    p=c=0;
    while(s[c].used && m<10 && x!=s[p].data)
    {
        p=c;
        if(x<s[p].data)
        c=2*p+1;
        if(x>s[p].data)
        c=2*p+2;
    }
    if(x==s[p].data)
    {
        printf("Redundant elements not allowed\n");
        return;
    }
    s[c].data=x;
    s[c].used=1;
}
void preorder(int p)
{
    if(m==0 || s[p].used==0)
    return;
    printf("%d ",s[p].data);
    preorder(2*p+1);
    preorder(2*p+2);
}
void in(int p)
{
    if(m==0 || s[p].used==0)
    return;
    in(2*p+1);
    printf("%d ",s[p].data);
    in(2*p+2);
}
void main()
{
	int ch;
	do
	{
		printf("Tree using array\nChoice:1 Insert,2 Display(preorder),3 Inorder\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(m<10)
			insert();
			else printf("full\n");
			break;
			case 2:preorder(0); printf("\n"); break;
            case 3:in(0); printf("\n"); break;
			default:return;
		}
	}while(ch);	
}

