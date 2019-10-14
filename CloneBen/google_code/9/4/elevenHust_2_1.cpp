#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
typedef long long LL ;

int N , K ; 
int a[110] ; 

int dp[110][110]  ;

vector<int> pre[110] ; 

int DP(int l, int r){
	if(l > r)	return dp[l][r] = 0 ; 
	if( dp[l][r] != -1 )	return dp[l][r] ; 
	dp[l][r] = r - l + 1 ;
	
	int u , v ;
	for(int i=0;i<pre[r].size();i++){
		u = pre[r][i] ; 
		if( u < l )	continue ; 
		if( DP(u+1,r-1) != 0 )	continue ; 
		for(int j=0;j<pre[u].size();j++){
			v = pre[u][j] ; 
			if( v < l )	continue ; 
			if( DP(v+1,u-1) != 0 )	continue  ;
			dp[l][r] = min( dp[l][r] , DP(l , v-1) ) ;
		}
	}
	dp[l][r] = min( dp[l][r] , DP(l , r-1)+1 ) ; 
	return  dp[l][r] ; 
}

void gao(){
	for(int i=0;i<N;i++)	pre[i].clear() ;
	for(int i=0;i<N;i++){
		for(int j=i-1;j>=0;j--){
			if( a[j]+K == a[i] )
				pre[i].push_back(j) ;
		}
	}
}

int main(){
	int T ; scanf("%d",&T);
	int cas = 0 ; 
	while( T-- ){
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)	scanf("%d",a+i);
		memset( dp, -1, sizeof(dp) ) ;
		gao() ; 
		printf("Case #%d: %d\n" , ++cas , DP(0,N-1));
	}
	return 0 ;
}