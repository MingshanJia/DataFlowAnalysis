#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fio ios_base::sync_with_stdio(false)
#define pdl cout << "*" << endl
#define MOD 1000000007
#define INF 1000000000
#define INFLL 1000000000000000000ll
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define long uint64_t
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<int, pii> piii;
typedef priority_queue<piii, vector<piii>, greater<piii>> min_pq;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1){ cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{ const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma+1, args...); }

const int O = -100000;
const int N = 101;

int v[N][N];
bool b[N][N];
int d[N][N];

int main()
{
	fio;
	int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        memset(b, 0, sizeof b);
        memset(d, -1, sizeof d);
        int n, m, e;
        pii s, z;
        cin >> n >> m >> e >> s.ff >> s.ss >> z.ff >> z.ss;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> v[i][j];
        priority_queue<piii> q;
        q.push(mp(e, s));
        while(!q.empty())
        {
            int x = q.top().ss.ff;
            int y = q.top().ss.ss;
            int val = q.top().ff;
            q.pop();
            if(b[x][y])
                continue;
            b[x][y] = true;
            if(x > 1 and !b[x-1][y] and v[x-1][y] != O and d[x-1][y] < val + v[x-1][y])
            {
                d[x-1][y] = val + v[x-1][y];
                q.push(mp(d[x-1][y], mp(x-1, y)));
            }
            if(x < n and !b[x+1][y] and v[x+1][y] != O and d[x+1][y] < val + v[x+1][y])
            {
                d[x+1][y] = val + v[x+1][y];
                q.push(mp(d[x+1][y], mp(x+1, y)));
            }
            if(y > 1 and !b[x][y-1] and v[x][y-1] != O and d[x][y-1] < val + v[x][y-1])
            {
                d[x][y-1] = val + v[x][y-1];
                q.push(mp(d[x][y-1], mp(x, y-1)));
            }
            if(y < m and !b[x][y+1] and v[x][y+1] != O and d[x][y+1] < val + v[x][y+1])
            {
                d[x][y+1] = val + v[x][y+1];
                q.push(mp(d[x][y+1], mp(x, y+1)));
            }
        }
        cout << "Case #" << t << ": " << d[z.ff][z.ss] << endl;
    }
	return 0;
}