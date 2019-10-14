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

#define maxm 150
#define inf (1<<29)
#define ii __int64

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

int n;
ii K;
ii lim;

ii dp[maxm][maxm];
bool vis[maxm][maxm];

ii cal(int rem,int open){

    if(open<0) return 0;
    if(!rem && !open) return 1;
    if(rem<=0)          return 0;

    if(vis[rem][open]) return dp[rem][open];
    vis[rem][open]=1;

    ii ret=0;

    ret=cal(rem-1,open+1);
    if(ret>lim){
        return dp[rem][open]=lim+1;
    }
    ret+=cal(rem-1,open-1);
    if(ret>lim){
        return dp[rem][open]=lim+1;
    }
    return dp[rem][open]=ret;
}

void find_ans(int n,ii K,int open){

	if(n<=0) return ;

    if(cal(n,open)<K){
        printf("Doesn't Exist!");
        return ;
    }

    int i;

    // open .. ..

    if(cal(n-1,open+1)>=K){
        printf("(");
        find_ans(n-1,K,open+1);
        return ;
    }
    else{
        printf(")");
        find_ans(n-1,K-cal(n-1,open+1),open-1);
    }
}

int main(){

    int i,j,k,l,test,t=1;

	lim=1;
	for(i=1;i<=18;i++){
		lim*=(ii)10;
	}


    freopen("d1.in","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %I64d",&n,&K);

		n+=n;
        printf("Case #%d: ",t++);

        find_ans(n,K,0);
        puts("");
    }

    return 0;
}

