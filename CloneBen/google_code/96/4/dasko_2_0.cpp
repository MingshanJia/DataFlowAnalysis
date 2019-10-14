#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(AA,BB) for(AA=0; AA<BB; ++AA)
#define FOR(AA,BB,CC) for(AA=BB; AA<CC; ++AA)
#define FC(AA,BB) for(typeof(AA.begin()) BB=AA.begin(); BB!=AA.end(); ++BB)

using namespace std;

char c[510], d[]="welcome to code jam";
int dp[20][510], n=19, m, MOD=10000;

int rec(int a, int b) {
	if(dp[a][b]!=-1)
		return dp[a][b];
	if(a==n)
		return 1;
	if(b==m)
		return 0;
	return dp[a][b]=(rec(a,b+1)+((d[a]==c[b])?rec(a+1,b+1):0))%MOD;
}

int main(void) {
	int t, T, i, j, k;
	scanf("%d", &T); fgets(c, 510, stdin);
	REP(t,T) {
		fgets(c, 510, stdin); m=strlen(c);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %04d\n", t+1, rec(0,0));
	}
	return 0;
}
