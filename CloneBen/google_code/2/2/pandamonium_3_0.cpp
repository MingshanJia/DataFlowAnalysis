#include <bits/stdc++.h>
using namespace std;
int t,dp[10005],n;
int main(){
	scanf("%d",&t);
	dp[0]=0;
	for(int x=1;x<=10000;x++){
		dp[x]=4;
		for(int y=1;y<=10000;y++){
			if(y*y>x) break;
			dp[x]=min(dp[x],dp[x-y*y]+1);
		}
	}
	for(int tc=1;tc<=t;tc++){
		scanf("%d",&n);
		printf("Case #%d: %d\n",tc,dp[n]);
	}
	return 0;
}
