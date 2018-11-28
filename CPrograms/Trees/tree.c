//BST insertion,level order,inorder,postorder,preorder
#include<stdio.h>
#include<stdlib.h>
struct tree 
{
	int data;
	struct tree *right;
	struct tree *left;
};
typedef struct tree * node;
void level_oder(node root)
{
	node q[20],curr;
	int f=0,r=-1;
	q[++r]=root;
	while(f<=r)
	{
		curr=q[f++];
		printf("%d ",curr->data);
		if(curr->left!=NULL)
		q[++r]=curr->left;
		if(curr->right!=NULL)
		q[++r]=curr->right;
	}
}
void insert(node *root,int item)
{
	node curr=*root;
	node prev=NULL;
	node temp=(node)malloc(sizeof(struct tree));
	temp->left=temp->right=NULL;
	temp->data=item;
	if(*root==NULL)
	{
		*root=temp;
		return;
	}
	while(curr!=NULL)
	{
		prev=curr;
		if(item<curr->data)
		{
			curr=curr->left;
			if(curr==NULL)
			{
				prev->left=temp;
				return;
			}
		}
		else
		{
			curr=curr->right;
			if(curr==NULL)
			{
				prev->right=temp;
				return;
			}
		}
	}

}
void inorder(node root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(node root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
void preorder(node root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void main()
{
	node root=NULL;
	int ch,item;
	do
	{
		printf("Choices:1 Insert,2 Level Order,3 Inorder,4 Preorder,5 Postoder\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element\n");
			scanf("%d",&item);
			insert(&root,item);
			break;
			case 2:level_oder(root);
			printf("\n");
			break;
			case 3:inorder(root);
			printf("\n");
			break;
			case 4:preorder(root);
			printf("\n");
			break;
			case 5:postorder(root);
			printf("\n");
			break;
			default:return;
		}
	}while(ch);
}