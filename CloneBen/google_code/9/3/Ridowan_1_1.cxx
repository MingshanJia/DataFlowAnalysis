//BISM ILLAHHIRRAHMANNI RRAHIM

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

double dp[410][410*410];
bool vis[410][410*410];

int pr[410*410];
int tr[410*410];
int it[410*410];

int tt;
double dfs(int l,int g) {
	if(l==1) return double(tt>250?(tt-250):0)/3;
	if(vis[l][g]) return dp[l][g];
	vis[l][g]=1;
	double r=0;
	if(tr[l-1]>=g) r=dfs(l-1,g);
	int t=g-pr[g];
	if(t>1) r+=dfs(l-1,g-it[pr[g]]-1);
	if(t<=it[pr[g]]) r+=dfs(l-1,g-it[pr[g]]);
	if(r>=250) r-=250;
	else r=0;
	//cerr<<l<<' '<<g<<' '<<r<<' '<<(r/3)<<'\n';
	return dp[l][g]=r/3;
}


int main() {
	//READ("input.in");
	//READ("B-small-attempt0.in");
	//READ("B-small-attempt1.in");
	//READ("B-small-attempt2.in");
	//READ("B-small-attempt3.in");
	READ("B-large.in");
	WRITE("output-large.out");
	int i,j;
	for(i=1;i<=405;i++) {
		tr[i]=tr[i-1]+i;
		it[tr[i]]=i;
	}
	i=0;
	for(j=1;j<=403*403;j++) {
		pr[j]=tr[i];
		if(tr[i+1]==j) i++;
	}
	int I,T,l,g,b;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>b>>l>>g;
		tt=750*b;
		CLR(vis);
		double r=0;
		if(l==1) r=tt>=250?250:tt;
		else {
			if(tr[l-1]>=g) r=dfs(l-1,g);
			int t=g-pr[g];
			if(t>1) r+=dfs(l-1,g-it[pr[g]]-1);
			if(t<=it[pr[g]]) r+=dfs(l-1,g-it[pr[g]]);
			if(r>=250) r=250;
		}
		printf("Case #%d: %.9lf\n",I,r);
	}
	return 0;
}
