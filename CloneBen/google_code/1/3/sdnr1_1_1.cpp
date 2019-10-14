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
typedef priority_queue<pii, vector<pii>, greater<pii>> min_pq;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1){ cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{ const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma+1, args...); }

const int N = 400001;

void inp(int arr[], int n)
{
    int a, b, c, m;
    cin >> arr[1] >> arr[2] >> a >> b >> c >> m;
    for(int i=3; i<=n; i++)
        arr[i] = (a * 1ll * arr[i-1] + b * 1ll * arr[i-2] + c) % m;
}

int l[N], r[N], x[N], y[N], z[N], s[N], in[N << 1], cp[N << 1];
long cs[N << 1];

int solve(int v, int n)
{
    int i = 1, j = n;
    while(i != j)
    {
        int mid = i+j+1 >> 1;
        //trace(i, j, mid, cs[mid]);
        if(cs[mid] >= v)
            j = mid - 1;
        else
            i = mid;
    }
    //trace(i);
    v -= cs[i];
    return cp[i] + 1 - (v + in[i] - 1) / in[i];
}

int main()
{
	fio;
	int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        vector<pii> Q;
        int n, q;
        cin >> n >> q;
        inp(x, n);
        inp(y, n);
        inp(z, q);
        long tot = 0;
        for(int i=1; i<=n; i++)
        {
            l[i] = min(x[i], y[i]) + 1;
            r[i] = max(x[i], y[i]) + 1;
            tot += r[i] - l[i] + 1;
        }
        map<int, int> m;
        for(int i=1; i<=n; i++)
        {
            m[l[i] - 1]--;
            m[r[i]]++;
        }
        int sz = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++)
        {
            cp[++sz] = it->ff;
            in[sz] = in[sz-1] + it->ss;
        }
        for(int i=1; i<=sz; i++)
        {
            cs[i] = cs[i-1] + (cp[i-1] - cp[i]) * 1ll * in[i-1];
            //trace(i, cp[i], cs[i], in[i]);
        }
        long ans = 0;
        for(int i=1; i<=q; i++)
        {
            int v = z[i] + 1;
            if(v > tot)
                continue;
            //int x = solve(v, sz);
            //trace(v, x);
            ans += solve(v, sz) * 1ll * i;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
	return 0;
}