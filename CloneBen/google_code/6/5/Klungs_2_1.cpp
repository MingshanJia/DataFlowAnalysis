#include<bits/stdc++.h>


#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long
#define ALL(a) a.begin(),a.end()
#define vi vector<int>

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

clock_t first_attempt = clock();
inline void cek_time(){
	clock_t cur = clock()- first_attempt;
	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
}
inline void OPEN (string s) {
	freopen ((s + ".in").c_str (), "r", stdin);
	freopen ((s + ".out").c_str (), "w", stdout);
}

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> bbst;
//find_by_order(idx) : i-th index 
//order_of_key(val)  : val has which index

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

//end of template

const int maxn = 3e5 + 5;

ll fak[maxn], two[maxn];
ll pw(ll a, ll b) {
	if (b == 0) return 1;
	ll x = pw(a * a % INF, b >> 1);
	return b & 1 ? x * a % INF : x;
}
ll inv(ll a) {
	return pw(a, INF - 2);
}
ll C(ll n, ll r) {
	return fak[n] * inv(fak[r] * fak[n - r] % INF) % INF;
}
int main() {
	fak[0] = two[0] = 1;
	rep(k, 1, maxn) {
		fak[k] = fak[k-1] * k % INF;
		two[k] = two[k-1] * 2 % INF;
	}
		
	int t;
	cin >> t;
	rep(tc, 1, t + 1) {
		int n, m;
		cin >> n >> m;
		
		ll ans = 0;
		rep(k, 0, m + 1) {
			int tnd = (k % 2 ? -1 : 1);
			ans += tnd * two[k] * fak[2 * (n - k) + k] % INF * C(m, k) ;
			ans %= INF;
		}
		
		if (ans < 0) ans += INF;
		
		printf("Case #%d: %lld\n", tc, ans);
	}
}