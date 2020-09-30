//addition and product of two algebra using linked list
#include<stdlib.h>
#include<stdio.h>
struct node
{
	int coeff;
	int pow;
	struct node *next;
};
void insert(struct node**,int,int);
void display(struct node*);
void add(struct node*,struct node*,struct node**);
void subtract(struct node*,struct node*,struct node**);
void multiply(struct node*,struct node*,struct node**);
int main()
{
	struct node *p1,*p2,*r,*m,*s;
	p1=NULL;
	p2=NULL;
	r=NULL;
	m=NULL;
	s=NULL;
	//inserting in polynomial p1
	insert(&p1,9,3);
	insert(&p1,2,2);
	insert(&p1,3,1);
	insert(&p1,8,0);
	//now inserting in polynomial p2
	insert(&p2,5,4);
	insert(&p2,2,1);
	insert(&p2,3,0);
	add(p1,p2,&r);							//adding both polynomial and storing in poly 'r'
	subtract(p1,p2,&s);					//subtracting both polynomial and storing in poly 's'
	printf("\nThe data of 1st expression are:\n");
	display(p1);
	printf("\nThe data of 2nd expression are:\n");
	display(p2);
	printf("\nThe data of after addition are:\n");
	display(r);
	printf("\nThe data of after subtraction are:\n");
	display(s);
	printf("\nThe data of after multiplication are:\n");
	multiply(p1,p2,&m);
	display(m);
	return 0;
}
void insert(struct node **temp,int c,int p)
{
	struct node *temp1,*temp2;
	int cn=1;
	temp1=(struct node *)malloc(sizeof(struct node));
	temp1->coeff=c;
	temp1->pow=p;
	temp1->next=NULL;
	if(*temp==NULL)
	{
		*temp=temp1;
	}
	else
	{
		temp2=*temp;
		while(temp2->next!=NULL)
		{
			if(temp2->pow==p)
			{
				temp2->coeff=(temp2->coeff+c);
				cn++;
				break;
			}
			temp2=temp2->next;
		}
		if(cn==1 && temp2->pow==temp1->pow)
		{
			temp2->coeff=(temp2->coeff+temp1->coeff);
			cn++;
		}
		if(cn==1)
		temp2->next=temp1;
	}
}
void add(struct node *q1,struct node *q2,struct node **s)
{
	
	while(q1!=NULL && q2!=NULL)
	{
		if(q1->pow>q2->pow)
		{
			insert(s,q1->coeff,q1->pow);
			q1=q1->next;
		}	
		else if(q1->pow<q2->pow)
		{
			insert(s,q2->coeff,q2->pow);
			q2=q2->next;
		}
		else
		{
			insert(s,(q1->coeff+q2->coeff),q1->pow);
			q1=q1->next;
			q2=q2->next;
		}	
	}	
	while(q1!=NULL)
	{
		insert(s,q1->coeff,q1->pow);
		q1=q1->next;
	}
	while(q2!=NULL)
	{
		insert(s,q2->coeff,q2->pow);	
		q2=q2->next;
	}
}
void subtract(struct node *q1,struct node *q2,struct node **s)
{
	while(q1!=NULL && q2!=NULL)
	{
		if(q1->pow>q2->pow)
		{
			insert(s,q1->coeff,q1->pow);
			q1=q1->next;
		}	
		else if(q1->pow<q2->pow)
		{
			insert(s,q2->coeff,q2->pow);
			q2=q2->next;
		}
		else
		{
		
			insert(s,(q1->coeff-q2->coeff),q1->pow);
			q1=q1->next;
			q2=q2->next;
		}	
	}	
	while(q1!=NULL)
	{
		insert(s,q1->coeff,q1->pow);
		q1=q1->next;
	}
	while(q2!=NULL)
	{
		insert(s,q2->coeff,q2->pow);	
		q2=q2->next;
	}
}
void multiply(struct node *f,struct node *s,struct node **pr)
{
	struct node *temp2;
	int c,p;
	while(f!=NULL)
	{
		temp2=s;
		while(temp2!=NULL)
		{
			c=f->coeff*temp2->coeff;
			p=f->pow+temp2->pow;
			insert(pr,c,p);
			temp2=temp2->next;
		}
		f=f->next;
	}	
}
void display(struct node *temp)
{
	if(temp==NULL)
	printf("\n list is empty\n");
	else
	{
		while(temp->next!=NULL)
		{
			printf("\t%dX%d",temp->coeff,temp->pow);
			temp=temp->next;
		}
		printf("\t%d",temp->coeff);
	}
}
/*
	The data of 1st expression are:
	9X3		2X2		3X1		8
	The data of 2nd expression are:
	5X4		2X1		3
	The data of after addition are:
	5X4		9X3		2X2		5X1		11
	The data of after subtraction are:
	5X4		9X3		2X2		1X1		5
	The data of after multiplication are:
	45X7	10X6	15X5	58X4	31X3	12X2	25X1	24
*/
