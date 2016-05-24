#include <stdio.h>
#include<time.h>
void dij(int src,int dest,int n,int cost[n][n],int dist[n])
{
	
	int i,j,min;
	int visit[n];
	int start=src;
	for(i=0;i<n;i++)
	{
		visit[i]=0;
		dist[i]=cost[start][i];
	}
	
	visit[start]=1;
	dist[start]=1000000;
	int prev[n];
	int temp=1;
	for(i=0;i<n;i++)
		prev[i]=0;
	
	
	
	for(i=0;i<n;i++)
	{
		min=0;
		while(visit[min]==1)
			min++;
		
		for(j=0;j<n;j++)
		{
			if(dist[j]<dist[min] && !visit[j] )
			{
				min=j;	
				
			}
		}
		printf("min:%d\n",min);
		
		visit[min]=1;
		
		
		
		for(j=0;j<n;j++)
		{
			if(dist[j]>cost[min][j]+dist[min])
			{
				dist[j]=cost[min][j]+dist[min];
				prev[j]=min;
				printf("%d\n",min);
				
			}		
		}
		
		if(min==dest)
		{
			for(i=0;i<n;i++)
				printf("%d prev: %d \n",i,prev[i]);
			printf("\n");
			break;
		}
	}
}

void main()
{
	clock_t t;
	t=clock();
	int n;
	scanf("%d",&n);
	int cost[n][n];
	int dist[n];
	int i,j;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=1000000;
		}
	
	int src,dest;
	scanf("%d",&src);
	scanf("%d",&dest);
	
	dij(src,dest,n,cost,dist);

	
	printf("\nCost: %d\n",dist[dest]);
	t=clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	time_taken=time_taken*1000000;
	printf("%f",time_taken);
}
