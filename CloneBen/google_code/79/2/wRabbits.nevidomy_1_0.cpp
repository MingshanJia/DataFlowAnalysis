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

int A[1<<20];
void solve() {
	int L,N,C;
	LL t;
	scanf("%d%lld%d%d",&L,&t,&N,&C);
	int a[1024]; FOR(i,0,C) scanf("%d",a+i);
	for(int i=0; i<N; i++) {
		A[i]=a[i%C];
	}
	LL sum=0;
	FOR(i,0,N) sum+=(LL)A[i]*2LL;
	LL time=0;
	vector<int> use;
	FOR(i,0,N) {
		LL ntime=time+2LL*A[i];
		if (ntime>=t) {
			if (time>=t) use.pb(-A[i]);
			else {
				use.pb(-((LL)ntime-(LL)t)/2LL);
			}
		}
		time=ntime;
	}
	sort(ALL(use));
	FOR(i,0,min(L,(int)use.sz)) {
		sum+=use[i];
	}
	printf("%lld\n",sum);
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