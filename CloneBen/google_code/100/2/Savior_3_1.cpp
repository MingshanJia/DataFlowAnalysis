#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <cctype> 
#include <vector> 
#include <string> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <utility> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
using namespace std; 

#define size(x) int((x).size()) 
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
typedef long long I64; typedef unsigned long long U64; 
const double EPS=1e-12; 
const int INF=999999999; 
typedef vector<int> VI; 
typedef vector<string> VS;

const int MAXN=110;

int n,m;
bool g1[MAXN][MAXN],g2[MAXN][MAXN];
char f[MAXN][MAXN];
VI adj1[MAXN],adj2[MAXN];

int n1,n2;
bool mat[MAXN][MAXN];
int a[MAXN];
bool flag[MAXN];

void dfs(int u,int fu,int n,bool g[MAXN][MAXN],VI adj[MAXN])
{
	adj[u].clear();
	for(int i=0;i<n;i++) if(g[u][i] && i!=fu) {
		adj[u].push_back(i);
		dfs(i,u,n,g,adj);
	}
}

bool go(int u)
{
	if(flag[u]) return 0;
	flag[u]=1;
	for(int i=0;i<n1;i++) if(mat[i][u] && (a[i]<0 || go(a[i]))) {
		a[i]=u;
		return 1;
	}
	return 0;
}

bool com(int u1,int u2)
{
	char &res=f[u1][u2];
	if(res!=-1) return res;

	res=0;
	if(size(adj1[u1]) < size(adj2[u2])) return res;

	for(int i=0;i<size(adj1[u1]);i++) {
		int v1=adj1[u1][i];
		for(int j=0;j<size(adj2[u2]);j++) {
			int v2=adj2[u2][j];
			com(v1,v2);
		}
	}

	n1=size(adj1[u1]),n2=size(adj2[u2]);
	memset(mat,0,sizeof(mat));
	for(int i=0;i<n1;i++) {
		int v1=adj1[u1][i];
		for(int j=0;j<n2;j++) {
			int v2=adj2[u2][j];
			mat[i][j]=f[v1][v2];
		}
	}
	
	memset(a,-1,sizeof(a));
	for(int i=0;i<n2;i++) {
		memset(flag,0,sizeof(flag));
		if(!go(i)) return res;
	}

	return res=1;
}

bool solve()
{
	int x,y;

	scanf("%d",&n);
	memset(g1,0,sizeof(g1));
	for(int i=0;i+1<n;i++)  {
		scanf("%d%d",&x,&y);
		x--,y--;
		g1[x][y]=g1[y][x]=1;
	}

	scanf("%d",&m);
	memset(g2,0,sizeof(g2));
	for(int i=0;i+1<m;i++)  {
		scanf("%d%d",&x,&y);
		x--,y--;
		g2[x][y]=g2[y][x]=1;
	}

	dfs(0,-1,n,g1,adj1);
	for(int i=0;i<m;i++) {
		dfs(i,-1,m,g2,adj2);
		memset(f,-1,sizeof(f));
		for(int j=0;j<n;j++) if(com(j,i)) return 1;
	}
	return 0;
}

int main()
{
	int T;

	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d: ",i);
		if(solve()) printf("YES\n"); else printf("NO\n"); 
	}

	return 0;
}
