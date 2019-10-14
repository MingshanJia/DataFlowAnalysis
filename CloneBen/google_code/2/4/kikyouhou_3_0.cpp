#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#include<map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 300010
#define LL long long
#define RUN
using namespace std;

int n;
int pow2[MAX];
int dp[MAX];

int main(){
#ifdef RUN
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
#endif
	for (int i = 1; i <= 100; i++){
		pow2[i] = i * i;
	}
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++){
		scanf("%d", &n);
		mem(dp, -1);
		dp[0] = 0;
		for (int i = 1; i <= 100; i++){
			for (int j = 0; j < n; j++){
				if (pow2[i] + j > n) break;
				if (dp[j + pow2[i]] == -1){
					dp[j + pow2[i]] = dp[j] + 1;
				}
				else if (dp[j + pow2[i]] > dp[j] + 1){
					dp[j + pow2[i]] = dp[j] + 1;
				}
			}
		}
		printf("Case #%d: %d\n", ii, dp[n]);
	}
	return 0;
}