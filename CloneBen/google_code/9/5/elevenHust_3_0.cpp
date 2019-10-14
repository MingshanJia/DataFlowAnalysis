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

int N ;
LL K ;
LL dp[110][110]  ;
const LL Max = 1e18+10 ;
void check(LL &n,LL M){
	if(n > M)	n = M ; 
}

void gao(){
	memset( dp , 0 , sizeof(dp) ) ;
	dp[0][0]  = 1 ; 
	for(int i=0;i<=100;i++){
		for(int j=0;j<=i;j++) if( dp[i][j] != 0){
			dp[i+1][j] += dp[i][j] ; 
			check( dp[i+1][j] , Max ) ; 
			if(i >= j+1){
				dp[i][j+1] += dp[i][j] ;
				check( dp[i+1][j] , Max ) ;
			}
		}
	}
}

char ans[220] ; 

void solve(int l ,int r,  LL k,int idx){
	if(l == 0){
		if(r == 0)	return ;
		ans[idx] = ')' ; 
		solve(l , r-1,k, idx+1 ) ;
		return ; 
	}
	if( dp[r][l-1] >= k ){
		ans[idx] = '(' ; 
		solve(l-1 , r , k , idx+1 ) ; 
		return ; 
	}
	ans[idx] = ')' ; 
	solve(l , r-1, k - dp[r][l-1] , idx+1 ) ;
}

int main(){
	int T ; 
	cin >> T ; 
	int cas = 0 ; 
	gao() ; 
	while( T-- ){
		cin >> N >> K  ; 
		if( dp[N][N] < K ){
			printf("Case #%d: Doesn't Exist!\n",++cas);
			continue ;
		}
		solve(N , N ,  K, 0) ; 
		ans[N * 2] = 0 ;
		printf("Case #%d: %s\n",++cas,ans);
	}

	return 0 ;
}