#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define max(x,y) (x>y?(x):(y))
#define min(x,y) (x<y?(x):(y))
#define MAXN 1000001
#define INF 1000000000

int flg[MAXN], dp[MAXN];
std::vector<int> vec[MAXN];

void build(){
	for(int i=1; i<MAXN; ++i) vec[i].clear();
	for(int i=2; i<MAXN; ++i){
		for(int j=2*i; j<MAXN; j+=i) vec[j].push_back(i);
	}
}
void init(){
	for(int i=10; i<MAXN; ++i) flg[i] = -1;
	dp[1] = (flg[1]? 2 : INF);
	for(int i=1; i<MAXN; ++i){
		if(i<10 && flg[i]==1) dp[i] = 2;
		else dp[i] = -1;
	}
}
int avail(int n){
	if(flg[n] != -1) return flg[n];
	int tmp = avail(n/10);
	if(flg[n%10]!=0 && tmp!=0) flg[n] = tmp+1;
	else flg[n] = 0;
	return flg[n];
}
int dfs(int n){
	// printf("[%d, %d]\n", n, avail(n));
	if(dp[n] != -1) return dp[n];
	int ret = avail(n)+1;
	if(ret == 1) ret = INF;
	for(unsigned i=0; i<vec[n].size(); ++i){
		int av = avail(vec[n][i])+1, tmp;
		if(av != 1){
			tmp = dfs(n/vec[n][i]) + av;
			ret = min(ret, tmp);
		}
	}
	dp[n] = ret;
	return dp[n];
}

int main(){
	build();
	int T, n;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		for(int i=0; i<10; ++i) scanf("%d", &flg[i]);
		init();
		scanf("%d", &n);
		int ans = dfs(n);
		printf("Case #%d: ", t);
		if(ans == INF) printf("Impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}

