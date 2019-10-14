#include <bits/stdc++.h>
using namespace std;

int a[100][100],dist[10000];
vector <pair <int, int > >v[10000];
priority_queue <pair <int, int >, vector < pair <int, int > >, greater <pair <int ,int > > >pq;

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-smalloutput","w",stdout);
	int t,n,m,e,sr,sc,tr,tc,u,we,i,j,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d %d %d %d %d",&n,&m,&e,&sr,&sc,&tr,&tc);
		for(j=0;j<10000;j++)
		v[j].clear();
		for(j=0;j<n;j++)
		{
			for(k=0;k<m;k++)
				scanf("%d",&a[j][k]);
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<m;k++)
			{
				if(a[j][k]==-100000)
					continue;
				if(j>0 && a[j-1][k]!=-100000)
				{
					v[j*m+k].push_back(make_pair((j-1)*m+k,-a[j-1][k]));
				}
				if(k>0 && a[j][k-1]!=-100000)
				{
					v[j*m+k].push_back(make_pair(j*m+k-1,-a[j][k-1]));
				}
				if(j<n-1 && a[j+1][k]!=-100000)
				{
					v[j*m+k].push_back(make_pair((j+1)*m+k,-a[j+1][k]));
				}
				if(k<m-1 && a[j][k+1]!=-100000)
				{
					v[j*m+k].push_back(make_pair(j*m+k+1,-a[j][k+1]));
				}
			}
		}
		for(j=0;j<n*m;j++)
			dist[j]=100000000;
		dist[(sr-1)*m+(sc-1)]=0;
		pq.push(make_pair(0,(sr-1)*m+sc-1));
		while(!pq.empty())
		{
			u=pq.top().second;
			pq.pop();
			for(j=0;j<v[u].size();j++)
			{
				if(dist[v[u][j].first]>dist[u]+v[u][j].second)
				{
					dist[v[u][j].first]=dist[u]+v[u][j].second;
					pq.push(make_pair(dist[v[u][j].first],v[u][j].first));
				}
			}
		}
		/*for(j=0;j<n;j++)
		{
			for(k=0;k<m;k++)
				printf("%d ",dist[j*m+k]);
			printf("\n");
		}*/
		//printf("%d\n",dist[(tr-1)*m+tc]);
		if(dist[(tr-1)*m+(tc-1)]==100000000 || dist[(tr-1)*m+tc-1]>e)
			printf("Case #%d: -1\n",i);
		else
			printf("Case #%d: %d\n",i,e-dist[(tr-1)*m+tc-1]);
	}
	return 0;
}
