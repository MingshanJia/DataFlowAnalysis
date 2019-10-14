/* ***********************************************
Author        :axp
Created Time  :2016/10/16 13:49:44
TASK		  :B.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int md = 1e9+7;
const int N = 100+10;
int T;
bool vis[N][N];

bool check(int x,int y)
{
	if(x<=0 || y<=0)return 1;
	if(vis[x-1][y]&&vis[x][y]&&vis[x+1][y])return 0;
	if(vis[x][y-1]&&vis[x][y]&&vis[x][y+1])return 0;
	return 1;
}

bool ok(int x,int y)
{
	vis[x][y]=1;
	for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<=y+1;j++)
			if(!check(i,j))
			{
				vis[x][y]=0;
				return 0;
			}
	vis[x][y]=0;
	return 1;
}

int solve(int n,int m,bool k)
{
	memset(vis,0,sizeof vis);
	if(k && n>=2 && m>=3)vis[2][3]=1;
	int re=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ok(i,j))
			{
				//cout<<i<<' '<<j<<endl;
				vis[i][j]=1;
				re++;
			}
	return re;
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		for(int i=0;i<2;i++)
			ans=max(ans,max(solve(n,m,i),solve(m,n,i)));
		//for(int i=1;i<=n;i++){ for(int j=1;j<=n;j++)printf("%d ",vis[i][j]);putchar(10);}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}
