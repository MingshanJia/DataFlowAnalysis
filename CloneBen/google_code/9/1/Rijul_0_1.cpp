/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-09-15
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 2010
#define inf (1<<29)
#define ii __int64

#define mod 1000000007

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int n,m;

ii dp1[maxm][maxm];
ii dp[maxm][maxm];
bool vis[maxm][maxm];

ii ncr(int i,int j){

	if(i<j) return 0;
	if(i==j||i==0||j==0) return 1;

	if(dp1[i][j]!=-1) return dp1[i][j];

	return dp1[i][j]=(ncr(i-1,j-1)%mod+ncr(i-1,j)%mod)%mod;
}

ii cal(int len,int rem){

    if(len<=0 || rem<0) return 0;
    if(rem==1) return 1;

    if(vis[len][rem]) return dp[len][rem];
    vis[len][rem]=1;

    int i;
    ii ret=0;

    for(i=1;i<=len;i++){
        ret+=(ncr(len,i)*cal(len-i,rem-1));
        if(ret>=mod) ret%=mod;
    }

    return dp[len][rem]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("A1.in","r",stdin);
    freopen("out1.txt","w",stdout);

    memset(dp1,-1,sizeof(dp));

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&m,&n);

        memset(vis,0,sizeof(vis));

        printf("Case #%d: %I64d\n",t++,cal(n,m));

    }

    return 0;
}

