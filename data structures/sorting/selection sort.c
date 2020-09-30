//selecction sort in ascending order
/* basically it finds the smallest element by comparing with all
	 and then swaps it with the starting value of the rest unsorted elements*/
#include<stdio.h>
int main()
{
	int a[50],i,j,n,min,temp;
	printf("\nEnter the size of the array:");
	scanf("%d",&n);
	printf("\nNow enter the elements:");
	for(i=0;i<n;i++)
	scanf("\n%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		min=i;						//initializing minimum value
		for(j=i+1;j<n;j++)			
		{
			if(a[min]>a[j])			//comparing with the rest values to find min
			min=j;
		}
		temp=a[i];					//swaping the minimum element i.e. sorting
		a[i]=a[min];
		a[min]=temp;
	}
	printf("\nprinting the sorted elements:");
	for(i=0;i<n;i++)
	printf("\n%d",a[i]);
	return 0;
}
/* output:
	enter the size of array:5
	Now enter the elements:
	3,1,2,4,5,
	printing the sorted elements:
	1
	2
	3
	4
	5
*/
