#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>

typedef long long llint;

using namespace std;

int N, M, E, Sr, Sc, Tr, Tc;
int a[102][102];
llint dist[102][102];

priority_queue<pair<int,pair<int,int>>> PQ;

int main()
{
    int T;

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0-output.txt", "w", stdout);

    scanf("%d", &T);
    setbuf(stdout, NULL);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d %d %d %d %d %d", &N, &M, &E, &Sr, &Sc, &Tr, &Tc);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf("%d", &a[i][j]);
                a[i][j] *= -1;
                dist[i][j] = 1e9;
            }
        }
        for(int i=0;i<=N+1;i++)
            a[i][0] = a[i][M+1] = 100000;
        for(int i=0;i<=M+1;i++)
            a[0][i] = a[N+1][i] = 100000;

        dist[Sr][Sc] = 0;
        PQ.push({0, {Sr, Sc}});

        while(!PQ.empty())
        {
            auto p = PQ.top(); PQ.pop();

            llint d = -1 * p.first;
            int r = p.second.first;
            int c = p.second.second;

            if(d > dist[r][c])
                continue;

            if(a[r+1][c]!=100000 && d + a[r+1][c] < dist[r+1][c])
            {
                PQ.push({-1*(d + a[r+1][c]), {r+1, c}});
                dist[r+1][c] = d + a[r+1][c];
            }
            if(a[r-1][c]!=100000 && d + a[r-1][c] < dist[r-1][c])
            {
                PQ.push({-1*(d + a[r-1][c]), {r-1, c}});
                dist[r-1][c] = d + a[r-1][c];
            }
            if(a[r][c+1]!=100000 && d + a[r][c+1] < dist[r][c+1])
            {
                PQ.push({-1*(d + a[r][c+1]), {r, c+1}});
                dist[r][c+1] = d + a[r][c+1];
            }
            if(a[r][c-1]!=100000 && d + a[r][c-1] < dist[r][c-1])
            {
                PQ.push({-1*(d + a[r][c-1]), {r, c-1}});
                dist[r][c-1] = d + a[r][c-1];
            }
        }

        if(E >= dist[Tr][Tc])
            printf("Case #%d: %d\n", test_case, E - dist[Tr][Tc]);
        else
            printf("Case #%d: %d\n", test_case, -1);
    }

    return 0;
}