//having 2 stacks in a single array
#include<stdio.h>
int size,top1,top2,stack[100];
void push1();
void push2();
void pop1();
void pop2();
void display();
int main()
{
	int ch,n;
	printf("\tStack Operations:\n\n");
	printf("enter the size of stack:");
	scanf("%d",&size);
	top1=-1;
	top2=size;
	c:
		printf("\n enter ur choice:");
		printf("\n1.push data into stack1");
		printf("\n2.push data into stack2");
		printf("\n3.Pop data from stack1");
		printf("\n4.Pop data from stack2");
		printf("\n5.To display the stack: ");
		scanf("%d",&ch);
		if(ch==1)
		push1();
		else if(ch==2)
		push2();
		else if(ch==3)
		pop1();
		else if(ch==4)
		pop2();
		else if(ch==5)
		display();
		else
		printf("\nWrong choice");
		printf("\ndo you want to continue y=1 n=0: ");
		scanf("%d",&n);
		if(n==1)
		goto c;
		else
		exit(0);
	return 0;
}
void push1()
{
	if(top1==top2-1)
	{
		printf("\nStack1 overflow");
		sleep(2);
	}
	else
	{
		printf("\n Enter the data:");
		scanf("%d",&stack[++top1]);
	}
}
void push2()
{
	if(top1==top2-1)
	{
		printf("\nStack2 overflow");
		sleep(2);
	}
	else
	{
		printf("\n Enter the data:");
		scanf("%d",&stack[--top2]);
	}
}
void pop1()
{
	if(top1==-1)
	{
		printf("\n Stack1 Underflow");
		sleep(1);
	}
	else
	{
		printf("\nThe data %d is deleted",stack[top1--]);
	}
}
void pop2()
{
	if(top2==size)
	{
		printf("\n Stack2 Underflow");
		sleep(1);
	}
	else
	{
		printf("\nThe data %d is deleted",stack[top2++]);
	}
}
void display()
{
	int i,j;
	printf("\nthe datas of stack are:\n");
	printf("\nStack1:");
	for(i=top1;i>-1;i--)
	printf("\n %d",stack[i]);
	printf("\nStack2:");
	for(j=top2;j<size;j++)
	printf("\n %d",stack[j]);
}
