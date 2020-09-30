#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
};
struct bst* insert(struct bst*,int);
struct bst* delet(struct bst*,int);
int main()
{
	struct bst *p=NULL;
	int n=1,num;
	while(n)
	{
		printf("\n\n1.to insert data");
		printf("\n2.to display");
		printf("\n3.to delete data");
		printf("\n0.to exit");
		printf("\nexit your choice");
		scanf("%d",&n);
		if(n==1)
		{
			printf("\nEnter your data");
			scanf("%d",&num);
			p=insert(p,num);
		}
		else if(n==2)
		display(p);
		else if(n==3)	
		{
			printf("\nEnter the data to delete:");
			scanf("%d",&num);
			delet(p,num);
		}
		else
		printf("\nInvalid choice");
	}
	return 0;
}
struct bst* insert(struct bst *q,int num)
{
	if(q==NULL)
	{
		q=(struct bst *)malloc(sizeof(struct bst));
		q->left=NULL;
		q->right=NULL;
		q->data=num;
	}
	else if(q->data>num)
	{
		q->left=insert(q->left,num);
	}
	else
	{
		q->right=insert(q->right,num);
	}
	return q;
}
void display(struct bst *q)
{
	int n;
	printf("\n1.to postorder traversal");
	printf("\n2.for inorder traversal");
	printf("\nby default preorder traversal");
	printf("\nEnter your choice:");
	scanf("%d",&n);
	if(n==1)
	postorder(q);
	else if(n==2)
	inorder(q);
	else
	{
		printf("\nDisplaying preorder traversal\n");
		preorder(q);
	}
}
preorder(struct bst *q)
{
	
	printf("\t %d",q->data);
	if(q->left!=NULL)
	preorder(q->left);
	if(q->right!=NULL)
	preorder(q->right);
}
postorder(struct bst *q1)
{
	
	if(q1->left!=NULL)
	postorder(q1->left);
	if(q1->right!=NULL)
	postorder(q1->right);
	printf("\t %d",q1->data);
}
inorder(struct bst *q2)
{
	
	if(q2->left!=NULL)
	inorder(q2->left);
	printf("\t %d",q2->data);
	if(q2->right!=NULL)
	inorder(q2->right);
}
struct bst* delet(struct bst *d,int num)
{
	struct bst *par1,*par2;
	int t=0;
	while(d!=NULL)
	{
		if(num>d->data)
		{
			par1=d;
			d=d->right;
		}
		else if(d->data>num)
		{
			par1=d;
			d=d->left;
		}
		else
		{
			t=1;
			break;
		}
	}
	if(t==0)
	{
		printf("\n data not found");
		return;
	}
	if(d->left==NULL && d->right==NULL)
	{
		if(par1->left==d)
		par1->left=NULL;
		if(par1->right==d)
		par1->right=NULL;
		printf("\n data %d is deleted",num);
		free(d);
	}
	else if(d->left!=NULL && d->right!=NULL)
	{
		par2=d;
		d=d->right;
		printf("\n Data %d is deleted",num);
		if(d->left==NULL)
		{
			if(par1->left==par2)
			par1->left=d;
			else
			par1->right=d;
			
			d->left=par2->left;
			free(par2);
		}
		else
		{
			while(d->left!=NULL)
			{
				par1=d;
				d=d->left;
			}
			par1->left=d->right;
			par2->data=d->data;
			free(d);
		}
	}
	else if(d->left==NULL && d->right!=NULL)
	{
		par2=d;
		d=d->right;
		if(d->left==NULL)
		{
			par1->right=d;
			printf("\n Data %d is deleted",num);
			free(par2);
		}
		else
		{
			while(d->left!=NULL)
			{
				par1=d;
				d=d->left;
			}
			par1->left=d->right;
			par2->data=d->data;
			printf("\n Data %d is deleted",num);
			free(d);
		}
	}
	else if(d->left!=NULL && d->right==NULL)
	{
		if(par1->left==d)
		par1->left=d->left;
		else if(par1->right==d)
		par1->right=d->left;
		printf("\n Data %d is deleted",d->data);
		free(d);
	}
}
