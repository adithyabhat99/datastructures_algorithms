//Array implementation of Binary Tree with Pre Order Traversal
#include<stdio.h>
struct tree
{
	int data;
	int used;
};
struct tree a[10];
int size;
void maketree(int item)
{
	int i;
	a[0].used=1;
	a[0].data=item;
	for(i=1;i<10;i++)
		a[i].used=0;
	size++;
}
void insert()
{
	int p,c,item;
	
		printf("Enter item\n");
		scanf("%d",&item);
		if(size==0) { maketree(item); return; }
		size++;
		p=c=0;
		while(c<10 && a[c].used && item!=a[p].data)
		{
			p=c;
			if(item<a[p].data)
				c=2*p+1;
			if(item>a[p].data)
				c=2*p+2;
		}
		if(item==a[p].data)
		{
			printf("Duplicate\n");
			size--;
			return;
		}
		a[c].data=item;
		a[c].used=1;
}
void preorder(int p)
{
	if(a[p].used==0)
		return;
	printf("%d ",a[p].data);
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
void po(int p)
{
	if(m==0 || s[p].used==0)
		return;
	po(2*p+1);
	po(2*p+2);
	printf("%d ",s[p].data);
}
void main()
{
	int ch;
	do
	{
		printf("Tree using array\nChoice:1 Insert,2 Display(preorder)\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(size<10)
			insert();
			else printf("full\n");
			break;
			case 2:preorder(0); printf("\n"); break;
            case 3:in(0); printf("\n"); break;
			default:return;
		}
	}while(ch);	
}
