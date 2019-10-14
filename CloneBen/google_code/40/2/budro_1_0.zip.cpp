//Franciszek Budrowski

#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;

const bool print=false;
const int MAXN=730;
int dp[2*MAXN][MAXN][2][2];
int t[2*MAXN][2];
const int DAYMINS=1440;
const int TIMSPE=720;



main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		int n[2];scanf("%d%d",&n[0],&n[1]);
		FOR(i,0,DAYMINS)
				t[i][0]=t[i][1]=0;
		FOR(x,0,1){
			FOR(i,1,n[x]){
				int a,b;scanf("%d%d",&a,&b);
				FOR(j,a+1,b) t[j][x]=1;
			}
		}
		FOR(j,1,720)
			FOR(z,0,1)
				dp[0][j][z][0]=dp[0][j][z][1]=100*MAXN;
		dp[0][0][0][1]=dp[0][0][1][0]=100*MAXN;
		FOR(i,1,DAYMINS){
			int gora=min(i,720);
			FOR(j,0,gora+5) FOR(z,0,1) dp[i][j][z][0]=dp[i][j][z][1]=100*MAXN;
			FOR(j,0,gora){
				FOR(z,0,1){
					FOR(x,0,1){
						if(i==1&&x!=z) continue;
						if(t[i][x]!=0) continue;
						if(dp[i-1][j][z][x]<dp[i][j+x][z][x]) dp[i][j+x][z][x]=dp[i-1][j][z][x];
						if(dp[i-1][j][z][(x^1)]+1<dp[i][j+x][z][x]) dp[i][j+x][z][x]=dp[i-1][j][z][(x^1)]+1;
					}
				}
			}
		}
		int ans=min(dp[DAYMINS][720][0][0],dp[DAYMINS][720][1][1]);
		ans=min(ans,min(dp[DAYMINS][720][1][0]+1,dp[DAYMINS][720][0][1]+1));
		printf("Case #%d: %d\n",casenr,ans);
	}
}
			
		
		
