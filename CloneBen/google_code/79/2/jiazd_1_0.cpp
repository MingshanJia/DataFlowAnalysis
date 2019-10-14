#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;
#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CONTAIN(container, it) (container.find(it)!=container.end())
#define CLR(c,n) memset(c,n,sizeof(c))
#define MCPY(dest,src) memcpy(dest,src,sizeof(src))
template<class T> T checkmax(T &a, T b) {return a=max(a,b);}
template<class T> T checkmin(T &a, T b) {return a=min(a,b);}
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
const double EPS=1e-9;
const double PI=acos(-1);
const int INF=0x3F3F3F3F;
const int MAXN=1000;
const int MAXL=2;
int l, n, c, a[MAXN];
long dp[2][MAXL+1],t;
int main(int argc, char *argv[])
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int test_case;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		//fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		scanf("%d%ld%d%d", &l, &t, &n, &c); REP(i,c) scanf("%d", a+i);
		for (int i=c; i<n; ++i) a[i]=a[i-c];
		CLR(dp,0);
		int cur=0, prev=1;
		REP(i,n) {
			swap(cur,prev);
			FOR(j,0,l) dp[cur][j]=dp[prev][j]+2*a[i];
			FOR(j,1,l) {
				if (dp[prev][j-1]>=t) checkmin(dp[cur][j],dp[prev][j-1]+a[i]);
				else if (dp[prev][j-1]+2*a[i]>t) checkmin(dp[cur][j], dp[prev][j-1]+2*a[i]-(dp[prev][j-1]+2*a[i]-t)/2);
			}
		}
		printf("Case #%d: %ld\n", test_case_id, dp[cur][l]);
	}
}
