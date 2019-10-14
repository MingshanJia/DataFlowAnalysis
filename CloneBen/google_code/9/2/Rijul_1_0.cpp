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

#define maxm 3050
#define inf (1<<29)
#define ii double

#define cn 3005

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

//ii on(ii n,ii k){ return (n|(1<<k)); }
//ii off(ii n,ii k){ return (n-(n&(1<<k))); }
//bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int b;
int L,n;
double hold[maxm][maxm],lim;
int sum[maxm];
int last;
bool vis[maxm][maxm];
ii dp[maxm][maxm];
ii tot;

vector<int>v[maxm],vt[maxm];

ii dfst(int l,int n){

    //printf("%d %d\n",l,n);

	if(n>sum[l]) return 0;

	if(l==1){
        dp[l][n]=tot-250.0;
        hold[l][n]=250;
		dp[l][n]/=3.0;
        return dp[l][n];
	}
	if(vis[l][n]) return dp[l][n];
	vis[l][n]=1;

	ii ret=0;
	int i;

	for(i=0;i<vt[n].size();i++){
        ret+=dfst(l-1,vt[n][i]);
	}

	hold[l][n]=mini(ret,lim);
	ret-=lim;
	ret=maxi(ret,0);

	return dp[l][n]=ret/3.0;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("b1.in","r",stdin);
    freopen("out.txt","w",stdout);

    sum[1]=1;

    for(i=2;;i++){
        sum[i]=sum[i-1]+i;
        if(sum[i]>cn) break;
    }

    int now=1;
    for(i=1;i<=cn;i++){
        if(i>sum[now]){
            now++;
        }
		v[i].push_back(i);
        v[i].push_back(i+now);
        v[i].push_back(i+now+1);

		vt[i+now+1].push_back(i);
		vt[i+now].push_back(i);
		vt[i].push_back(i);
    }

    lim=250;

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d",&b,&L,&n);

        memset(hold,0,sizeof(hold));
		memset(vis,0,sizeof(vis));

		tot=b*750.0;

		ii ans=dfst(L,n);

		printf("Case #%d: %.7lf\n",t++,hold[L][n]);

    }

    return 0;
}

