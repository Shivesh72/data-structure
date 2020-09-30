#include<stdio.h>
int heapsize,length;
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
	return(2*i+1);
}
int * max_heapify(int a[],int i)
{
	int l,r,largest,temp;
	l=left(i);
	r=right(i);
	if(l<=heapsize && a[l]<a[i])
	largest=l;
	else
	largest=i;
	if(r<=heapsize && a[r]<a[largest])
	largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest);	
	}
}
void build_maxheap(int a1[])
{
	int i;
	heapsize=length;
	for(i=length/2;i>0;i--)
	max_heapify(a1,i);
}
int main()
{
	int a[30],i;
	printf("enter the size of array:");
	scanf("%d",&length);
	printf("\nENter the values of aray:\n");  	
	for(i=1;i<=length;i++)
	scanf("\n%d",&a[i]);
	build_maxheap(a);
	printf("\nAfter heapify the values are:");
	for(i=1;i<=length;i++)
	printf("\n%d",a[i]);
	printf("\nThe min element is :%d",extract_max(a));
	printf("\nAfter heapify the values are:");
	for(i=1;i<=length;i++)
	printf("\n%d",a[i]);
	insert(a,5);
	printf("\nAfter inserting the values are:");
	for(i=1;i<=length;i++)
	printf("\n%d",a[i]);
	insert(a,2);
	printf("\nAfter inserting the values are:");
	for(i=1;i<=length;i++)
	printf("\n%d",a[i]);
	increase(a,6,6);
	printf("\nAfter increasing the values are:");
	for(i=1;i<=length;i++)
	printf("\n%d",a[i]);
}
int extract_max(int a1[])
{
	int max;
	max=a1[1];
	a1[1]=a1[length];
	length=length-1;	
	heapsize=heapsize-1;
	max_heapify(a1,1);
	return max;
}
insert(int a2[],int v)
{
	int temp;
	length=length+1;
	a2[length]=v;
	while(length>1 && a2[length/2]<a2[length])
	{
		temp=a2[length];
		a2[length]=a2[length/2];
		a2[length/2]=temp;
		length=length/2;
	}
}
increase(int a3[],int i,int v)
{
	int temp;
	a3[i]=v;
	while(i>1 && a3[i/2]<a3[i])
	{
		temp=a3[i];
		a3[i]=a3[i/2];
		a3[i/2]=temp;
		i=i/2;
	}
}

