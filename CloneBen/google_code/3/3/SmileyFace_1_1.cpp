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
int MAXN = 1e7+2;
const double eps = 1e-13;

LL d[5009];
vector<LL> dc;
LL f[5009];
LL rs[5009];

int main(){
	RF("B-large.in");
	WF("Bl.txt");
	CASET{
		MS0(f);MS0(rs);
		dc.clear();
		DRI(n);
		REP(i,n){
			scanf("%lld",&d[i]);
			dc.PB(d[i]);
		}
		sort(ALL(dc));
		dc.resize(unique(ALL(dc))-dc.begin());
		REP(i,n){
			int p=lower_bound(ALL(dc),d[i])-dc.begin();
			f[p]++;rs[p]++;
		}
		int m=SZ(dc);
		REPP(i,1,m)rs[i]+=rs[i-1];
		LL ans=0;
		REP(i,m){
			REP(j,m){
				if(i==j)continue;
				LL a=dc[i],b=dc[j];
				LL minc=b+1,maxc=b+a*2-1;
				int pp=upper_bound(ALL(dc),maxc)-dc.begin()-1;
				LL c3=0;
				if(pp>=0)c3+=rs[pp];
				pp=lower_bound(ALL(dc),minc)-dc.begin()-1;
				if(pp>=0)c3-=rs[pp];
				if(a>=minc&&a<=maxc){
					c3-=f[i];
				}
				ans+=(f[i]*(f[i]-1))/2LL*f[j]*c3;
				if(b<3LL*a)ans+=(f[i]*(f[i]-1)*(f[i]-2))/6LL*f[j];
			}
		}
		printf("Case #%d: %lld\n",case_n++,ans);
	}
}
