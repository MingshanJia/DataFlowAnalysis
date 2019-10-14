#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 5e5;
vi g[N];

int a[N], b[N], p[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int i, j, k, z, n, m;
    int u, v, t, l;
    ll ans;
	int mx = 0;
	cin>>t;
	Fo(z, 1, t+1){
		cout<<"Case #"<<z<<": ";
        cin>>n>>m>>l;
        fo(i, n){
            cin>>a[i]>>b[i]>>p[i];
        }
        int lim = 1<<n;
        int mask;
        ans = mod;
        fo(mask, lim){
            ll cur = 0;
            ll L=0, R=0;
            fo(i, n){
                int pos = 1<<i;
                if( (mask&pos) != 0 ){
                    cur += p[i];
                    L += a[i];
                    R += b[i];
                }
            }
            if (L<=l and l<=R and cur<=m) ans = min(ans, cur);
            //cout<<mask<<" "<<cur<<" "<<L<<" "<<R<<endl;
        }
        if(ans==mod) cout<<"IMPOSSIBLE\n";
        else cout<<ans<<endl;

	}
	return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
