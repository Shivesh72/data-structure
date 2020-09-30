//INSERTION SORT 
/* here the array is divided into two parts sorted and unsorted
	loop from i=1 to n and we pick  element a[i] and insert it into sorted sequence
	what we do is first we let a[0] is sortd array and we check a[1] and see if it 
	is smaller then we first move sorted array one step forward making space for 
	a[1] and then insert a[1] at right place.   here let 0 as n and 1 as n+1.
*/
#include<stdio.h>
void display(int*,int);
int main()
{
	int a[10],n,key,j,i;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements now:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//now sorting the array
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;							//last element of sorted array
		while(j>=0 && a[j]>key)			//now comparing sorted elements with the key and
		{								//shifting forward the elements to insert the key 
			a[j+1]=a[j];				//at proper position
			j=j-1;
		}
		a[j+1]=key;
	}
	//now display sorted array
	display(a,n);
}
void display(int ar[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",ar[i]);
}
/* output:
	enter theno.of elements:5
	enter the elements now:
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
