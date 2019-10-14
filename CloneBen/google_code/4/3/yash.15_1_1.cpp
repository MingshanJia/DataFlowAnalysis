#include <bits/stdc++.h>
using namespace std;
int a[500];
int dp[500][3];
int main(){
	int tt,t=1;
	int n,m,i,j,k,ans,a2;
	cin >>tt;
	while(tt--) {
		cin >> n >> m;
		if(n>m)
			swap(n,m);
		for(i=1,k=0;i<=n;i++,k++)
			a[k]=i;
		for(i=n+1;i<=m;i++,k++)
			a[k]=n;
		for(i=n-1;i;i--,k++)
			a[k]=i;
		dp[0][0]=dp[0][2]=0;
		dp[0][1]=1;
		for(i=1;i<n+m-1;i++){
			dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			dp[i][1]=a[i]+dp[i-1][0];
			dp[i][2]=a[i]+dp[i-1][1];
		}

		ans=max(dp[n+m-2][0],max(dp[n+m-2][1],dp[n+m-2][2]));
		if(n==2 && m==2)
			ans=4;
		a2=(n/3)*(m/3)*5+(n/3)*(2*(m%3))+(m/3)*(2*(n%3))+(n%3)*(m%3);
		printf("Case #%d: %d\n",t++,max(ans,a2));
	}
	return 0;
}