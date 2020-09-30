//binary serach works on sorted nos.
#include <stdio.h> 
int binarySearch(int arr[], int l, int high, int x) 
{ 
	while (l <= high) 
	{ 
		int m;
		m= l + (high - l) / 2; 
		if (arr[m] == x) 
			return m; 
		if (arr[m] < x) 
			l = m + 1;
		else
			high = m - 1; 
	} 
	return -1; 
} 

int main() 
{ 
	int arr[50],n,num,i; 
	printf("Enter the size of the array ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the %d element:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the no. to search:");
	scanf("%d",&num);
    i=binarySearch(arr, 0, n - 1, num); 
	(i==-1)?printf("Element is not present in array") : printf("Element is present at index %d",i);
    return 0; 
} 

