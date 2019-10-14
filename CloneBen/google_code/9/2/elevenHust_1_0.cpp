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

const int NN = 401 * 200 + 100 ;

int B ,L, N ; 
int pre[3][NN] ; 

void calc(int n, int &rr , int &cc){
	int l = 1 , r = 400 , m , tmp ; 
	while(l < r){
		m = (l + r) >> 1 ;
		tmp = (1 + m) * m / 2 ; 
		if( n <= tmp )	r = m ; 
		else	l = m + 1 ;
	}
	rr = l ; 
	tmp = (l - 1) * l / 2 ; 
	cc = n - tmp ;
}


int ab(int r, int c){
	int res = (r-1) * r / 2 ; 
	return res + c ; 
}

void gao(){
	int r ,c ; 
	memset( pre, -1 , sizeof(pre) ) ;
	for(int i=1;i<=401*200;i++){
		calc(i , r , c ) ; 
		if( c != 1 && r != 1){
			pre[0][i] = ab(r-1,c-1) ;  
		}
		if( c != r && r !=1 )
			pre[1][i] = ab(r-1,c) ;
		if( r != 400 )
			pre[2][i] = i ;
	}
}

double ans ; 

double go(int l , int n){
	if( (l + 1)*l/2 < n )	return 0 ; 
	double res = 0 ; 
	if(l==1){	
		res = B * 750 ; 
		if(L == l){
			if( res >= 250 )	ans = 250 ;
			else	ans = res ; 
		}
		if( res >= 250 )	return res - 250  ;
		else	return 0 ;
	}
	if( pre[0][n] != -1 )
		res += go(l-1, pre[0][n] ) / 3 ; 
	if( pre[1][n] != -1 )
		res += go(l-1, pre[1][n] ) / 3 ;
	if( pre[2][n] != -1 ){
		res += go(l-1, pre[2][n] ) / 3 ;
	}
	if( l == L ){
		if( res >= 250 )	ans = 250 ; 
		else	ans = res ;
	}
//	printf("%d %d %lf\n",l,n,res);
	if( res >= 250 )	return (res - 250) ;
	else	return 0 ; 
}

int main(){
//	freopen("E:\\C++\\stdin.in","r",stdin);
	gao() ; 
	int T ;
	scanf("%d",&T);
	int cas = 0 ;
	while( T-- ){
		scanf("%d%d%d",&B,&L,&N);
		go(L, N) ; 
		printf("Case #%d: %lf\n",++cas,ans);
	}
	return 0 ;
}