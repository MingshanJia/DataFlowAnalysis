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
ll dp[N];
pii p[N];
int a[N], rem[N], cons[N];
set<string> pool;

map<string, int> cnt;
string s;
string f(string a){
    sort(all(a));
    return a;
}
int len, LIM;
ll go(int pos){
    //cout<<pos<<" ";
    int i;
    if (pos == len) return 1;
    string cur = "";
    ll &ans = dp[pos];
    if (ans != -1) return ans;
    ans = 0;
    int to = pos+LIM+1;
    to = min(to, len);
   	Fo(i, pos, to){
   		cur += s[i];
   		sort(all(cur));
   		if (cnt[cur]){
          //  cout<<cur<<" "<<cnt[cur]<<endl;
   			ans += (cnt[cur]*go(i+1))%mod;
   			if (ans >= mod) ans -= mod;
   		}
   	}
   return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int i, j, k, z, n, m;
    int u, v, t, q;
    ll ans;
	int mx = 0;
	cin>>t;
	string word;
	Fo(z, 1, t+1){
		cout<<"Case #"<<z<<": ";
		cin>>n>>q;

		cnt.clear(); pool.clear();
		LIM = 0;
		fo(i, n){
            cin>>word;
            LIM = max(LIM, (int)word.length());
            if(pool.find(word)==pool.end()){
                pool.insert(word);
                cnt[f(word)]++;
            }
		}
        while(q--){
            cin>>s;
            len = s.size();
            fo(i, len+1) dp[i] = -1;
            cout<<go(0)<<" ";
        }
        cout<<endl;
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
