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

#define M 100111
#define Q 505

int n,m;
char A[M];
vector<string> T[Q];


inline vector<string> dziel(string s) {
	int akt=1;
	string t="";
	vector<string> res;
	while (akt<SIZE(s)) {
		if (s[akt]=='/') res.PB(t);
		else t+=s[akt];
		akt++;
	}
	res.PB(t);
	return res;
}


int main() {
	int test,number=0;
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d",&n,&m);
		printf("Case #%d: ",++number);
		string s;
		REP(i,n) {
			scanf("%s",A),s=A;
			T[i]=dziel(s);
		}

		int res=0,ile,akt;
		REP(i,m) {
			scanf("%s",A),s=A;
			T[i+n]=dziel(s);
			ile=0;
			REP(j,n+i) {
				akt=0;
				while (akt<min(SIZE(T[j]),SIZE(T[i+n])) && T[j][akt]==T[i+n][akt]) akt++;
				ile=max(ile,akt);
			}
			res+=SIZE(T[i+n])-ile;
		}

		printf("%d\n",res);
	}
	return 0;
}
