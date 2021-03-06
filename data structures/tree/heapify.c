//program for max heap
#include<stdio.h>
int n;
int parent(int i)
{
	return(i/2);
}
int left(int i)
{
	return(2*i);
}
int right(int i)
{
	return((2*i)+1);
}
int* max_heapify(int*,int);
int main()
{
	int ar[10],i,temp;
	printf("Enter the size:");
	scanf("%d",&n);
	printf("\nEnter the elements now:");
	for(i=1;i<=n;i++)
	scanf("\n%d",&ar[i]);
	for(i=n/2;i>0;i--)
	{
		max_heapify(ar,i);
	}
	printf("\nThe elements after heapify are now:");
	for(i=1;i<=n;i++)
	printf("\n%d",ar[i]);
	return 0;
}
int * max_heapify(int a[],int i)
{
	int l,r,largest,temp;
	l=left(i);
	r=right(i);
	if(l<=n && a[l]>a[i])
	largest=l;
	else
	largest=i;
	if(r<=n && a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest);	
	}
}
	
