//circular QUeue
#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main()
{
	int n=1,ch;
	while(n)
	{
		printf("\nQUEUE Operations:\n");
		printf("0.to exit\n");
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
	int a;
	if((front==0 && rear==max-1) || ((front-rear)==1))
	printf("Queue is full");
	else 
	{
		if(front==-1)
		{
			front=0;
		}
		else if(rear==max-1 && front>0)
		rear=-1;
		printf("\nEnter value:");
		scanf("%d",&a);
		q[++rear]=a;
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
		else if(front==max)
			front=0;
		else
		front++;
	}
}
void display()
{
	int i;
	if(rear<front)
	{
		for(i=front;i<max;i++)
		printf("%d ",q[i]);
		for(i=0;i<=rear;i++)
		printf("%d ",q[i]);
	}
	else
	{
		for(i=front;i<=rear;i++)
		printf("%d ",q[i]);
	}
}
