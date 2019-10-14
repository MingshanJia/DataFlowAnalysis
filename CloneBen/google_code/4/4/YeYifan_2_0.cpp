#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
long long dp[4444];
int T,cnt[4444][26],n;
int val[444][26];
int lim[444];
char s[4444];
void solve(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		for(int j=0;j<26;j++)cnt[i][j]=cnt[i-1][j];
		cnt[i][s[i]-'a']++;
	}
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=len;i++)
	for(int j=1;j<=n;j++)
	if(lim[j]<=i){
		bool can=1;
		for(int k=0;k<26;k++)if(cnt[i][k]-cnt[i-lim[j]][k]!=val[j][k])can=0;
		if(can)dp[i]=(dp[i]+dp[i-lim[j]])%mod;
	
	}
	printf(" %lld",dp[len]);
}
int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		char s[33];
		scanf("%d",&n);
		int Q;
		scanf("%d",&Q);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			int len=strlen(s+1);
			lim[i]=len;
			for(int j=0;j<26;j++)val[i][j]=0;
			for(int j=1;j<=len;j++)
			val[i][s[j]-'a']++;
		}
		
		
		printf("Case #%d: ",cas);
		for(int i=1;i<=Q;i++)solve();
		puts("");
	}

return 0;
}