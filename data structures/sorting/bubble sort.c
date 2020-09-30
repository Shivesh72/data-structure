//bubble sort in ascending order
/* it repeatedly swaps the adjacent elements if they are in wrong order.
	like taking first element and then comparing with the next if not in order
	 then swaps then with third .
	 basically it first takes the largest element to the last then the second largest 
	 (i.e. like it sorts from backwards.) 
*/

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
		
		for(j=0;j<n-i-1;j++)			
		{
			if(a[j]>a[j+1])			//comparing with the adjacent value to find min
			{
				temp=a[j];					//swaping the element i.e. sorting
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
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
/* average and worst case time complexity:o(n^2)
	best case:o(n) if it is already sorted
	*/
