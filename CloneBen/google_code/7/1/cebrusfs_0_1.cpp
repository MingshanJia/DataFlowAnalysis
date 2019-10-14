// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define IOS ios_base::sync_with_stdio(false)

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front


// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;
#endif

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 1005

int dp[MAX][MAX];
int ary[MAX][MAX];

PII idx[MAX * MAX];


int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
void update(int n, int r, int c)
{
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
    {
        int x = r + dir[i][0];
        int y = c + dir[i][1];

        if (0 <= x and x < n and 0 <= y and y < n and ary[x][y] == 1 + ary[r][c])
            cnt = max(dp[x][y], cnt);
    }
    dp[r][c] = cnt + 1;
}

int main()
{
    int z;
    scanf("%d", &z);
    for (int zi = 1; zi <= z; ++zi)
    {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &ary[i][j]);
                idx[ary[i][j]] = MP(i, j);
            }

        int ans = -1, ansd = -1;
        memset(dp, 0, sizeof(dp));
        for (int i = n * n; i >= 1; --i)
        {
            PII p = idx[i];
            update(n, p.first, p.second);

            if (dp[p.first][p.second] >= ansd)
            {
                ans = ary[p.first][p.second];
                ansd = dp[p.first][p.second];
            }
        }
        printf("Case #%d: %d %d\n", zi, ans, ansd);
    }
}

