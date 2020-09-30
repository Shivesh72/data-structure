//merge sort
/* it is a divide and conquer algorithm.it divides input array into two halves,
	calls itself for the two halves repeatedly repeating and then merge the two sorted
	 halves.the merge() function is used for merging two halves.
 */
#include<stdio.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);
int main()
{
	int a[50],i,j,n,l=0,r;
	printf("\nEnter the size of the array:");
	scanf("%d",&n);
	r=n-1;
	printf("\nNow enter the elements:");
	for(i=0;i<n;i++)
	scanf("\n%d",&a[i]);
	mergesort(a,l,r);
	printf("\nprinting the sorted elements:");
	for(i=0;i<n;i++)
	printf("\n%d",a[i]);
	return 0;
}
void mergesort(int ar[],int l,int r)
{
	int m;
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(ar,l,m);
		mergesort(ar,m+1,r);
		merge(ar,l,m,r);
	}
}
void merge(int arr[],int l,int m,int r)
{
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=r-m;
	int a1[n1],a2[n2];
	for(i=0;i<n1;i++)
	a1[i]=arr[l+i];
	for(i=0;i<n1;i++)
	a2[i]=arr[m+1+i];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			arr[k++]=a1[i++];
		}
		else
		arr[k++]=a2[j++];
	}
	while(i<n1)
	{
		arr[k++]=a1[i++];
		
	}
	while(j<n2)
	{
		arr[k++]=a2[j++];
	}
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
