/* DIKRA */
/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

#define INF 2000000000000LL

int ntc;
int x;
long long dp[1000005];
int av[15];


int countDigit(int pos){
	if (pos == 0) return 1;
	int cnt = 0;
	while (pos > 0){
		cnt++; 
		pos /= 10;
	}
	return cnt;
}

int available(int pos){
	if (pos == 0){
		return (av[0]);
	}
	while (pos > 0){
		if (av[pos%10] == 0) return 0;
		pos /= 10;
	}
	return 1;
}

long long work(int pos){
	long long &ret = dp[pos];
	if (ret == -1){
		ret = INF;
		if (available(pos)) ret = countDigit(pos);

		for(int i = 2; i*i <= pos; i++){
			if (pos%i == 0){
				MN(ret, work(i) + work(pos/i) + 1LL);
			}
		}
	}
	return ret;
}

int main(){
	OPEN("c");

	scanf("%d", &ntc);
	FOR(itc, 1, ntc){
		REP(i, 10) scanf("%d", &av[i]);
		scanf("%d", &x);

		RESET(dp, -1LL);
		long long ans = work(x);

		printf("Case #%d: ", itc);
		if (ans < INF) printf("%I64d\n", ans+1LL);
		else printf("Impossible\n");
	}
	return 0;
}
