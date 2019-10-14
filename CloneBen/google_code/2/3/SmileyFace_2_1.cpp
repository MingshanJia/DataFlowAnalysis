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

int n,m,p;
vector<vector<double> > io;

pair<double,double> prob(int x){//same, diff.
	if(x==1)return MP(0,1);
	if(x%2){
		pair<double,double> h=prob(x-1);
		return MP(h.S/(n-1),h.F+h.S*(n-2)/(n-1));
	}
	pair<double,double> h=prob(x/2);
	return MP(h.S*h.S/(n-1)+h.F*h.F,h.F*h.S*2+h.S*h.S*(n-2)/(n-1));
}

vector<vector<double> > mg(vector<vector<double> >a ,vector<vector<double> >b,int x1,int x2){
	vector<vector<double> >ans;
	ans.resize(n);
	REP(i,n)ans[i].resize(n);
	PDD pp=prob(x1+x2);
	pair<double,double> p1=prob(x1);
	pair<double,double> p2=prob(x2);
	REP(i,n){
		REP(j,n){
			ans[i][j]=0;
			REP(k,n){
				double dx=(a[i][k]+b[k][j]);
				if(i==k)dx*=p1.F;else dx*=p1.S/(n-1);
				if(j==k)dx*=p2.F;else dx*=p2.S/(n-1);
				ans[i][j]+=dx;
			}
			if(ans[i][j]<=1e-10)continue;
			if(i==j)ans[i][j]/=pp.F;
			else ans[i][j]/=pp.S/(n-1);
		}
	}
	return ans;
}

vector<vector<double> > solve(int x){
	//printf("SOLVE %d\n",x);
	if(x==1)return io;
	if(x%2)return mg(solve(x-1),io,x-1,1);
	vector<vector<double> > h=solve(x/2);
	return mg(h,h,x/2,x/2);
}

int fw[109][109];

int main(){
	RF("C-large.in");
	WF("Clout.txt");
	CASET{
		RIII(n,m,p);
		REP(i,n){
			REP(j,n){
				fw[i][j]=1<<29;
			}
		}
		REP(i,n)fw[i][i]=0;
		REP(i,m){
			DRIII(a,b,c);a--;b--;
			fw[a][b]=fw[b][a]=c;
		}
		REP(k,n){
			REP(i,n){
				REP(j,n){
					fw[i][j]=min(fw[i][j],fw[i][k]+fw[k][j]);
				}
			}
		}
		io.resize(n);
		REP(i,n){
			io[i].resize(n);
			REP(j,n){
				io[i][j]=(double)fw[i][j];
			}
		}
		vector<vector<double> > fv=solve(p);
		/*REP(i,n){
			REP(j,n){
				printf("%.1lf ",fv[i][j]);
			}puts("");
		}*/
		double ans=0;
		PDD pp=prob(p);
		ans+=fv[0][0]*pp.F;
		REPP(i,1,n){
			ans+=fv[0][i]*pp.S/(n-1);
		}
		cerr<<"hI";
		printf("Case #%d: %lf\n",case_n++,ans);
	}
}
