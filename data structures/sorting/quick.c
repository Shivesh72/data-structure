//quick sort
/* like merge sort, it is also a divide and conquer algorithm.it picks an element as pivot 
	and partitions the given array around the pivot point i.e. All smaller elements than 
	pivot before it and all larger elements than it after that and then again we partition
	as two pivot points from both sides.
	NOW PIVOT ELEMENT CAN BE PICKED BY MANY WAYS:
	1.first element as pivot
	2.last element as pivot(mostly taken)
	3.random element 
	4.median as pivot
*/
#include<stdio.h>
void quicksort(int [],int,int);
int partition(int [],int low,int high);
int main()
{
	int a[50],i,j,n,r;
	printf("\nEnter the size of the array:");
	scanf("%d",&n);
	r=n-1;
	printf("\nNow enter the elements:");
	for(i=0;i<n;i++)
	scanf("\n%d",&a[i]);
	quicksort(a,0,r);
	printf("\nprinting the sorted elements:");
	for(i=0;i<n;i++)
	printf("\n%d",a[i]);
	return 0;
}
void quicksort(int ar[],int low,int high)
{
	int pi;
	if(low<high)
	{
		pi=partition(ar,low,high);
		quicksort(ar,low,pi-1);
		quicksort(ar,pi+1,high);
	}
}
partition(int arr[],int low,int high)
{
	int pivot=arr[high],i=low-1,j,temp;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	temp=arr[high];
	arr[high]=arr[i+1];
	arr[i+1]=temp;
	return(i+1);
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
/*  average and worst case time complexity
	  and best case:0(nlogn) if it is already sorted
*/
