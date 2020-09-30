#include<stdio.h>
int q[10],front=-1,rear=-1;
void Enqueue(int);
int dequeue();
void display();
int main()
{
	int n;
	printf("QUEUE Operations:\n");
	Enqueue(5);
	Enqueue(10);
	Enqueue(15);
	Enqueue(20);
	display();
	n=dequeue();
	printf("\n Deleted %d\n",n);
	return 0;
}
void Enqueue(int a)
{
	if(front==-1)
	{
		front++;
	}
	q[++rear]=a;
}
int dequeue()
{
	int a;
	if(front==rear)
	{
		
		front=-1;
		rear=-1;
		return(q[front]);
	}
	a=q[front--];
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
	printf("%d ",q[i]);
}
