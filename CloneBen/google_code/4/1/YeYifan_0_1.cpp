#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double dp[2222][2222];
int T;
int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T,m,n;
	scanf("%d",&T);		
	for(int cas=1;cas<=T;cas++){
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&m,&n);
		dp[0][0]=1;
		for(int i=1;i<=m;i++)
		for(int j=0;j<i;j++)
		{
			if(i)dp[i][j]+=dp[i-1][j]*(m-i+1)/(m+n-i-j+1);
			if(j)dp[i][j]+=dp[i][j-1]*(n-j+1)/(m+n-i-j+1);
		}
		printf("Case #%d: %.10f\n",cas,dp[m][n]);
	}
return 0;
}