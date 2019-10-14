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

#define md 1000000007

//i64 fc[120],ifc[120];

i64 ncr[520][520];
i64 dp[120][129];

bool vis[120][120];

i64 dfs(int n,int m) {
	if(!m) {
		return n?0:1;
	}
	if(n<m) return 0;
	if(vis[n][m]) return dp[n][m];
	vis[n][m]=1;
	int cr;
	i64 r=0;
	for(cr=1;n>=cr;cr++) {
		r=(dfs(n-cr,m-1)*ncr[n][cr]+r)%md;
	}
	return dp[n][m]=r;
}

int main() {
	//READ("input.in");
	//READ("A-small-attempt0.in");
	//READ("A-small-attempt1.in");
	//READ("A-small-attempt2.in");
	//READ("A-small-attempt3.in");
	READ("A-large.in");
	WRITE("output-large.out");
	int I,T;
	int i,j,k,l;
	//fc[0]=ifc[0]=1;
	i64 b;
	/*for(i=1;i<=110;i++) {
		fc[i]=(fc[i-1]*i)%md;
		k=md-2;
		ifc[i]=1;
		b=fc[i];
		while(k)  {
			if(k&1) ifc[i]=(b*ifc[i])%md;
			b=(b*b)%md;
			k>>=1;
		}
		//assert((fc[i]*ifc[i])%md==1);
	}*/
	for(i=0;i<=250;i++) {
		ncr[i][0]=ncr[i][i]=1;
		for(j=1;j<i;j++) ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%md;
	}
	cin>>T;
	int n,m;
	for(I=1;I<=T;I++) {
		cin>>m>>n;
		printf("Case #%d: ",I);
		cout<<dfs(n,m)<<'\n';
	}
	return 0;
}
