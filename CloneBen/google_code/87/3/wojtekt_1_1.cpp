// {{{
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>
#include <stack>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <utility>
#include <bitset>
#include <assert.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PI;
typedef pair<LD,LD> PD;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())
// }}}

#define M 55

int n,k,b,t;
int x[M],v[M];
int W[M];


inline bool fun(int a, int b) {
	if (x[a]!=x[b]) return x[a]>x[b];
	if (v[a]!=v[b]) return v[a]>v[b];
	return a<b;
}


int main() {
	int test,number=0;
	scanf("%d",&test);
	while (test--) {
		printf("Case #%d: ",++number);
		scanf("%d%d%d%d",&n,&k,&b,&t);
		REP(i,n) scanf("%d",&x[i]);
		REP(i,n) scanf("%d",&v[i]);

		REP(i,n) W[i]=i;
		sort(W,W+n,fun);

		int ile=0,akt=0,zly=0;
		int res=0;
		while (ile<k && akt<n) {
			int nr=W[akt];
			if (t*v[nr]>=b-x[nr]) ile++,res+=zly;
			else zly++;
			akt++;
		}

		if (ile<k) printf("IMPOSSIBLE\n");
		else printf("%d\n",res);
	}
	return 0;
}
