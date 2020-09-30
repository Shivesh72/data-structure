#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int count=0;
struct node* insert(struct node*);
struct node* insert_pos(struct node*);
struct node* delete_first(struct node*);
struct node* delete_last(struct node*);
struct node* delete_pos(struct node*);
struct node* delete_no(struct node*);
void search(struct node*);
struct node* reverse(struct node*);
void display(struct node*);
int main()
{
 int n=1;
 struct node *head=NULL;
 while(n)
 {
	printf("\n\nEnter ur choice:");
	printf("\n1.to add");
 	printf("\n2.To add data at any pos.");
	printf("\n3.To delete a node from begining:");
	printf("\n4.to delete a node from last");
	printf("\n5.to delete a node from any position");
	printf("\n6.to delete a node by no.:");
	printf("\n7.to search a data");
	printf("\n8.to reverse the whole list");
	printf("\n9.Total no.of nodes present");
	printf("\n10.To display data:");
	scanf("%d",&n);
	if(n==1)
	head=insert(head);
	else if(n==2)
	head=insert_pos(head);
	else if(n==3)
 	head=delete_first(head);
 	else if(n==4)
 	head=delete_last(head);
 	else if(n==5)
 	head=delete_pos(head);
 	else if(n==6)
 	head=delete_no(head);
 	else if(n==7)
 	search(head);
 	else if(n==8)
 	head=reverse(head);
 	else if(n==9)
 	{
 		if(count<0)
 		printf("\n No nodes present");
 		else
 		printf("\nThe no.of nodes are %d now",count);
	}
 	else if(n==10)
	display(head);
 	else
	printf("\nInvalid choice");
}
 return 0;
}
struct node* insert(struct node *temp1)
{
	struct node *temp,*h=temp1;
	int num;
	count++;
	printf("\nEnter the data: ");
	scanf("%d",&num);
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	if(temp1==NULL)
	{
		return(temp);
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		return h;
	}
}
struct node* insert_pos(struct node *temp1)
{
	struct node *temp,*head=temp1;
	int num,pos,i;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(pos>count+1)
	{
		printf("\nWrong position");
		return(temp1);
	}
	else
	{
		count++;
		printf("\nEnter the data: ");
		scanf("%d",&num);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num;
		if(pos==1)
		{
			temp->next=temp1;
			return(temp);
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				temp1=temp1->next;
			}
			temp->next=temp1->next;
			temp1->next=temp;
			return(head);
		}
	}
}
struct node* delete_first(struct node *temp1)
{
	struct node *temp;
	if(count==0)
	printf("\list is already empty");
	else
	{
		count--;
		temp=temp1;
		temp1=temp1->next;
		printf("\nThe data %d is deleted",temp->data);
		free(temp);
		if(count==0)
		temp1=NULL;
	}
	return(temp1);
}
struct node* delete_last(struct node *temp1)
{
	struct node *temp,*head=temp1;
	temp=temp1;
	if(count==0)
	printf("\nempty list");
	else
	{
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=NULL;
		printf("\nThe data %d is deleted",temp->data);
		free(temp);
		count--;
		if(count==0)
			return(NULL);
		
	}
	return(head);
}
struct node* delete_pos(struct node *temp1)
{
	struct node *temp,*head=temp1;
	int pos,i;
	if(count==0)
	printf("\nlist is empty");
	else
	{
		temp=head;
		printf("\nEnter the position: ");
		scanf("%d",&pos);
		if(pos>count)
		printf("\nwrong position");
		else if(pos==1)
		head=delete_first(temp1);
		else
		{
			count--;
			for(i=1;i<pos;i++)
			{
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=temp->next;
			printf("\nThe dta %d is deleted",temp->data);
			free(temp);
		}
	}
	return(head);
}
struct node* delete_no(struct node *temp1)
{
	struct node *temp,*head=temp1;
	int num,f=0,c=1;
	if(count==0)
	printf("\nempty list");
	else
	{
		temp=head;
		printf("\nEnter the no. u want to delete: ");
		scanf("%d",&num);
		while(temp!=NULL)
		{	
			if(temp->data==num)
			{
				if(c==1)
				{
					head=head->next;
				}	
				temp1->next=temp->next;
				printf("\nThe data %d is deleted",temp->data);
				free(temp);
				f=1;
				count--;
				break;
			}
			else
			{
				c++;
				temp1=temp;
				temp=temp->next;
			}
		}
		if(f==0)
		printf("\nThe data %d is not found",num);
	}
	return(head);
}
void search(struct node *temp)
{
	int num;
	int c=1,f=0;
	if(count==0)
	printf("\nempty list");
	else
	{
		printf("\nEnter the data to search: ");
		scanf("%d",&num);
		while(temp!=NULL)
		{
			if(temp->data==num)
			{
				printf("\n the data is present at %d pos.",c);
				f=1;
				break;
			}
			temp=temp->next;
			c++;
		}
		if(f==0)
		printf("\nThe data is not present");
	}
}
void display(struct node *temp1)
{
	struct node *temp=temp1;
	if(temp==NULL)
	printf("\nNothing to print");
	else
	{
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			printf("\n");
			temp=temp->next;
		}
	}
}
struct node* reverse(struct node *temp1)
{
	struct node *temp,*prev=NULL;
	temp=head;
	while(temp!=NULL)
	{
		temp1=temp->next;
		temp->next=prev;
		prev=temp;
		temp=temp1;
	}
	printf("\n the list is reversed now");
	return prev;
}

