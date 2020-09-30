#include<stdio.h>
#include<stdlib.h>
struct avl
{
	struct avl *left;
	int data;
	struct avl *right;
	int h;
};
struct avl *del;
struct avl* insert(struct avl*,int);
struct avl* delet(struct avl*,int);
struct avl* balf(struct avl*);
int height(struct avl*);
int main()
{
	struct avl *p=NULL;
	int n=1,num;
	while(n)
	{
		printf("\n\n1.to insert data");
		printf("\n2.to display");
		printf("\n3.to delete data");
		printf("\n0.to exit");
		printf("\nenter your choice");
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
			p=delet(p,num);
		}
		else
		printf("\nInvalid choice enter again");
	}
	return 0;
}
struct avl* insert(struct avl *q,int num)
{
	if(q==NULL)
	{
		q=(struct avl *)malloc(sizeof(struct avl));
		q->left=NULL;
		q->right=NULL;
		q->data=num;
		q->h=1;
		return q;
	}
	else if(q->data>num)
	{
		q->left=insert(q->left,num);
		q->h=height(q);
		return (balf(q));
	}
	else
	{
		q->right=insert(q->right,num);
		q->h=height(q);
		return (balf(q));
	}
}
int height(struct avl *p)
{
	int max=0;
	if(p->left==NULL && p->right==NULL)
	max=1;
	else if(p->left==NULL)
	max=p->right->h+1;
	else if(p->right==NULL)
	max=p->left->h+1;
	else 
	{
		max=(p->left->h<p->right->h)?p->right->h+1: p->left->h+1;
	}
	return max;
}
struct avl* balf(struct avl *p)
{
	struct avl *y,*x;	
	int bf=0;
	if(p->h==1)
	return p;
	if(p->right==NULL)
	{
		bf=p->left->h;
		y=p->left;
		x=y->left;
	}
	else if(p->left==NULL)
	{
		bf=p->right->h;
		y=p->right;
		x=y->right;
	}
	else 
	{
		y=p->left->h < p->right->h ? p->right : p->left;
		if(y->left!=NULL && y->right!=NULL)
		x=y->left->h < y->right->h ? y->right : y->left;
		bf=abs(p->left->h - p->right->h);
	}
	if(bf>1)
	{
		if(y==p->left && x==y->left)//leftleft case-Right rotation			
		{
			p->left=y->right;
			y->right=p;
			p->h=height(p);
			y->h=height(y);
			p=y;
		}
		else if(y==p->right && x==y->right)//rr case-left rotation
		{
			p->right=y->left;
			y->left=p;
			p->h=height(p);
			y->h=height(y);
			p=y;
		}
		else if(y==p->left && x==y->right)  //lR case, left then right rotation
		{
			p->left=x;
			y->right=x->left;
			x->left=y;
			y->h=height(y);
			//x->h=height(x);
			p->left=x->right;
			x->right=p;
			p->h=height(p);
			x->h=height(x);
			p=x;
		}
		else if(y==p->right && x==y->left)  //RL case-right then left rotation
		{
			p->right=x;
			y->left=x->right;
			x->right=y;
			y->h=height(y);
		//	x->h=height(x);
			p->right=x->left;
			x->left=p;
			p->h=height(p);
			x->h=height(x);
			p=x;
		}
	}
	return p;	
}
void display(struct bst *p)
{
	int num;
	if(p==NULL)
	printf("\ntree is empty");
	else
	{
		printf("\nenter 1 for preorder");
		printf("\nenter 2 for postorder");
		printf("\nenter 3 for inorder");
		printf("\nenter your choice,by default inorder traversal will be shown:\n");
		scanf("%d",&num);
		if(num==1)
		{
			preorder(p);
		}
		else if(num==2)
		{
			postorder(p);
		}
		else 
		inorder(p);
	}
}
preorder(struct avl *q)
{
	
	printf("\t%d",q->data);
	if(q->left!=NULL)
	preorder(q->left);
	if(q->right!=NULL)
	preorder(q->right);
}
postorder(struct avl *q1)
{
	
	if(q1->left!=NULL)
	postorder(q1->left);
	if(q1->right!=NULL)
	postorder(q1->right);
	printf("\t%d",q1->data);
}
inorder(struct avl *q2)
{
	
	if(q2->left!=NULL)
	inorder(q2->left);
	printf("\t%d",q2->data);
	if(q2->right!=NULL)
	inorder(q2->right);
}
struct avl* delet(struct avl *d,int num)
{
	struct avl *par1;
	if(d==NULL)
	{
		printf("\n data not found in tree");
		return d;
	}
	else if(num>d->data)
	{
		d->right=delet(d->right,num);
		d->h=height(d);
		return (balf(d));
	}
	else if(num<d->data)
	{
		d->left=delet(d->left,num);
		d->h=height(d);
		return (balf(d));
	}
	else
	{
		if(d->right==NULL)
		{
			par1=d->left;
			printf("\ndata %d is deleted",num);
			free(d);
			return par1;
		}
		else
		{
			del=d;
			par1=d->right;
			if(par1->left==NULL)
			del->right=par1->right;
			del->data=del2(par1);
			printf("\n dta %d is deleted and %d is retrieved",num,d->data);
			d->h=height(d);
			return (balf(d));
		}	
	}
}
int del2(struct avl *d1)
{
	struct avl *par2;
	int num;
	if(d1->left==NULL)
	{
		num=d1->data;
		printf("\n data is delted");
		free(d1);
		return num;	
	}
	else if(d1->left->left==NULL)
	{
		par2=d1->left;
		d1->left=par2->right;
		num=par2->data;
		free(par2);
		d1->h=height(d1);
		del->right=(balf(d1));		//we have to store it in its parent node after rotation 
		return num;
	}
	num=del2(d1->left);
	d1->h=height(d1);
	del->right=balf(d1);
	return num;
}
