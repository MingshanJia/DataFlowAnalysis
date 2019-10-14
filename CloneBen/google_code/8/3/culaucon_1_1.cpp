#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int MOD=1000000007;

int n, m[1110], w[1110];
int a[1110][1110];
vector<int> mm[1110][1110], dd[1110][110], cc[1110][1110];
int dp[1110][1110];

int main()
{
	freopen("taking_metro.in","r",stdin);
	freopen("taking_metro.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--)
	{
		memset(a,-1,sizeof(a));
		for (int i=0;i<1110;i++)
			for (int j=0;j<1110;j++)
			{
				mm[i][j].clear();
				dd[i][j].clear();
				cc[i][j].clear();
			}
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>m[i]>>w[i];
			for (int j=0;j<m[i]-1;j++) scanf("%d", &a[i][j]);
		}
		int h;
		cin>>h;
		for (int i=0;i<h;i++)
		{
			int x, y, u, v, t;
			scanf("%d%d%d%d%d",&x,&y,&u,&v,&t);
			x--;y--;u--;v--;
			mm[x][y].push_back(u);
			mm[u][v].push_back(x);
			dd[x][y].push_back(v);
			dd[u][v].push_back(y);
			cc[x][y].push_back(t);
			cc[u][v].push_back(t);
		}
		cout<<"Case #"<<nt++<<": "<<endl;
		cin>>h;
		while (h--)
		{
			int x, y, u, v, f=0;
			cin>>x>>y>>u>>v;
			x--;y--;u--;v--;
			memset(dp,-1,sizeof(dp));
			priority_queue<pair<int, pair<int, int> > > q;
			q.push(make_pair(0,make_pair(x,y)));
			while (!q.empty())
			{
				pair<int, pair<int, int> > p = q.top();
				q.pop();
				int cost=-p.first, st=p.second.first, en=p.second.second;
				//cout<<st<<" "<<en<<" "<<cost<<"___"<<endl;
				if (st==u && en==v) continue;
				int sum=0;
				for (int i=en;i<m[st];i++)
				{
					sum+=a[st][i];
					if (dp[st][i+1]==-1 || dp[st][i+1]>cost+sum+w[st])
					{
						//if (st==u && i+1==v) cout<<"__ "<<dp[u][v]<<endl;
						dp[st][i+1]=cost+sum+w[st];
						q.push(make_pair(-cost-sum-w[st],make_pair(st,i+1)));
					}
				}
				sum=0;
				for (int i=en-1;i>=0;i--)
				{
					sum+=a[st][i];
					if (dp[st][i]==-1 || dp[st][i]>cost+sum+w[st])
					{
						//if (st==u && i==v) cout<<"__ "<<dp[u][v]<<endl;
						dp[st][i]=cost+sum+w[st];
						q.push(make_pair(-cost-sum-w[st],make_pair(st,i)));
					}
				}
				for (int i=0;i<mm[st][en].size();i++)
				{
					int m1=mm[st][en][i], d1=dd[st][en][i], c1=cc[st][en][i];
					if (dp[m1][d1]==-1 || dp[m1][d1]>cost+c1)
					{
						//if (m1==u && d1==v) cout<<"__ "<<dp[u][v]<<endl;
						dp[m1][d1]=cost+c1;
						q.push(make_pair(-cost-c1,make_pair(m1,d1)));
					}
				}
			}
			cout<<dp[u][v]<<endl;
		}
	}
}
