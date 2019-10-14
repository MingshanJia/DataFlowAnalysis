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

#include <gmpxx.h>
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

mpz_class dp[410][410];
bool vis[410][410];

mpz_class dfs(int n,int lf) {
	if(!n) return lf?0:1;
	if(vis[n][lf]) return dp[n][lf];
	vis[n][lf]=1;
	mpz_class r=dfs(n-1,lf+1);
	if(lf) r+=dfs(n-1,lf-1);
	return dp[n][lf]=r;
}

string back(int n,int lf,mpz_class k) {
	if(!n) return "";
	mpz_class r=dfs(n-1,lf+1);
	if(k<=r) return "("+back(n-1,lf+1,k);
	k-=r;
	return ")"+back(n-1,lf-1,k);
}

int main() {
	//READ("input.in");
	READ("D-small-attempt0.in");
	//READ("D-small-attempt1.in");
	//READ("D-small-attempt2.in");
	//READ("D-small-attempt3.in");
	//READ("D-large.in");
	WRITE("output-small.out");
	//cout<<dfs(100,0)<<'\n';
	int I,T;
	int n;
	mpz_class k;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n>>k;
		n<<=1;
		mpz_class r=dfs(n,0);
		//cerr<<r<<'\n';
		printf("Case #%d: ",I);
		if(r<k) {
			puts("Doesn't Exist!");
		}
		else {
			cout<<back(n,0,k)<<'\n';
		}
	}
	return 0;
}
