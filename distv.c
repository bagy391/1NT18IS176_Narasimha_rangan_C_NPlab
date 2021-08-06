#include<stdio.h>
struct node
{
	unsigned cost[20];
	unsigned from[20];
}router[10];
int main()
{
int dmat[20][20];
int n,i,j,k,count=0;
printf("\nEnter the number of nodes: ");
scanf("%d",&n);
printf("\nEnter the cost matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
	scanf("%d",&dmat[i][j]);
	dmat[i][i]=0;
	router[i].cost[j]=dmat[i][j];
	router[i].from[j]=j;
}
do
{
count=0;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		for(k=0;k<n;k++)
		{
			if(router[i].cost[j]>dmat[i][k]+router[k].cost[j])
			{
				router[i].cost[j]=router[i].cost[k]+router[k].cost[j];
				router[i].from[j]=k;
				count++;
			}
		}
	}
}
}while(count!=0);
for(i=0;i<n;i++)
{
	printf("\n\nState value for router %d is \n",i+1);
	printf("\nNode \t Via \t cost. ");
	for(j=0;j<n;j++)
	{
		printf("\n%d \t %d \t %d ",j+1,router[i].from[j]+1,router[i].cost[j]);
	}
}
printf("\n\n");
printf("Final Cost Matrix\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d \t",router[i].cost[j]);
	}
printf("\n");
}

}
