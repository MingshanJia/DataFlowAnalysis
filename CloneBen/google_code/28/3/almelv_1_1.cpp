#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;

const int nMax = 15;
const int INF = 1000000;

int mini[1<<nMax];
int N,K;
int dp[nMax][1<<nMax];
pair<int,int> tabN[nMax];

int go(int k, int mask) {
	int &res = dp[k][mask];
	if(res>=0) return res;
	if(mask==0) return res=0;
	if(k==1) return res=mini[mask];
	res = INF;
	for(int w=mask; w>0; w=(w-1)&mask)
		res <?= max(mini[w], go(k-1,mask-w));
	return res;
}

void testcase(int tNum) {
	scanf("%d %d",&N,&K);
	FOR(i,0,N) scanf("%d %d",&tabN[i].FI,&tabN[i].SE);
	FOR(mask,1,1<<N) {
		int minX=INF, maxX=-INF, minY=INF, maxY=-INF;
		FOR(i,0,N) if(mask&(1<<i)) {
			minX <?= tabN[i].FI;
			maxX >?= tabN[i].FI;
			minY <?= tabN[i].SE;
			maxY >?= tabN[i].SE;
		}
		int best = max(maxX-minX, maxY-minY);
		mini[mask] = best;
	}
	memset(dp,-1,sizeof(dp));
	printf("Case #%d: %d\n",tNum,go(K,(1<<N)-1));
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
