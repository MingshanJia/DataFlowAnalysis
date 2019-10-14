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

int dp[1000][1000];

int solve(int a, int b)
{
    if (a <= 0 || b <= 0)
        return 1;
    int &ret = dp[a][b];
    if (ret > -1)
        return ret;
    ret = 0;
    int A = a, B = b;
    while (a - B > 0)
    {
        a -= B;
        if (!solve(a, B))
        {
            ret = 1; goto end;
        }
    }
    while (b - A > 0)
    {
        b -= A;
        if (!solve(A, b))
        {
            ret = 1; goto end;
        }
    }
    end:;
    return ret;
}

const int MAXA = 1000100;
int l[MAXA], r[MAXA];

bool win(int a, int b)
{
    return b < l[a] || b > r[a];
}


int main()
{

    scanf("%d",&T);
    memset(dp, -1, sizeof(dp));
    F(xx,T)
     {
        int A1, B1, A2, B2;
        scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
        l[1] = r[1] = 1;
        int b = 1;
        long long answer = 0;
        if (A1 == 1)
        {
            int left = 2;
            if (left < B1) left = B1;
            int right = B2;
            if (left <= right)
                answer = right - left + 1;
        }
        for (int a = 2; a <= A2; a++)
        {
            if (win(b, a))
                b++;
            l[a] = b;
            r[a] = b + a - 1;
            if (a >= A1)
            {
                int left = 1;
                int right = l[a] - 1;
                if (left < B1) left = B1;
                if (right > B2) right = B2;
                if (left <= right)
                    answer += right - left + 1;
                    
                left = r[a] + 1;
                if (left < B1) left = B1;
                right = B2;
                if (left <= right)
                    answer += right - left + 1;

            }
        }
        
        cout<<"Case #"<<xx+1<<": "<<answer<<"\n";
     }
    return 0;
}


