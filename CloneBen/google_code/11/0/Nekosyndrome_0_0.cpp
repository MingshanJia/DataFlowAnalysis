#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 200
using namespace std;
typedef long long LL;
int t,n,sqn,in[M][M];
bool vis[M];
bool vis2[M][M];
bool check()
{
	REP(i,0,n-1)
	{
		MSET(vis,false);
		REP(j,0,n-1)
		{
			if(in[i][j]<=0 || in[i][j]>n)return false;
			if(vis[in[i][j]])return false;
			vis[in[i][j]]=true;
		}
	}

	REP(j,0,n-1)
	{
		MSET(vis,false);
		REP(i,0,n-1)
		{
			if(in[i][j]<=0 || in[i][j]>n)return false;
			if(vis[in[i][j]])return false;
			vis[in[i][j]]=true;
		}
	}

	MSET(vis2,false);
	REP(i,0,n-1)REP(j,0,n-1)
	{
		int block=(i/sqn)*sqn + (j/sqn);
		if(vis2[block][in[i][j]])return false;
		vis2[block][in[i][j]]=true;
	}
	return true;
}
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		scanf("%d",&n);
		sqn=n;
		n*=n;
		REP(i,0,n-1)REP(j,0,n-1)scanf("%d",&in[i][j]);

		printf("Case #%d: ",tt);
		if(check())puts("Yes");
		else puts("No");
	}
	return 0;
}

