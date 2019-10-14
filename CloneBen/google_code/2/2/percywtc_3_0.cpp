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

int n, dp[20055];

void init() {
	SET(dp, -1);
	dp[0] = 0;
	FOE(i, 1, 100) {
		FOE(j, 0, 10000 - i * i) if (dp[j] != -1) {
			if (dp[j + i * i] == -1 || dp[j + i * i] > dp[j] + 1)
				dp[j + i * i] = dp[j] + 1;
		}
	}
}

int solve() {
	scanf("%d", &n);
	return dp[n];
}

int main () {
	
	scanf("%d", &TC);
	
	OUT = fopen("d.out", "w");
		
	init();
	
	FOE(ttc, 1, TC) {
		
		printf("Processing on Case #%d...\n", ttc);
		
		fprintf(OUT, "Case #%d: %d\n", ttc, solve());
		
	}
	
	return 0;
	
}
