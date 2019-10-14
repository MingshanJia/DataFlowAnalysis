#include <bits/stdc++.h>
using namespace std;
double dp[5000][2500],ans;

double solve(int n, int m){
	//cout<<n << " "<<m<<endl;
	if(n<=m || m<0)
		return 0;
	if(dp[n][m]==-1)
		return 0;
	if(dp[n][m]>0)
		return dp[n][m];
	return (n*1./(m+n))*solve(n-1,m)+(m*1./(m+n))*solve(n,m-1);
}

int main(){
	int tt,t=1;
	int n,m,i,j;
	cin >>tt;
	while(tt--) {
		memset(dp,0,sizeof dp);
		dp[1][0]=1;
		cin >> n >> m;
		ans=solve(n,m);
		printf("Case #%d: %0.7f\n",t++,ans);
	}
	return 0;
}