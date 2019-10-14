#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LINT;
const int INF=2147483647;

int graph[10001][10001];
int x[100];
int v[100];

LINT dist[10001][10001];
bool visit[10001];

void main()
{

	int n,p,m;
	int t;
	
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		//input
		cin>>n>>p>>m;

		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				graph[i][j]=0;

		for(int i=0; i<p; i++)
			cin>>x[i]>>v[i];
		for(int i=0; i<m; i++)
		{
			int d;
			int l;
			cin>>d>>l;
			int pa,pb;
			cin>>pa;
			for (int j=1; j<l; j++)
			{
				cin>>pb;
				if(graph[pa][pb]==0 || d<graph[pa][pb])
					graph[pa][pb]=graph[pb][pa]=d;
				pa=pb;
			}
		}
	
		//shortest path
		for (int i=0; i<p; i++)
		{
			int s=x[i];
			
			for(int j=1; j<=n; j++)
			{
				dist[s][j]=(graph[s][j]>0 ? graph[s][j] : INF);
				visit[j]=false;
			}
			dist[s][s]=0;
			visit[s]=true;

			while(true)
			{
				int mindist=INF;
				int minpos=-1;
				for(int j=1; j<=n; j++)
				{
					if(!visit[j] && dist[s][j]<mindist)
					{
						minpos=j;
						mindist=dist[s][j];
					}
				}
				if(minpos==-1)
					break;

				visit[minpos]=true;
				dist[s][minpos]=mindist;
				for(int j=1; j<=n; j++)
					if(graph[minpos][j]>0)
						dist[s][j]=min(dist[s][j],dist[s][minpos]+graph[minpos][j]);
			}
		}

		//compute
		LINT minmaxt=-1;
		for(int j=1; j<=n; j++)
		{
			LINT maxt=-1;
			for(int i=0; i<p; i++)
				maxt=max(maxt,dist[x[i]][j]*v[i]);
			if(maxt>=INF)
				continue;
			if(minmaxt==-1)
				minmaxt=maxt;
			else
				minmaxt=min(minmaxt,maxt);
		}
		cout<<"Case #"<<ii+1<<": "<<minmaxt<<endl;
	}		
}