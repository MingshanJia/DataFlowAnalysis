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

#define M 505

const int P=100003;

int n;
int res[M][M];
int nk[M][M];


int main() {
	nk[0][0]=1;
	FOR(i,1,500) {
		nk[i][0]=1;
		FOR(j,1,i) nk[i][j]=nk[i-1][j-1]+nk[i-1][j];
	}

	FOR(i,2,500) { /* koncowa */
		res[i][1]=1;
		FOR(j,2,i-1) { /* ktora jest */
			FOR(k,1,j-1) 
				res[i][j]=(res[i][j]+(int)(((LL)res[j][k]*(LL)nk[i-j-1][j-k-1])%((LL)P)))%P;
		}
	}

	int test,number=0;
	scanf("%d",&test);
	while (test--) {
		printf("Case #%d: ",++number);
		scanf("%d",&n);

		int w=0;
		FOR(i,1,n) w=(w+res[n][i])%P;
		printf("%d\n",w);
	}
	return 0;
}
