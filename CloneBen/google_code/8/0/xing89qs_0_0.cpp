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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

#define MAXN 305

const int dx[] = {0,0,-1,1,1,-1,1,-1};
const int dy[] = {-1,1,0,0,1,-1,-1,1};
int tot[MAXN][MAXN];
char g[MAXN][MAXN];
int vis[MAXN][MAXN];
int n;

void bfs(int x,int y){
	queue<PII> q;
	q.push(MP(x,y));
	vis[x][y] = 1;
	while(!q.empty()){
		PII p = q.front();q.pop();
		for(int i = 0;i<8;i++){
			x = p.first+dx[i];
			y = p.second+dy[i];
			if(x>=0&&x<n&&y>=0&&y<n&&!vis[x][y]){
				vis[x][y] = 1;
				if(tot[x][y]==0) q.push(MP(x,y));
			}
		}
	}
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
	freopen("/Users/mac/Desktop/data.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0;i<n;i++) scanf("%s",g[i]);
		memset(vis,0,sizeof(vis));
		FOR(i,n){
			FOR(j,n){
				tot[i][j] = 0;
				if(g[i][j]=='*') tot[i][j]++;
				FOR(k,8){
					int x = i+dx[k],y = j+dy[k];
					if(x>=0&&x<n&&y>=0&&y<n){
						if(g[x][y]=='*') tot[i][j]++;
					}
				}
				if(g[i][j]=='*') vis[i][j] = 1;
			}
		}
		int ans = 0;
		FOR(i,n){
			FOR(j,n){
				if(tot[i][j]==0&&!vis[i][j]){
					bfs(i,j);
					ans++;
				}
			}
		}
		FOR(i,n){
			FOR(j,n){
				if(tot[i][j]&&g[i][j]!='*'&&!vis[i][j]) ans++;
			}
		}
		static int ca = 1;
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}

