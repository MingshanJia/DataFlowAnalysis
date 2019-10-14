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

#define MAX 305
#define DMAX 8

char str[MAX][MAX];
bool vis[MAX][MAX];

int dir[DMAX][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {-1, 0}};

int n;
void dfs(int x, int y)
{
    vis[x][y] = true;

    if (str[x][y] != 0) return ;
    for (int k = 0; k < DMAX; ++k)
    {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];

        if (0 <= dx and dx < n and 0 <= dy and dy < n and str[dx][dy] != '*' and not vis[dx][dy])
            dfs(dx, dy);
    }
}
int main()
{
    int z;
    scanf("%d", &z);
    for (int zi = 1; zi <= z; ++zi)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            scanf("%s", str[i]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (str[i][j] == '*') continue;

                int cnt = 0;
                for (int k = 0; k < DMAX; ++k)
                {
                    int dx = i + dir[k][0];
                    int dy = j + dir[k][1];

                    if (0 <= dx and dx < n and 0 <= dy and dy < n and str[dx][dy] == '*')
                        cnt++;
                }
                str[i][j] = cnt;
            }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (str[i][j] == 0 and not vis[i][j])
                    dfs(i, j), ans++;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (str[i][j] != '*' and not vis[i][j])
                    ans++;
        printf("Case #%d: %d\n", zi, ans);
    }
}

