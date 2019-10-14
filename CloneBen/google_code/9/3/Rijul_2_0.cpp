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

#define maxm 201
#define inf (1<<29)
#define ii int

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

int n,K;
int a[maxm];

int dp[maxm][maxm];
bool vis[maxm][maxm];

int cal(int beg,int end){

    if(beg>end) return 0;

    if(vis[beg][end]) return dp[beg][end];
    vis[beg][end]=1;

    int i,j;
    int ret=cal(beg+1,end)+1;

    for(i=beg+1;i<=end;i++){
        if(a[beg]+K!=a[i]) continue;
        if(cal(beg+1,i-1)) continue;
        for(j=i+1;j<=end;j++){
            if(a[i]+K!=a[j]) continue;
            if(cal(i+1,j-1)) continue;
            ret=mini(ret,cal(j+1,end));
        }
    }

    return dp[beg][end]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("c.in","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&K);

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }

        memset(vis,0,sizeof(vis));

        printf("Case #%d: %d\n",t++,cal(1,n));
    }

    return 0;
}

