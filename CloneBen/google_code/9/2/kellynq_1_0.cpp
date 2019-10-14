
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 410
#define maxm 410*410

int x[maxn*maxn],y[maxn*maxn];
double dp[2][maxn*maxn];
int cnt[maxn*maxn];

void init(){
	int index=0;
	for(int i=1;i<maxn;i++) {
		for(int j=1;j<=i;j++){
			++index;
			x[index]=i;
			y[index]=j;
		}
	}
	for(int i=1;i<maxn;i++)
		cnt[i]=i*(i+1)/2;
}

int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	init();
	int B,L,N,cs=0,t=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&B,&L,&N);
		int flag=0;
		
		dp[flag][1]=B*750;
		for(int i=1;i<L;i++){
			for(int j=1;j<=cnt[i+1];j++)	dp[1-flag][j]=0;
			for(int j=1;j<=cnt[i];j++){
				double sum=0;
				if(dp[flag][j]>250)	sum = (dp[flag][j]-250)/3;
				dp[1-flag][j]+=sum;
				int xi=x[j];
				int yi=y[j];
				int l = cnt[xi] + yi;
				dp[1-flag][l]+=sum;
				dp[1-flag][l+1]+=sum;
			}
			flag=1-flag;
		}
		double ans;
		if(dp[flag][N]>=250)	ans=250;
		else ans = dp[flag][N];
		printf("Case #%d: %.7lf\n",++cs,ans);
	}
	return 0;
}
	 
