//Normal stack operations
#include<stdio.h>
int stack[20],size,top=-1;
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
	if(top==size-1)
	{
		printf("Stack overflow");
		sleep(2);
	}
	else
	{
		printf("\nEnter data: ");
		scanf("%d",&stack[++top]);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\nStack underflow");
		sleep(2);
	}
	else
	printf("\nTHe data %d is deleted",stack[top--]);
}
void display()
{
	int i;
	printf("\nThe data of stack are:\n");
	for(i=top;i>-1;i--)
	printf("%d\n",stack[i]);
}
