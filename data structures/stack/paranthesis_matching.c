//parenthesis matching
#include<stdio.h>
int main()
{
	char exp[30],stack[30],ch;
	int i,top=-1;
	printf("Enter the expression :");		
	scanf("%s",&exp);
	for(i=0;exp[i]!='\0';i++)
		{
			if(exp[i]=='(' ||exp[i]=='[' ||exp[i]=='{')
			stack[++top]=exp[i];
			else
			{
				ch=stack[top--];
				if((exp[i]==')' && ch=='(') ||(exp[i]==']' && ch=='[') ||(exp[i]=='}' && ch=='{'))
				continue;
				else
				{
					printf("\nwrong expression");
					exit(0);
				}
			}
		}
		if(top!=-1)
		{
			printf("\nwrong expression");
			exit(0);
		}
		else
		printf("\nBalanced parenthesis");
	return 0;
}
