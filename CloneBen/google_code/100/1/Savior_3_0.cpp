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

int n,m;
bool g1[10][10];
int e2[10][2];
bool flag[10];
int a[10];
bool ok;

bool check()
{
	for(int i=0;i+1<m;i++) {
		int x=a[e2[i][0]],y=a[e2[i][1]];
		if(!g1[x][y]) return 0;
	}
	return 1;
}

bool go(int t)
{
	if(t==m) {
		return check();
	}

	for(int i=0;i<n;i++) if(!flag[i]) {
		flag[i]=1;
		a[t]=i;
		if(go(t+1)) return 1;
		flag[i]=0;
	}
	return 0;
}

void solve()
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
//	memset(g2,0,sizeof(g2));
	for(int i=0;i+1<m;i++)  {
		scanf("%d%d",&x,&y);
		x--,y--;
		e2[i][0]=x,e2[i][1]=y;
	}

	memset(flag,0,sizeof(flag));
	if(go(0)) printf(" YES"); else printf(" NO");
}

int main()
{
	int T;

	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d:",i);
		solve();
		printf("\n");
	}

	return 0;
}
