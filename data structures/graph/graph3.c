#include<stdio.h>
#include<stdlib.h>
#define vertex 6
#define edge 15
int v,e,arr[vertex][vertex]={0},a[vertex],adj[vertex][vertex];
//arr represents matrix display,,adj represents adjacent vertex in list,,
//a contains the no. of vertex joined to each vertex
int main()
{
	int i,j,x,y;
	FILE *fp;
	fp=fopen("file3.txt","r");
	if(fp==NULL)
	{
		printf("\n Unable to open file");
		exit(0);
	}
	fscanf(fp,"%d%d",&v,&e);
	for(i=1;i<=v;i++)
		a[i]=0;
	for(i=1;i<=e;i++)
	{
		fscanf(fp,"%d %d",&x,&y);
		arr[x][y]=1;
		arr[y][x]=1;
		adj[x][a[x]++]=y;
		adj[y][a[y]++]=x;
	}
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nadjacency list format:\n");
	for(i=1;i<=v;i++)
	{
		printf("%d\t",i);
		for(j=0;j<a[i];j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	return 0;
}
