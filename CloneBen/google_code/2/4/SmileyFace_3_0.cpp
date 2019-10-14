#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define VPII vector<pair<int,int> >
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const LL MOD = 1e9+7;
const int INF = 1<<30;
int MAXN = 1e5+2;
const double eps = 1e-13;

int dp[100009];

int solve(int x){
	if(x==0)return 0;
	if(dp[x]!=-1)return dp[x];
	dp[x]=4;
	REP(i,350){
		if(x-i*i>=0)dp[x]=min(dp[x],solve(x-i*i)+1);
		else break;
	}
	return dp[x];
}

int main(){
	RF("D-small-attempt0.in");
	WF("Dsout.txt");
	MS1(dp);
	CASET{
		DRI(n);
		printf("Case #%d: %d\n",case_n++,solve(n));
	}
}
