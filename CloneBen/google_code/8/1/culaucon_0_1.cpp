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

bool a[310][310];
int adj[310][310];

int dx[8]={-1,0,1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};

bool vst[310][310];
int n;

void go(int i, int j)
{
	if (vst[i][j]) return;
	vst[i][j]=1;
	if (adj[i][j]!=0) return;
	
	for (int k=0;k<8;k++)
	{
		int x=i+dx[k], y=j+dy[k];
		if (x<0 || x>=n || y<0 || y>=n) continue;
		go(x,y);
	}
}
int main()
{
	freopen("minesweeper.in","r",stdin);
	freopen("minesweeper.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				char ch;
				cin>>ch;
				if (ch=='.') a[i][j]=0;
				else a[i][j]=1;
			}
		memset(adj,0,sizeof(adj));
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				for (int k=0;k<8;k++)
				{
					int x=i+dx[k], y=j+dy[k];
					if (x<0 || x>=n || y<0 || y>=n || a[x][y]==0) continue;
					adj[i][j]++;
				}
		memset(vst,0,sizeof(vst));
		int ret=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (!vst[i][j] && adj[i][j]==0 && a[i][j]==0)
				{
					go(i,j);
					ret++;
				}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (!vst[i][j] && a[i][j]==0) ret++;
		cout<<"Case #"<<nt++<<": "<<ret<<endl;
	}
}
