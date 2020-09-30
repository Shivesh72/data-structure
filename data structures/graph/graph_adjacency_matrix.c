#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[20][20]={0},i,j,a,b,v,e=4;
	FILE *fp;
	fp=fopen("file1.txt","r");
	if(fp==NULL)
	{
		printf("\n Unable to open file");
		exit(0);
	}
	fscanf(fp,"%d%d",&v,&e);
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d %d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	for(i=0;i<e;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
output:-
0		1		0		1
1		0		1		0
0		1		0		1
1		0		1		0
*/
