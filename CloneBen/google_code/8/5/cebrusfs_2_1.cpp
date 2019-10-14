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

#define MAX 10
#define VMAX 1000005
const int INF = 1e9;

int used[MAX];
int dp[VMAX];

int check(int v)
{
    char s[20];
    sprintf(s, "%d", v);

    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        if (not used[s[i] - '0'])
            return -1;

    return n;
}

int main()
{
    int z;
    scanf("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        fprintf(stderr, "solve %d\n", zi);
        for (int i = 0; i < MAX; ++i)
            scanf("%d", &used[i]);
        int x;
        scanf("%d", &x);

        for (int i = 0; i <= x; ++i)
        {
            int c = check(i);
            dp[i] = c == -1 ? INF : c;
        }

        for (int i = 2; i * i <= x; ++i)
        {
            if (x % i != 0) continue;

            int k = i;
            int len = check(k);
            if (len != -1)
            {
                for (int j = k; j <= x; j += k)
                    dp[j] = min(dp[j], dp[j / k] + len + 1);
            }

            k = x / i;
            len = check(k);
            if (len != -1)
            {
                for (int j = k; j <= x; j += k)
                    dp[j] = min(dp[j], dp[j / k] + len + 1);
            }
        }
        //for (int j = 1; j <= x; ++j)
        //    printf("%d = %d\n", j, dp[j]);

        printf("Case #%d: ", zi);
        if (dp[x] == INF)
            printf("Impossible\n");
        else
            printf("%d\n", dp[x] + 1);

        
    }
    
}

