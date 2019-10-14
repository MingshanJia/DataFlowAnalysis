#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double A[400],dp[210][210];
int len,b[10][10],n,d[20],go[30][30],pd[20],num1,num2,num3,ans;
char ch[10];
void dfs(int k){
	pd[k]=1; if (k>n) num2++; else num1++;
	for (int i=1;i<=n*2;i++)
		if (go[k][i]){
			num3++; if (pd[i]==0) dfs(i);
		}
}
int check(){
	memset(go,0x00,sizeof go);
	memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) go[i][j+n]=b[i][j],go[j+n][i]=b[i][j];
//	for (int i=1;i<=n*2;i++){
//		for (int j=1;j<=n*2;j++) cout<<go[i][j]<<" "; cout<<endl;
//	}
	for (int i=1;i<=n*2;i++)
		if (pd[i]==0){
			num1=0; num2=0; num3=0;
			dfs(i);
			//cout<<num1<<" "<<num2<<" "<<num3<<endl;
			if (num1!=num2||num3!=num1*num2*2) return 0;
		}
//	while (1);
	return 1;
}
void dfs(int k1,int k2,int k3){
	if (k2>n) k1++,k2=1;
	if (k1>n){
		if (check()) ans=min(ans,k3); return;
	}
	if (b[k1][k2]) dfs(k1,k2+1,k3);
	else {
		dfs(k1,k2+1,k3); b[k1][k2]=1; dfs(k1,k2+1,k3+1); b[k1][k2]=0;
	}
}
int solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for (int j=1;j<=n;j++) b[i][j]=ch[j]-'0';
	}
	ans=100;
	dfs(1,1,0);
	return ans;
}
int main(){
	freopen("Ds.in","r",stdin);
	freopen("Ds.out","w",stdout);
	int t; scanf("%d",&t);
	for (int tt=1;tt<=t;tt++){
		printf("Case #%d: %d\n",tt,solve());
	}
}
