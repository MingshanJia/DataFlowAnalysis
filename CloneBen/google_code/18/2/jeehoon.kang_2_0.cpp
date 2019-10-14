#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXL = 50;
const int MAXN = 20;
const int MAXM = 20;
const int MAXR = 400; // ((MAXN + 1) * (MAXM + 1)) / 2;
const int BLOCK = -2;
const int BLANK = -1;

char input_data[MAXM + 1];
int l, n, m;
int data[MAXL][MAXN][MAXM];
bool conflict[MAXL][MAXR][MAXR];
int cnt[MAXL];

class Graph
{
public:
    Graph (int ln, int rn)
    {
        init (ln, rn);
    }

    void init (int ln, int rn)
    {
        _ln = ln;
        _rn = rn;
        _graph.clear ();
        _graph.resize (ln);
    }

    void add (int l, int r)
    {
        _graph[l].push_back (r);
    }

    int match ()
    {
        _lm.clear();
        _lm.resize (_ln);
        _rm.clear();
        _rm.resize (_rn);
        _dist.clear ();
        _dist.resize (_ln);

        for (int i = 0; i < _ln; ++i)
        {
            _lm[i] = -1;
        }
        for (int i = 0; i < _rn; ++i)
        {
            _rm[i] = -1;
        }

        int result = 0;
        while (_bfs ())
        {
            for (int i = 0; i < _ln; ++i)
            {
                if (_lm[i] == -1 && _dfs (i))
                {
                    ++result;
                }
            }
        }

        return result;
    }

private:
    void _print ()
    {
        for (int i = 0; i < _ln; ++i)
        {
            printf ("%d ", _lm[i]);
        }
        printf ("\n");
        for (int i = 0; i < _rn; ++i)
        {
            printf ("%d ", _rm[i]);
        }
        printf ("\n");
    }
    
    bool _bfs ()
    {
        queue<int> que;

        for (int i = 0; i < _ln; ++i)
        {
            if (_lm[i] == -1)
            {
                _dist[i] = 0;
                que.push (i);
            }
            else
            {
                _dist[i] = -1;
            }
        }

        _sol = -1;
        bool visit = false;
        while (!que.empty ())
        {
            int x = que.front ();
            que.pop ();

            for (int i = 0; i < _graph[x].size (); ++i)
            {
                int y = _graph[x][i];

                if (_rm[y] == -1)
                {
                    _sol = _dist[x] + 1;
                    visit = true;
                }
                else if (_dist[_rm[y]] == -1)
                {
                    _dist[_rm[y]] = _dist[x] + 1;
                    que.push (_rm[y]);
                }
            }
        }

        return visit;
    }

    bool _dfs (int x)
    {
        if (x == -1)
        {
            return true;
        }

        for (int i = 0; i < _graph[x].size (); ++i)
        {
            int y = _graph[x][i];
            int tdist = (_rm[y] == -1) ? _sol : _dist[_rm[y]];

            if (tdist == _dist[x] + 1 && _dfs (_rm[y]))
            {
                _lm[x] = y;
                _rm[y] = x;
                return true;
            }
        }
        _dist[x] = -1;
        return false;
    }
    
    int _ln, _rn, _sol;
    vector<vector<int> > _graph;
    vector<int> _lm, _rm, _dist;
};

void fill (int x, int y, int z, int c)
{
    int dir[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    
    queue<pair<int, int> > que;
    que.push (make_pair (y, z));
    data[x][y][z] = c;

    while (!que.empty ())
    {
        pair<int, int> cur = que.front ();
        que.pop ();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next = make_pair (cur.first + dir[i][0], cur.second + dir[i][1]);
            if (0 <= next.first && next.first < n &&
                0 <= next.second && next.second < m &&
                data[x][next.first][next.second] == BLANK)
            {
                data[x][next.first][next.second] = c;
                que.push (next);
            }
        }
    }
}

int main ()
{
    int nCase;
    scanf ("%d", &nCase);

    for (int iCase = 0; iCase < nCase; ++iCase)
    {
        scanf ("%d %d %d", &n, &m, &l);

        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf ("%s", input_data);
                for (int k = 0; k < m; ++k)
                {
                    data[i][j][k] = (input_data[k] == '#') ? BLOCK : BLANK;
                }
            }
        }

        memset (conflict, 0, sizeof (conflict));
        int nn[2] = {0, 0};
        for (int i = 0; i < l; ++i)
        {
            cnt[i] = 0;
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < m; ++k)
                {
                    if (data[i][j][k] == BLANK)
                    {
                        fill (i, j, k, cnt[i]++);
                    }

                    if (0 < i && data[i - 1][j][k] != BLOCK && data[i][j][k] != BLOCK)
                    {
                        conflict[i][data[i - 1][j][k]][data[i][j][k]] = true;
                    }
                }
            }

            nn[i % 2] += cnt[i];
        }

        Graph graph (nn[0], nn[1]);
        int ln, rn;
        
        ln = 0; rn = 0;
        for (int i = 1; i < l; i += 2)
        {
            for (int j = 0; j < cnt[i - 1]; ++j)
            {
                for (int k = 0; k < cnt[i]; ++k)
                {
                    if (conflict[i][j][k])
                    {
                        graph.add (ln + j, rn + k);
                    }
                }
            }

            ln += cnt[i - 1];
            rn += cnt[i];
        }

        ln = cnt[0]; rn = 0;
        for (int i = 2; i < l; i += 2)
        {
            for (int j = 0; j < cnt[i - 1]; ++j)
            {
                for (int k = 0; k < cnt[i]; ++k)
                {
                    if (conflict[i][j][k])
                    {
                        graph.add (ln + k, rn + j);
                    }
                }
            }

            ln += cnt[i];
            rn += cnt[i - 1];
        }

        printf ("Case #%d: %d\n", iCase + 1, nn[0] + nn[1] - graph.match ());
    }

    return 0;
}
