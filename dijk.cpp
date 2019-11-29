#include<iostream>
using namespace std;
#define V 20
#define INF 9999

void dijk(int graph[][V],int n)
{

	int dist[n+1];
	for(int j=1;j<=n;j++)
		dist[j]=graph[1][j];
		
	int vis[n+1];
	for(int j=1;j<=n;j++)
		vis[j]=0;
		
	dist[0]=0;
	vis[0]=1;
	int count = 1,u;
	
	while(count!=n)
	{
		int min=9999;
		for(int j=1;j<=n;j++)
			if(dist[j]<min && vis[j]!=1)
			{
				min = dist[j];
				u=j;
			}
		vis[u]=1;
		count++;
		for(int j=1;j<=n;j++)
		{
			if(min + graph[u][j]<dist[j] && vis[j]!=1)
				dist[j]=min + graph[u][j];
		}
	}
	
	cout<<"Shortest Distance is : \n";
	for(int j=1;j<=n;j++)
		cout<<"1 "<<j<<" "<<dist[j]<<endl;
}

int main()
{
	int n;
	cout<<"Enter the value of vertex : ";
	cin>>n;
	
	cout<<"Enter the matrix\n";
	int graph[V][V];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>graph[i][j];
	dijk(graph,n);
}
