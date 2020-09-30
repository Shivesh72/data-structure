#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int count=0;
struct node *head;
void insert();
void insert_pos();
void delete_first();
void delete_last();
void delete_pos();
void delete_no();
void search();
void reverse();
void display();
int main()
{
 int n=1;
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
	 insert();
	 else if(n==2)
	 insert_pos();
	else if(n==3)
 	delete_first();
 	else if(n==4)
 	delete_last();
 	else if(n==5)
 	delete_pos();
 	else if(n==6)
 	delete_no();
 	else if(n==7)
 	search();
 	else if(n==8)
 	reverse();
 	else if(n==9)
 	{
 		if(count<0)
 		printf("\n No nodes present");
 		else
 		printf("\nThe no.of nodes are %d now",count);
	}
 	else if(n==10)
	display();
 	else
	printf("\nInvalid choice");
}
 return 0;
}
void insert()
{
	struct node *temp,*temp1=head;
	int num;
	count++;
	printf("\nEnter the data: ");
	scanf("%d",&num);
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	if(head==NULL)
	{
		temp->next=NULL;
		head=temp;
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp->next=NULL;
		temp1->next=temp;
	}
}
void insert_pos()
{
	struct node *temp,*temp1=head;
	int num,pos,i;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(pos>count+1 || pos<1)
	printf("\nwrong position");
	else
	{
		count++;
		printf("\nEnter the data: ");
		scanf("%d",&num);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num;
		if(pos==1)
		{
			temp->next=head;
			head=temp;
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				temp1=temp1->next;
			}
			temp->next=temp1->next;
			temp1->next=temp;
		}
	}
}
void delete_first()
{
	struct node *temp;
	if(count==0)
	printf("\nempty list");
	else
	{
		count--;
		temp=head;
		head=head->next;
		printf("\nThe data %d is deleted",temp->data);
		free(temp);
	}
}
void delete_last()
{
	struct node *temp,*temp1=head;
	temp=head;
	if(count==0)
	printf("\nempty list");
	else
	{
		count--;
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=NULL;
		if(count==0)
		head=NULL;
		printf("\nThe data %d is deleted",temp->data);
		free(temp);
	}
}
void delete_pos()
{
	struct node *temp,*temp1;
	int pos,i;
	if(count==0)
	printf("\nempty stack");
	else
	{
		temp=head;
		printf("\nEnter the position: ");
		scanf("%d",&pos);
		if(pos>count)
		printf("\nwrong position");
		else if(pos==1)
		delete_first();
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
}
void delete_no()
{
	struct node *temp,*temp1;
	int num,f=0,c=1;
	if(count==0)
	printf("\nempty stack");
	else
	{
		temp=head;
		temp1=head;
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
}
void search()
{
	struct node *temp;
	int num;
	temp=head;
	int c=1,f=0;
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
void display()
{
	struct node *temp;
	temp=head;
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
void reverse()
{
	struct node *temp,*temp1,*prev=NULL;
	temp=head;
	while(temp!=NULL)
	{
		temp1=temp->next;
		temp->next=prev;
		prev=temp;
		temp=temp1;
	}
	printf("\n the list is reversed now");
	head=prev;
}

