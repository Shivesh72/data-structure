//HEAPSORT program
#include<stdio.h>
int n,heapsize;
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
int* max_heapify(int a[],int i)
{
	int l,r,largest,temp;
	l=left(i);
	r=right(i);
	if(l<=heapsize && a[l]>a[i])
	largest=l;
	else
	largest=i;
	if(r<=heapsize && a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest);	
	}
}
void build_maxheap(int ab[])
{
	int i;
	heapsize=n;
	for(i=n/2;i>0;i--)
	max_heapify(ab,i);
}
void heapsort(int a[])
{
	int temp,i;
	build_maxheap(a);
	printf("\nThe elements after heapify are now:");
	for(i=1;i<=n;i++)
	printf("\n%d",a[i]);
	for(i=n;i>1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		heapsize=heapsize-1;
		max_heapify(a,1);
	}
}
int main()
{
	int ar[10],i,temp;
	printf("Enter the size:");
	scanf("%d",&n);
	printf("\nEnter the elements now:");
	for(i=1;i<=n;i++)
	scanf("\n%d",&ar[i]);
	heapsort(ar);
	printf("\nThe elements after heap sort are now:");
	for(i=1;i<=n;i++)
	printf("\n%d",ar[i]);
	return 0;
}	

