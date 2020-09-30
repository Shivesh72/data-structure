//program for evaluation of postfix expression
#include<stdio.h>
int isoperand(char);
int main()
{
	char exp[30];
	int i,stack[15],top=-1,a,b;
	printf("Enter the expression in postfix:");		//expression should  be numeral
	scanf("%s",&exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isoperand(exp[i]))
		 stack[++top]=((exp[i])-'0');
		 else
		 {
		 	a=stack[top--];
		 	b=stack[top--];
		 	switch (exp[i])
		 	{
			 
		 		case '+':
		 			stack[++top]=a+b;
		 			break;
		 		case '-':
		 			stack[++top]=a-b;
		 			break;
		 		case '*':
		 			stack[++top]=a*b;
		 			break;
		 		case '/':
		 			stack[++top]=a/b;
		 			break;
		 		default:
		 			printf("\nstill not defined operator");
		 				break;
		 	}
			
		 }
	}
	printf("the result of the expressionis: %d",stack[top]);
	return 0;
}
int isoperand(char ch)
{
	if(ch>=48 && ch<=57)
	return 1;
	else
	return 0;
}
/* INPUT:-567/+2- as 5+6/3-2
	OUTPUT:- 5
*/
