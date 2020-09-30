#include<stdio.h>
#include<stdlib.h>
#define vertex 7
//0 for white,2 for black,1 for gray
struct node
{
	int color;
	int par;
	int d;		//discovery time
	int f;		//finish time
};
struct node u[vertex];
int v,e,arr[vertex][vertex]={0},a[vertex],adj[vertex][vertex],time;
int main()
{
	int i,j,x,y;
	FILE *fp;
	fp=fopen("file4.txt","r");
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
	dfs();
	printf("\nAdjacency matrix:\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nAdjacency list:\n");
	for(i=1;i<=v;i++)
	{
		printf("%d\t",i);
		for(j=0;j<a[i];j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n\n");
	}
	for(i=1;i<vertex;i++)
	{
		printf("\n\nnode=%d,color=%d\npar=%d,arrivaltime=%d,finishtime=%d",i,u[i].color,u[i].par,u[i].d,u[i].f);
	}
	return 0;
}
dfs()
{
	int i;
	for(i=1;i<vertex;i++)
	{
		u[i].color=0;
		u[i].par=0;
	}
	time=0;
	for(i=1;i<vertex;i++)
	{
		if(u[i].color==0)
		dfs_visit(i);
	}
}
dfs_visit(int j)
{
	int i,k=0;
	struct node v;
	time++;
	u[j].d=time;
	u[j].color=1;
	while(k<vertex)
	{
		i=adj[j][k];
		if(i!=0)
		if(u[i].color==0)
		{
			u[i].par=j;
			dfs_visit(i);
		}
		k++;	
	}
	u[j].color=2;
	time=time+1;
	u[j].f=time;
}
