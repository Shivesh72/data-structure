#include<stdio.h>
#include<stdlib.h>
#define ver 9
#define size 20
//0 for white,1 for gray,2 for black
struct node
{
	int color;
	int par;
	int d;
};
struct node u[ver];
int front=-1,rear=-1,q[20];
int adj[ver][ver]={0},a[ver]={0},arr[ver][ver];
void enqueue(int d)
{
	if(rear==size)
	printf("\nqueue is full");
	else
	{	
		if(front==-1)
		front++;
		q[++rear]=d;	
	}
}
int dequeue()
{
	int n;
	if(front==-1)
	printf("\nQueue is empty");
	else
	{
		n=q[front];
		if(front==rear)
		{
			rear=-1;
			front=-1;
		}
		else
		front++;
		return n;
	}
	return 0;
}
void bfs(int s)
{
	int i,j,v;
	for(i=1;i<=ver;i++)
	{
		if(i==s)
		continue;
		u[i].color=0;
		u[i].d=10000;
		u[i].par=-1;
	}
	u[s].color=1;
	u[s].par=-1;
	u[s].d=0;
	enqueue(s);
	while(front!=-1)
	{
		j=dequeue();
		for(i=0;i<a[j];i++)
		{
			v=adj[j][i];
			if(u[v].color==0)
			{
				u[v].color=1;
				u[v].d=u[j].d+1;
				u[v].par=j;
				enqueue(v);
			}
		}
		u[j].color=2;
	}
}
int main()
{
	int i,j,x,y,v,e;
	FILE *fp;
	fp=fopen("file5.txt","r");
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
	printf("\nAdjacency list:\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nAdjacency matrix:\n");
	for(i=1;i<=v;i++)
	{
		printf("%d\t",i);
		for(j=0;j<a[i];j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	bfs(2);
	for(i=1;i<ver;i++)
	{
		printf("\n\nnode=%d,color=%d\npar=%d,arrivaltime=%d",i,u[i].color,u[i].par,u[i].d);
	}
	path(2,8);
	return 0;
}
path(int p,int q)
{
	int i,z=q;
	printf("\nthe path from 2 to 8 is:");
	printf("\n%d",z);
	for(i=0;i<=a[q];i++)
	{
		z=u[z].par;
		printf("\n%d",z);
	}
}
