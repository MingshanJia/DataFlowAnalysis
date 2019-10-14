#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for (int i=s;i<e;i++)
#define FOE(i,s,e) for (int i=s;i<=e;i++)
#define FOD(i,s,e) for (int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define LD long double
#define pb push_back
#define x first
#define y second
#define PII pair<int,int>
#define PLI pair<LL,int>
#define PIL pair<int,LL>
#define PLL pair<LL,LL>
#define PDD pair<LD,LD>
#define eps 1e-9
#define HH1 402653189
#define HH2 1610612741

int TC;
FILE *OUT;

const int TIL = 1000;

int n, m, p, x, y, z;
double dist[105][105], DP[1055][105];

void init() {
	FOR(i, 0, 105) FOR(j, 0, 105) dist[i][j] = 123456789;
	FOR(i, 0, 105) dist[i][i] = 0;
	FOR(i, 0, 1055) FOR(j, 0, 105) DP[i][j] = -1;
}

double dp(int x, int at) {
	if (x == 0) return 0;
	else if (DP[x][at] != -1) return DP[x][at];
	
	double ret = 0;
	
	FOE(i, 1, n) if (i != at) ret += dist[at][i] + dp(x - 1, i);
	
	ret /= n - 1;
	
	return DP[x][at] = ret;	
}

double solve() {
	scanf("%d%d%d", &n, &m, &p);
	FOR(i, 0, m) {
		scanf("%d%d%d", &x, &y, &z);
		dist[x][y] = dist[y][x] = z;
	}
	
	FOE(k, 1, n) FOE(i, 1, n) FOE(j, 1, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	dp(TIL, 1);
	
	if (p <= TIL) return dp(p, 1);
	
	double a = dp(TIL, 1);
	double d = dp(TIL, 1) - dp(TIL - 1, 1);
	
	p -= TIL;
	
	return a + d * p;
}

int main () {
	
	scanf("%d", &TC);
	
	OUT = fopen("c.out", "w");
	
	FOE(ttc, 1, TC) {
		
		printf("Processing on Case #%d...\n", ttc);
		
		init();
		
		fprintf(OUT, "Case #%d: %.10lf\n", ttc, solve());
		
	}
	
	return 0;
	
}
