//STACK PROGRAM with structures
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
struct stack
{
	int *d;
	int top;
	int size;
}s;
void push();
void pop();
void display();
int main()
{
	int ch=1;
	s.top=-1;
	printf("Stack Operations:\n");
	printf("enter the size of stack: ");
	scanf("%d",&s.size);
	s.d=(int *)malloc((s.size)*sizeof(int));
	while(ch)
	{
		printf("\n enter ur choice:");
		printf("\n1.push data into stack");
		printf("\n2.Pop data from stack");
		printf("\n3.To display the stack");
		printf("\n0.To Exit: ");
		scanf("%d",&ch);
		if(ch==1)
			push();
		else if(ch==2)
			pop();
		else if(ch==3)
			display();
		else
			printf("\nWrong choice");
	}
	return 0;
}

void push()
{
	if(s.top==s.size-1)
	{
		printf("\nStack overflow\n");
		sleep(2);
	}
	else
	{
		printf("\n Enter the data:");
		scanf("%d",&s.d[++s.top]);
	}
}
void pop()
{
	if(s.top==-1)
	{
		printf("\n Stack Underflow");
		sleep(2);
	}
	else
	{
		printf("\nThe data %d is deleted",s.d[s.top--]);
	}
}
void display()
{
	int i;
	printf("\nthe datas of stack are:");
	for(i=s.top;i>-1;i--)
	printf("\n %d",s.d[i]);
}
