//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

int node[105][1005],node1[105][1005];
int wt[105];

#define MAXN 5005
#define MAXE 1000005

int head[MAXN],nxt[MAXE],e[MAXE],w[MAXE];

int cnt;
int nd = 0;

int newNode(){
	head[nd] = -1;
	return nd++;
}

void addEdge(int u,int v,int w){
	e[cnt] = v,::w[cnt] = w;
	int tmp = head[u];
	head[u] = cnt;
	nxt[cnt++] = tmp;
}

int d[MAXN];
int inq[MAXN];

int spfa(int s,int t){
	memset(inq,0,sizeof(inq));
	for(int i = 0;i<=nd;i++) d[i] = INF;
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x = q.front();q.pop();
		inq[x] = 0;
		for(int i = head[x];~i;i = nxt[i]){
			int v = e[i];
			if(d[v]>d[x]+w[i]){
				d[v] = d[x]+w[i];
				if(!inq[v]){
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return d[t];
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
	freopen("/Users/mac/Desktop/data.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		cnt = nd = 0;
		int n;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			int sn;
			scanf("%d %d",&sn,&wt[i]);
			for(int j = 1;j<=sn;j++){
				node[i][j] = newNode();
				node1[i][j] = newNode();
				addEdge(node[i][j],node1[i][j],0);
				addEdge(node1[i][j],node[i][j],wt[i]);
			}
			for(int j = 1;j<sn;j++){
				int val;
				scanf("%d",&val);
				addEdge(node[i][j],node[i][j+1],val);
				addEdge(node[i][j+1],node[i][j],val);
			}
		}
		int m;
		scanf("%d",&m);
		for(int i = 0;i<m;i++){
			int m1,s1,m2,s2,t;
			scanf("%d %d %d %d %d",&m1,&s1,&m2,&s2,&t);
			addEdge(node1[m1][s1],node1[m2][s2],t);
			addEdge(node1[m2][s2],node1[m1][s1],t);
		}
		static int ca = 1;
		printf("Case #%d:\n",ca++);
		int q;
		scanf("%d",&q);
		while(q--){
			int m1,s1,m2,s2;
			scanf("%d %d %d %d",&m1,&s1,&m2,&s2);
			int ans = spfa(node1[m1][s1],node1[m2][s2]);
			if(ans==INF) puts("-1");
			else printf("%d\n",ans);
		}
	}
	return 0;
}

