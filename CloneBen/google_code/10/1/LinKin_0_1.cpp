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

long LED[] = { 126,48,109,121,51,91,95,112,127,123 };
long N;
long A[MAX+7];
long B[MAX+7];

int main( void )
{
    long i,j,s,Icase,k = 0;
    char str[107];

    //freopen("text1.txt","r",stdin );
    freopen("a.in","r",stdin );
    freopen("a.out","w",stdout );

    scanf("%ld",&Icase );
    while( Icase-- ){
        scanf("%ld",&N );
        for( i=0;i<N;i++ ){
            scanf("%s",str );
            A[i] = 0;
            for( j=0;j<7;j++ ){
                A[i] = 2*A[i] + str[j]-'0';
            }
        }
        vector<long> ans;
        long d = (1<<7)-1;
        long c = 0;
        while( d>=0 ){
            for( s=0;s<=9;s++ ){
                for( i=0;i<=N;i++ ){
                    B[i] = (s-i+10000)%10;
                }
                for( i=0;i<N;i++ ){
                    if( i>=10 and A[i]!=A[i-10] ) break;
                    if( A[i] & d ) break;
                    long t = A[i] & ~LED[B[i]];
                    if( t ) break;
                    t = ~A[i] & LED[B[i]];
                    if( (t & d) != t ) break;
                }
                if( i<N ) continue;
                ans.pb( LED[B[N]] & ~d );
            }
            d--;
        }
        sort( ALL( ans ) );
        ans.resize( unique( ALL( ans ) ) - ans.begin() );
        if( ans.size() != 1 ) printf("Case #%ld: ERROR!\n",++k );
        else{
            char str[107] = {0};
            for( i=6;i>=0;i-- ){
                str[i] = '0' + (ans[0]%2);
                ans[0] /= 2;
            }
            printf("Case #%ld: %s\n",++k,str );
        }
    }


    return 0;
}
