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

int s[1009];
int rs[1009];
int mm[1009][1009];

int e,n;

int dp(int x,int y){
	if(x==0&&y==0)return 1;
	if(x+y>n)return 0;
	if(y>x)return 0;
	if(mm[x][y]!=-1)return mm[x][y];
	int fe=e+rs[n]-rs[n-y]-rs[x];
	if(fe<=0)return 0;
	mm[x][y]=0;
	if(x)mm[x][y]|=dp(x-1,y);
	if(y)mm[x][y]|=dp(x,y-1);
	return mm[x][y];
}

int main(){
	RF("B-large.in");
	WF("Blout.txt");
	CASET{
		RII(e,n);
		REP(i,n){
			RI(s[i]);
		}
		sort(s,s+n);
		REP(i,n)rs[i+1]=rs[i]+s[i];
		MS1(mm);
		int ans=0;
		REP(i,n+1){
			REP(j,n+1){
				if(dp(i,j))ans=max(ans,i-j);
			}
		}
		printf("Case #%d: %d\n",case_n++,ans);
	}
}
