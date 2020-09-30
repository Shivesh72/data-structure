//conversion of infix to postfix
#include<stdio.h>
int prec(char);
int main()
{
	char stack[15],postfix[30],exp[30];
	int i,top=-1,j=0;
	printf("Enter the expression in infix:");
	scanf("%s",&exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if((exp[i]>=65 && exp[i]<=90) || (exp[i]>=97 && exp[i]<=122))
		 postfix[j++]=exp[i];
		 else
		 {
		 	if(exp[i]=='(')
		 	stack[++top]='(';
		 	else if(exp[i]==')')
		 	{
		 		while(stack[top]!='(')
		 		{
		 			postfix[j++]=stack[top--];	
				}
				 stack[top--];
			 }
			 else
			 {
			 	while(stack[top]>-1 && (prec(stack[top])>=prec(exp[i])))
		 		{
		 			postfix[j++]=stack[top--];
				 }
				 stack[++top]=exp[i];
			 }
		 }
	}
	 while(stack[top]!=-1)
		 postfix[j++]=stack[top--];
	postfix[j]='\0';
	printf("\n the postfix expression is:\n");
	puts(postfix);
	return 0;
}
int prec(char a)
{
	if(a=='*' || a=='/')
	return 2;
	else if(a=='+' || a=='-')
	return 1;
	else if(a=='^')
	return 3;
	else
	return -1;
}

/* INPUT:-(a+b*c-d/e)
output:-abc*+de/-
*/
