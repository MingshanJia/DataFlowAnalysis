#include <cstdio>
#include <cmath>
#include <iostream>

#define SIZE 110

typedef long long LL;

using namespace std;

long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}


LL fact[SIZE];

LL mod = 1000000007;

LL ncr( int n,int r ){
    return ( fact[n]* BigMod( ( fact[n-r]*fact[r] )%mod , mod-2, mod ) )%mod;
}


LL dp[SIZE][SIZE];
bool vis[SIZE][SIZE]={0};


LL func( int totake,int left ){

    //cout<<totake<<" "<<left<<endl;
    if ( left<0 )return 0;
    if ( totake == 0 ){
        if ( left == 0 )return 1;
        else return 0;
    }
    LL & ret = dp[totake][left];
    if ( vis[totake][left] )return ret;
    vis[totake][left] = true;

    ret = 0;

    for (int i=1;i<=left;++i){
        ret = ( ret + ncr( left,i ) * func( totake-1,left-i ) )%mod;
    }
    return ret;
}

int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);

    fact[0]= 1;
    for (int i=1;i<SIZE;++i){
        fact[i] = ( fact[i-1]* i )%mod;
    }

    //cout<<ncr(6,2)<<endl;

    int kase;
    scanf("%d",&kase);

    for (int kk=1; kase-- ;++kk ){

        int n,m;
        scanf("%d %d",&m,&n);

        printf("Case #%d: %lld\n",kk,func( m,n )%mod );

    }
    return 0;
}
