#include <stdio.h>

int dp[10010];

void Prework(){
	for(int i=0; i<10010; i++) dp[i] = 1000000;
	dp[0] = 0;
	
	for(int i=1; i<=100; i++){
		int sz = i*i;
		for(int j=0; j<10010; j++){
			if(j + sz > 10008) break;
			if(dp[j+sz] > dp[j]+1) dp[j+sz] = dp[j]+1;
		}
	}
}

int main(){
	int jcase;
	int tgt;
	
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);

	Prework();
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%d", &tgt);
		printf("Case #%d: %d\n", icase+1, dp[tgt]);
	}
	
	return 0;
}
