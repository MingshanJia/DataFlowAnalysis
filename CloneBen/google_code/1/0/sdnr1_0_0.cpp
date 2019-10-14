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
#define long int64_t
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

const int N = 7001;

int a[N];

int main()
{
	fio;
	int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        map<int, int> m;
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a+n);
        long ans = 0;
        for(int i=m[1]+m[0]; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(a[i] * 1ll * a[j] < INF)
                    ans += m[a[i] * a[j]];
                else
                    break;
            }
        }
        ans += (m[0] * 1ll * (m[0] - 1) * 1ll * (m[0] - 2)) / 6;
        ans += (m[1] * 1ll * (m[1] - 1) * 1ll * (m[1] - 2)) / 6;
        ans += ((m[0] * 1ll * (m[0] - 1)) / 2) * 1ll * (n - m[0]);
        for(auto it : m)
        {
            if(it.ff < 2)
                continue;
            ans += ((it.ss * 1ll * (it.ss - 1)) / 2) * 1ll * m[1];
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
	return 0;
}