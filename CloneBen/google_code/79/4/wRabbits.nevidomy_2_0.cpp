#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stack>
#include <memory.h>
#ifdef NEV_DEBUG
#include <ctime>
#endif
using namespace std;

const int SIZE = 32;
const double pi = 3.1415926535897932384626433832795;


typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef LL matrix[SIZE][SIZE];

#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define FOR(i,a,b) for(int i=(a),_b(b); i<_b; ++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b); i>=_b; --i)
#define CLR(a,b) memset(a,b,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define MIN(a,b) ((a)<(b)?(a):(b))

char ch[1<<20];
string gs() {scanf("%s",ch); return string(ch);}
string gl() {gets(ch); return string(ch);}
template <class T>
T gcd(T a, T b) { return (!a)?b:gcd(b%a,a); }
void error(){ int yyy=0; cout << 7/yyy; }

LL brut(LL l, LL r, vector<LL> &A) {
	for(LL i=l; i<=r; ++i) {
		int ok=1;
		FOR(j,0,A.sz) {
			if (A[j]%i!=0 && i%A[j]!=0) {ok=0; break;}
		}
		if (ok) return i;
	}
	return -1;
}

int A[1<<20];
void solve() {
	vector<LL> A;
	LL L,R;
	int N;
	scanf("%d%lld%lld",&N,&L,&R);
	FOR(i,0,N) {
		LL x; scanf("%lld",&x);
		A.pb(x);
	}
	LL res=brut(L,R,A);
	if (res==-1) printf("NO\n");
	else printf("%lld\n",res);
}

int main() {
#ifdef NEV_DEBUG
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    clock_t beg = clock();
#else
    //freopen("union.in","r",stdin);
    //freopen("union.out","w",stdout);
#endif

	int tests; scanf("%d",&tests); 
	for(int tn=1; tn<=tests; ++tn){
		printf("Case #%d: ",tn);
		solve();
	}

#ifdef NEV_DEBUG
    fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}