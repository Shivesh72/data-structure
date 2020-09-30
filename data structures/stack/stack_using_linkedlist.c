//STACK USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
int size,count=0;
void push();
void pop();
void display();
int main()
{
	int ch=1;
	printf("Stack operations:");
	printf("\nEnter the size of stack:");
	scanf("%d",&size);
	while(ch)
	{
		printf("\n\n1.To push data");
		printf("\n2.To pop data");
		printf("\n3.To display data");
		printf("\n0.To exit: ");
		scanf(" %d",&ch);
		if(ch==1)
		push();
		else if(ch==2)
		pop();
		else if(ch==3)
		display();
		else
		printf("\nInvalid choice\n");
	}
	return 0;
}
void push()
{
	struct node *temp;
	int num;
	if(count==size)
	{
		printf("\n stack overflow");
	}
	else
	{
		printf("\nEnter the data: ");
		scanf("%d",&num);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=head;
		head=temp;
		count++;
	}
}
void pop()
{
	struct node *temp;
	if(count==0)
	printf("\n stack underflow");
	else
	{
		count--;
		temp=head;
		head=head->next;
		printf("\nThe data %d is deleted",temp->data);
		free(temp);
	}
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
