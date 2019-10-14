#include<bits/stdc++.h>
#define N 5000005
using namespace std;
char s[N];int sum[N];int n;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T,Case=0;scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
			sum[i]=sum[i-1]+s[i]-'0';
		int m=(n+1)/2;
		int ans=0;
		for (int i=1;i<=n-m+1;i++)
			ans=max(ans,sum[i+m-1]-sum[i-1]);
		printf("Case #%d: %d\n",++Case,ans);
	}
}
