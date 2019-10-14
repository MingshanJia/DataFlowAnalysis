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
int D,I,M,N;

struct state
{
    int pos, value, answer;
    
    state(){};
    state(int a, int b, int c)
    { pos = a, value = b; answer = c; }
    
    bool operator<(const state &b) const
    {
        return answer > b.answer;
    }
};

int a[104];
int dist[103][258];
bool used[103][258];

priority_queue<state> q;

void check(int pos, int val, int ans)
{
    if (!used[pos][val] && dist[pos][val] > ans)
    {
//        cout<<"       to "<<pos<<" "<<val<<" with "<<ans<<"\n";
        dist[pos][val] = ans;
        q.push(state(pos, val, ans));
    }
}

int main()
{
    scanf("%d",&T);
    F(xx,T)
     {
            scanf("%d%d%d%d", &D, &I, &M, &N);
            for (int i=1;i<=N;i++)
            {
                scanf("%d", a + i);
                a[i]++;
            }
            memset(dist,127,sizeof(dist));
            memset(used,0,sizeof(used));
            while (!q.empty())
            {
                q.pop();
            }
            q.push(state(0,0,0));
            int answer = -1;
            while (!q.empty())
            {
                int pos = q.top().pos;
                int val = q.top().value;
                int ans = q.top().answer;
                q.pop();
                if (used[pos][val])
                {
                    continue;
                }
                if (pos == N)
                {
                    answer = ans;
              //      cout<<"kjsdfgkjdsfghlkdfs\n";
                    break;
                }
                used[pos][val] = 1;
               // cout<<" at "<<pos<<" "<<val<<" : "<<ans<<"\n";
                
                check(pos + 1, val, ans + D);
                
                int start = val - M; if (start < 1) start = 1;
                int finish = val + M; if (finish > 256) finish = 256;
                if (val == 0)
                {
                    start = 1; finish = 256;
                }
                for (int i = start; i <= finish; i++)
                {
                        check(pos + 1, i, ans + abs(i - a[pos + 1]));
                        check(pos, i, ans + I);
                }
            }
            printf("Case #%d: %d\n", xx + 1, answer);
     }
    return 0;
}
