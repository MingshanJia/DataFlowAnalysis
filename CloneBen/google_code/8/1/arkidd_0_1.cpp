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

int ntc;
int n;
char s[305][305];
int a[305][305], vis[305][305];
int rm[] = {0,0,1,-1,1,1,-1,-1};
int cm[] = {1,-1,0,0,1,-1,1,-1};

void ff(int r, int c){
	if (r < 0 || r >= n || c < 0 || c >= n) return;
	if (s[r][c] == '*') return;
	if (vis[r][c]) return;
	vis[r][c] = 1;

	if (a[r][c] != 0) return;

	REP(k, 8){
		int rr = r+rm[k];
		int cc = c+cm[k];
		ff(rr, cc);
	}
	return;
}

int main(){
	OPEN("a");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc){
		scanf("%d", &n);
		REP(i, n){
			scanf("%s", s[i]);
		}

		REP(i, n){
			REP(j, n){
				if (s[i][j] == '*') continue;

				int cnt = 0;
				REP(k, 8){
					int r = i+rm[k];
					int c = j+cm[k];
					if (r < 0 || r >= n || c < 0 || c >= n) continue;
					if (s[r][c] == '*') cnt++;
				}
				a[i][j] = cnt;
			}
		}

		RESET(vis, 0);
		int ans = 0;
		REP(i, n){
			REP(j, n){
				if (s[i][j] == '*') continue;
				if (a[i][j] == 0 && vis[i][j] == 0){
					ff(i, j);
					ans++;
				}
			}
		}

		REP(i, n){
			REP(j, n){
				if (s[i][j] == '*') continue;
				if (vis[i][j] == 0){
					ans++;
				}
			}
		}

		printf("Case #%d: %d\n", itc, ans);
	}
	return 0;
}









