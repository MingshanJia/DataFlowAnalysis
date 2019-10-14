#pragma comment(linker, "/STACK:16777216")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<list>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define SZ(a) ((long)a.size())
#define ALL(a) a.begin(),a.end()
#define FOREACH(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define AREA2(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define SQR(x) ((x)*(x))
#define STR string
#define IT iterator
#define ff first
#define ss second
#define MP make_pair
#define EPS 1e-9
#define INF 10000000000000007LL

#define chk(a,k) ((bool)(a&(1<<(k))))
#define set0(a,k) (a&(~(1<<(k))))
#define set1(a,k) (a|(1<<(k)))

typedef long long Long;
typedef vector<long> Vl;
typedef vector<Long> VL;
typedef pair<long,long> Pll;
typedef pair<Long,Long> PLL;

inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

long IR[] = { 0,-1,0,1,-1,-1,1,1 };
long IC[] = { 1,0,-1,0,1,-1,-1,1 };

#define MAX 107

long N;
long G[MAX+7][MAX+7];
long Tmp[MAX+7][MAX+7];

void Rotate( void ){
    CLR( Tmp );
    long i,j;
    for( i=1;i<=N;i++ ){
        for( j=1;j<=N;j++ ){
            Tmp[j][N-i+1] = G[i][j];
        }
    }
    memcpy( G,Tmp,sizeof(G) );
}


void Set( void ){
    CLR( Tmp );
    long r,i;
    for( r=1;r<=N;r++ ){
        vector<long> vc;
        for( i=1;i<=N;i++ ){
            if( G[r][i] ) vc.pb( G[r][i] );
        }
        long I = N;
        while( vc.size() ){
            if( vc.size()>=2 and vc[vc.size()-1] == vc[vc.size()-2] ){
                Tmp[r][I--] = 2*vc[vc.size()-1];
                vc.pop_back();
                vc.pop_back();
            }
            else{
                Tmp[r][I--] = vc[vc.size()-1];
                vc.pop_back();
            }
        }
    }
    memcpy( G,Tmp,sizeof(G) );
}

int main( void )
{
    long i,j,Icase,k = 0;
    string str;

    //freopen("text1.txt","r",stdin );
    freopen("b.in","r",stdin );
    freopen("b.out","w",stdout );

    scanf("%ld",&Icase );
    while( Icase-- ){
        cin>>N>>str;
        for( i=1;i<=N;i++ ){
            for( j=1;j<=N;j++ ){
                scanf("%ld",&G[i][j] );
            }
        }
        if( str=="right" ){
            Set();
        }
        else if( str=="up" ){
            Rotate();
            Set();
            Rotate();
            Rotate();
            Rotate();
        }
        else if( str=="left" ){
            Rotate();
            Rotate();
            Set();
            Rotate();
            Rotate();
        }
        else if( str=="down" ){
            Rotate();
            Rotate();
            Rotate();
            Set();
            Rotate();
        }
        printf("Case #%ld:\n",++k );
        for( i=1;i<=N;i++ ){
            for( j=1;j<=N;j++ ){
                if( j>1 ) printf(" ");
                printf("%ld",G[i][j] );
            }
            printf("\n");
        }
    }

    return 0;
}
