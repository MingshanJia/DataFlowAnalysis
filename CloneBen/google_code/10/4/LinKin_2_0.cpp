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

#define MAX 100007

Long N,Q;
vector<Pll> ed[MAX+7];
Long vi[MAX+7][2],TRUE;
Long di[MAX+7][2];

bool Dfs( Long u, bool b, Long trV, bool trB ){
    vi[u][b] = TRUE;
    if( u==trV and b==trB ) return true;
    Long i;
    for( i=0;i<ed[u].size();i++ ){
        Long v = ed[u][i].ff;
        Long c = ed[u][i].ss;
        if( vi[v][!b] == TRUE ) continue;
        if( !b ) di[v][!b] = di[u][b] + c;
        else di[v][!b] = di[u][b] - c;
        if( Dfs( v, !b, trV, trB ) ) return true;
    }
    return false;
}


int main( void )
{
    Long i,j,u,v,c,Icase,k = 0;
    char str[107],tmp[107];

    //freopen("text1.txt","r",stdin );
    freopen("c.in","r",stdin );
    freopen("c.out","w",stdout );

    scanf("%I64d",&Icase );
    while( Icase-- ){
        scanf("%ld",&N );
        map<string,Long> ind;
        for( i=1;i<=N;i++ ){
            scanf("%s",str );
            char *p = strtok( str,"+=" );
            string s1 = p;
            if( ind.find( s1 ) == ind.end() ) ind[s1] = ind.size();
            p = strtok( NULL,"+=" );
            string s2 = p;
            if( ind.find( s2 ) == ind.end() ) ind[s2] = ind.size();
            p = strtok( NULL,"+=" );
            ed[ind[s1]].pb( MP( ind[s2], atol( p ) ) );
            ed[ind[s2]].pb( MP( ind[s1], atol( p ) ) );
        }

        scanf("%I64d",&Q );
        printf("Case #%I64d:\n",++k );
        while( Q-- ){
            scanf("%s",str );
            strcpy( tmp,str );
            char *p = strtok( str,"+=" );
            string s1 = p;
            if( ind.find( s1 ) == ind.end() ) continue;
            p = strtok( NULL,"+=" );
            string s2 = p;
            if( ind.find( s2 ) == ind.end() ) continue;
            TRUE++;
            di[ind[s1]][0] = 0;
            if( !Dfs( ind[s1], 0, ind[s2], 1 ) ) continue;
            printf("%s=%I64d\n",tmp,di[ind[s2]][1] );
        }

        for( i=0;i<=ind.size();i++ ){
            ed[i].clear();
        }
    }

    return 0;
}
