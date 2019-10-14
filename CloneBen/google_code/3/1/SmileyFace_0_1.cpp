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

int eq[301][301][301];//0 index
int dp[301][301][301];//1 indexed?
char s[301];

int main(){
	RF("A-large.in");
	WF("Al.txt");
	CASET{
		RS(s);
		int n=LEN(s);
		REP(i,n){
			REP(j,n){
				eq[i][j][0]=1;
				REPP(l,1,n){
					if(i+l-1<n&&j+l-1<n){
						eq[i][j][l]=eq[i][j][l-1]&(s[i+l-1]==s[j+l-1]);
					}
					else eq[i][j][l]=0;
				}
			}
		}
		REP(i,n+1){
			REP(j,n+1)REP(k,n+1)dp[i][j][k]=INF;
		}
		dp[0][0][0]=0;
		REPP(i,1,n+1){//number of done characters
			int cmin=INF;
			REP(j,i+1){
				REPP(k,j,i+1){
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]+1);
					if((j!=0)&&(k!=0)){
						int l=k-j+1;//[i-l+1..i]==[j..k]
						if(j==1&&k==2){
						}
						if(i-l>=0&&eq[i-l][j-1][l]){
							dp[i][j][k]=min(dp[i][j][k],dp[i-l][j][k]+1);
						}
					}
					cmin=min(cmin,dp[i][j][k]);
				}
			}
			REP(j,i+1){
				REPP(k,j,i+1){
					dp[i][j][k]=min(dp[i][j][k],cmin+1);
				}
			}
		}
		int ans=INF;
		REP(i,n+1)REP(j,n+1){
			ans=min(ans,dp[n][i][j]);
		}
		printf("Case #%d: %d\n",case_n,ans);
		case_n++;
	}
}
