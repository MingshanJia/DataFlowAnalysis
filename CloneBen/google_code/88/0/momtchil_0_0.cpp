#include <vector>
#include <cstring>
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
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


#define SZ size()
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define x first
#define y second

#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define PI pair<int,int>
#define PD pair<double,double>
#define PLL pair<LL,LL>
#define PULL pair<ULL,ULL>
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define SI set<int>
#define PQ priority_queue
#define VVI vector<vector<int> >
#define IT iterator

#define ABS(x) (((x)>0)?(x):(-(x)))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define sign(a) ((a)>0)-((a)<0)
#define sqr(a) ((a)*(a))
#define F(i,n) for (int i=0;i<n;i++)
#define Repi(n) for (int i=0; i<n; i++)
#define Repj(n) for (int j=0; j<n; j++)
#define Repk(n) for (int k=0; k<n; k++)
#define F(i,n) for (int i=0;i<n;i++)

#define INF 2000000000
#define EPS 1e-6

#define Time ((double)clock()/CLOCKS_PER_SEC)
#define pause system("pause")

using namespace std;

int T;

char a[64][64];
int dp[64][64][4];
int N,K;

bool check(char col)
{
            memset(dp, 0, sizeof(dp));
            bool red = 0;
            Repi(N)
             Repj(N)
                if (a[i][j] == col)
                {
                    dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 1;
                    if (i > 0)
                     {
                            int prev = dp[i - 1][j][0];
                            if (prev + 1 > dp[i][j][0])
                                dp[i][j][0] = prev + 1;
                     }
                    if (j > 0)
                     {
                            int prev = dp[i][j - 1][1];
                            if (prev + 1 > dp[i][j][1])
                                dp[i][j][1] = prev + 1;
                     }
                    if (i > 0 && j > 0)
                     {
                            int prev = dp[i - 1][j - 1][2];
                            if (prev + 1 > dp[i][j][2])
                                dp[i][j][2] = prev + 1;
                     }
                    if (i > 0)
                     {
                            int prev = dp[i - 1][j + 1][3];
                            if (prev + 1 > dp[i][j][3])
                                dp[i][j][3] = prev + 1;
                     }
                    Repk(4)
                    if (dp[i][j][k] == K)
                    {
                        return true;
                    }
                }
     return false;
}
int main()
{
    scanf("%d",&T);
    F(xx,T)
     {
            scanf("%d%d", &N, &K);
            Repi(N)
             {
                    scanf("%s", a[i]);
             }
            for (int row = N - 1; row >=0; row--)
            {
                    int ncol = N - 1;
                    for (int col = N - 1; col >= 0; col--)
                    {
                        if (a[row][col] != '.')
                        {
                                swap(a[row][ncol--], a[row][col]);
                        }
                    }
            }
            bool red = check('R');
            bool blue = check('B');
            
            if (!red && !blue)
            {
                printf("Case #%d: Neither\n", xx + 1);
            }
            if (red && !blue)
            {
                printf("Case #%d: Red\n", xx + 1);
            }
            if (!red && blue)
            {
                printf("Case #%d: Blue\n", xx + 1);
            }
            if (red && blue)
            {
                printf("Case #%d: Both\n", xx + 1);
            }

            
     }
    return 0;
}
