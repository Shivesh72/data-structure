#include<stdio.h>
int main() 
{ 
    int arr[50],n,num,i,f=0; 
	printf("Enter the size of the array ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the %d element:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the no. to search:");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(arr[i]==num)
		{
			f=1;
			printf("Element is present at index %d",i);
		}
	}
	if(f==0)
	printf("Element is not present in array");
}
