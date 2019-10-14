
#define ll long long
#define vi vector <int>
#define pii pair <int,int>
#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <cassert>


using namespace std;

const int N = 303;

char g[N][N];
bool vst[N][N];
int n;

int dx[]={+1,-1 ,+1,-1,0, +1,-1,0};
int dy[]={0,0,  +1,+1,+1, -1,-1,-1};

bool f(int x,int y)
{
    if(g[x][y]!='.')return false;
    bool b=0;
    for(int i=0;i<8;i++)
    {
        b|=( g[x+dx[i]][y+dy[i]]=='*' );
        if(b)return false;
    }
    return true;
}

void dfs(int x,int y)
{
    vst[x][y]=1;

    if(!f(x,y))return;

    for( int i=0;i<8;i++ )
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(vst[nx][ny])continue;

        dfs(nx,ny);
    }
}

int main()
{
    freopen("ain.in","r",stdin);
    freopen("aout.txt","w",stdout);

    int i,j,k,t,ks=0;
    cin>>t;
    while(t--)
    {
        ++ks;
        cin>>n;

        SET(vst,0);
        SET(g,0);

        for(i=1;i<=n;i++)
        {
            scanf("%s",g[i]+1);
        }
        k=0;
        for( i=1;i<=n;i++ )
        {
            for(j=1;j<=n;j++)
            {
                if( !vst[i][j] && f( i,j ) )
                {
                    k++;
                    dfs( i,j );
                }
            }
        }
        for( i=1;i<=n;i++ )
        {
            for(j=1;j<=n;j++)
            {
                if( !vst[i][j] && g[i][j]=='.' )
                {
                    k++;
                }
            }
        }


        printf("Case #%d: %d\n",ks,k);
    }

    return 0;
}




















