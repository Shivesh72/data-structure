#include<stdio.h>
#include<stdlib.h>
#define vertex 6
struct node
{
	int data;
	struct node *next;
};
struct node *head[vertex];
void display();
void insert(int v1,int v2)
{
	struct node *temp,*temp1;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=v2;
	temp->next=NULL;
	if(head[v1]==NULL)
	{
		temp1=(struct node *)malloc(sizeof(struct node));
		temp1->data=v1;
		temp1->next=temp;
		head[v1]=temp1;
	}
	else
	{
		temp1=head[v1];
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
}
int main()
{
	int i,a,b,v,e;
	FILE *fp;
	for(i=0;i<vertex;i++)
	head[i]=NULL;
	fp=fopen("file2.txt","r");
	if(fp==NULL)
	{
		printf("\n Unable to open file");
		exit(0);
	}
	fscanf(fp,"%d%d",&v,&e);
	for(i=1;i<=2*e;i++)
	{
		fscanf(fp,"%d %d",&a,&b);
		insert(a,b);
	}
	display();
	return 0;
}
void display()
{
	struct node *temp;
	int i;
	for(i=1;i<vertex;i++)
	{
		temp=head[i];
		if(temp==NULL)
		printf("\nNothing to print");
		else
		{
			while(temp!=NULL)
			{
				printf("%d\t",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}
	}
}
/*
output:-
1		2		5
2		1		3
3		4		2
4		3		5
5		4		1
*/
