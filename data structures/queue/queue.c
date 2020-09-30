#include<stdio.h>
#include<stdlib.h>
#define max 10
int q[max],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main()
{
	int n=1,ch;
	while(n>0)
	{
		printf("\n\nQUEUE Operations:\n");
		printf("0.To exit \n");
		printf("1.Enqueue:\n");
		printf("2.Dequeue:\n");
		printf("3.Display:\n");
		scanf("%d",&n);
		if(n==1)
		enqueue();
		else if(n==2)
		dequeue();
		else if(n==3)
		display();
		else
		printf("\nInvalid choice\n");
	}
	return 0;
}
void enqueue()
{
	if(rear==max-1)
	printf("Queue is full");
	else 
	{
		if(front==-1)
		{
			front++;
		}
		printf("\nEnter value:");
		scanf("%d",&q[++rear]);
	}
}
void dequeue()
{
	if(front==-1)
	printf("\nQueue is empty");
	else
	{
		printf("value %d is deleted",q[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		q[front++];
	}
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
	printf("%d ",q[i]);
}
