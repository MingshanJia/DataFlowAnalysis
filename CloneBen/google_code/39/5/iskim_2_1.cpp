#include <bits/stdc++.h>
using namespace std;

char dat[55][55];
int idx[55][55];
int r, c;
constexpr int dr[4][2]=
{
    0,1,
    1,0,
    0,-1,
    -1,0
};

struct beam
{
    bitset<250> gflag;
    bitset<250> sflag;
    bool g, s;
    int x, y;
};

bool visit[55][55][4];
int lidx;

namespace SCC
{
    const int MAXN = 5000;
    vector<int> graph[MAXN];
    int up[MAXN], visit[MAXN], vtime;
    vector<int> stk;
    int scc_idx[MAXN], scc_cnt;
    int n;
    void dfs(int nod) {
        up[nod] = visit[nod] = ++vtime;
        stk.push_back(nod);
        for (int next : graph[nod]) {
            if (visit[next] == 0) {
                dfs(next);
                up[nod] = min(up[nod], up[next]);
            }
            else if (scc_idx[next] == 0)
                up[nod] = min(up[nod], visit[next]);
        }
        if (up[nod] == visit[nod]) {
            ++scc_cnt;
            int t;
            do {
                t = stk.back();
                stk.pop_back();
                scc_idx[t] = scc_cnt;
            } while (!stk.empty() && t != nod);
        }
    }
    // find SCCs in given directed graph
    // O(V+E)
    // the order of scc_idx constitutes a reverse topological sort
    void get_scc() {
        vtime = 0;
        memset(visit, 0, sizeof(visit));
        scc_cnt = 0;
        memset(scc_idx, 0, sizeof(scc_idx));
        stk.clear();
        for (int i = 0; i < n; ++i)
            if (visit[i] == 0) dfs(i);
    }
}

pair<int, int> process(int x, int y, int d, int *fin = nullptr)
{
    memset(visit, 0, sizeof(visit));

    queue<tuple<int, int, int>> que;
    x += dr[d][0];
    y += dr[d][1];

    for (;;)
    {
        if (visit[x][y][d]) return {-1, -1};

        if (x < 0 || y < 0 || x >= r || y >= c) return {-1, -1};
        if (dat[x][y] == '#') return {-1, -1};
        if (dat[x][y] == '-' || dat[x][y] == '|')
        {
            if (fin) *fin = d;
            return {x, y};
        }
        visit[x][y][d] = true;

        if (dat[x][y] == '/')
        {
            d ^= 3;
        }
        else if (dat[x][y] == '\\')
        {
            d ^= 1;
        }

        x += dr[d][0];
        y += dr[d][1];
    }
}

bool process(int x, int y)
{
    if (dat[x][y] == '-' || dat[x][y] == '|')
    {
        pair<int, int> res[4];
        for (int i = 0; i < 4; i++) res[i] = process(x, y, i);

        int sub = 2;

        if (res[0].first != -1 || res[2].first != -1)
        {
            SCC::graph[idx[x][y]].push_back(idx[x][y] + lidx);
            --sub;
        }
        if (res[1].first != -1 || res[3].first != -1)
        {
            SCC::graph[idx[x][y] + lidx].push_back(idx[x][y]);
            --sub;
        }

        return sub;
    }

    if (dat[x][y] == '.')
    {
        pair<int, int> res[4];
        int fin[4];
        for (int i = 0; i < 4; i++) res[i] = process(x, y, i, &fin[i]);

        int X = -1, Y = -1;

        if ((res[0].first == -1) != (res[2].first == -1))
        {
            if (res[0].first != -1) X = idx[res[0].first][res[0].second] + (fin[0] & 1) * lidx;
            else X = idx[res[2].first][res[2].second] + (fin[2] & 1) * lidx;
        }

        if ((res[1].first == -1) != (res[3].first == -1))
        {
            if (res[1].first != -1) Y = idx[res[1].first][res[1].second] + (fin[1] & 1) * lidx;
            else Y = idx[res[3].first][res[3].second] + (fin[3] & 1) * lidx;
        }

        if (X == -1 && Y == -1) return false;

        else if (X == -1)
        {
            SCC::graph[(Y + lidx) % (lidx * 2)].push_back(Y);
        }
        else if (Y == -1)
        {
            SCC::graph[(X + lidx) % (lidx * 2)].push_back(X);
        }
        else
        {
            SCC::graph[(X + lidx) % (lidx * 2)].push_back(Y);
            SCC::graph[(Y + lidx) % (lidx * 2)].push_back(X);
        }
    }

    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int TT = 1; TT <= T; TT++)
    {
        lidx = 0;
        printf("Case #%d: ", TT);

        scanf("%d%d",&r,&c);

        for (int i = 0; i < r; i++) scanf("%s", dat[i]);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (dat[i][j] == '|' || dat[i][j] == '-') idx[i][j] = lidx++;
            }
        }

        bool wrong = false;

        SCC::n = lidx * 2;
        for (int i = 0; i < lidx * 2; i++) SCC::graph[i].clear();

        for (int i = 0; i < r && !wrong; i++)
        {
            for (int j = 0; j < c && !wrong; j++)
            {
                if (process(i, j) == false)
                {
                    wrong = true;
                    printf("IMPOSSIBLE\n");
                    break;
                }
            }
        }

        if (!wrong) SCC::get_scc();
        for (int i = 0; i < r && !wrong; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (dat[i][j] != '-' && dat[i][j] != '|') continue;
                int x = idx[i][j];
                if (SCC::scc_idx[x] == SCC::scc_idx[x + lidx])
                {
                    printf("IMPOSSIBLE\n");
                    wrong = true;
                    break;
                }
                else if (SCC::scc_idx[x] > SCC::scc_idx[x + lidx])
                {
                    dat[i][j] = '|';
                }
                else dat[i][j] = '-';
            }
        }

        if (wrong) continue;

        printf("POSSIBLE\n");

        for (int i = 0; i < r; i++) printf("%s\n", dat[i]);
    }
}
