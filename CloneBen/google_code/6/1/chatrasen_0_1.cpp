#include <bits/stdc++.h>
using namespace std;
#define cerr cout
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
struct bit_trie{
    int len;
    struct node{
        int N[2];
        bool en;
        node(){N[0]=N[1]=0;en = 0;}
    };
    vector<node> T;
    bit_trie(int len):len(len),T(2){};
    void insert(int no, string& s, int i){
        if (i == sz(s)) {
            T[no].en = 1;
            return;
        }
        if (!T[no].N[s[i] == 'R']) {
            T.push_back(node()),T[no].N[s[i] == 'R']=T.size()-1;    
        }
        insert(T[no].N[s[i] == 'R'], s, i + 1);
    }
    ll query(int no, int n, int len){
        if (T[no].en) return 0;
        ll ans = 0;
        FOR (i, 0, 1) {
            if (T[no].N[i]) {
                ans += query(T[no].N[i], n, len + 1);
            } else {
                ans += (1LL << (n - len - 1));
            }
        }
        return ans;
    }

};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; FOR (tc, 1, t) {
        int n, p; cin >> n >> p;
        vector<string> a(p);
        bit_trie T(n - 1);
        FOR (it, 0, p - 1) {
            cin >> a[it];
            T.insert(1, a[it], 0);
        }

        cout << "Case #" << tc << ": " << T.query(1, n, 0) << "\n";
    }
    
    return 0;
}