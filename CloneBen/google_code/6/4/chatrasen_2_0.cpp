#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


const int N = 2e5 + 10;
int fac[N + 1];
int inv[N + 1];
int ifac[N + 1];
int p2[N + 1];

inline int C(int n, int k) {
    if (k > n)return 0;
    int ans = (fac[n] * 1LL * ifac[k]) % inf;
    return (ans * 1LL * ifac[n - k]) % inf;
}

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    fac[0] = 1; ifac[0] = 1; inv[1] = 1; p2[0] = 1;
    FOR(i, 1, N)fac[i] = (fac[i - 1] * 1LL * i) % inf, p2[i] = add(p2[i - 1], p2[i - 1]);
    FOR(i, 1, N)fac[i] = (fac[i - 1] * 1LL * i) % inf;
    FOR(i, 2, N)inv[i] = inf - ((inf / i) * 1LL * inv[inf % i]) % inf;
    FOR(i, 1, N)ifac[i] = (ifac[i - 1] * 1LL * inv[i]) % inf;
    

    int t; cin >> t; FOR (tc, 1, t) {
        int n, m; cin >> n >> m;
        int ans = 0;
        FOR (i, 0, m) {
            if (i & 1) {
                ans -= mul(fac[2*n-i], mul(C(m, i), p2[i]));
                if (ans < 0) ans += inf;
            } else {
                ans = add(ans, mul(fac[2*n-i], mul(C(m, i), p2[i])));
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    
    return 0;
}