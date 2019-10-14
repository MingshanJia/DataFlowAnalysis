#include<bits/stdc++.h>


#define pii pair<ll,ll>
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

//end of template

const int maxn = 4e5 + 5;
int n, q;

ll X[maxn], Y[maxn], Z[maxn], A[maxn], B[maxn], C[maxn], M[maxn];

ll L[maxn], R[maxn], K[maxn];

ll ceil(ll a, ll b) {
    if (b == 0) return 0;
    return a / b + (a % b ? 1 : 0);
}
int main() {
    int t;
    cin >> t;
    rep(tc, 1, t + 1) {
        cin >> n >> q;
        
        // X1 X2 A1 B1 C1 M1
        // Y1 Y2 A2 B2 C2 M2
        // Z1 Z2 A3 B3 C3 M3
        
        // Xi = (A1 × Xi - 1 + B1 × Xi - 2 + C1) modulo M1
        // Yi = (A2 × Yi - 1 + B2 × Yi - 2 + C2) modulo M2
        // Zi = (A3 × Zi - 1 + B3 × Zi - 2 + C3) modulo M3

        // Li = min(Xi, Yi) + 1, for i = 1 to N.
        // Ri = max(Xi, Yi) + 1, for i = 1 to N.
        // Ki = Zi + 1, for i = 1 to Q.
        
        cin >> X[1] >> X[2] >> A[1] >> B[1] >> C[1] >> M[1];
        cin >> Y[1] >> Y[2] >> A[2] >> B[2] >> C[2] >> M[2];
        cin >> Z[1] >> Z[2] >> A[3] >> B[3] >> C[3] >> M[3];
        
        rep(i, 3, maxn) {
            X[i] = (A[1] * X[i - 1] + B[1] * X[i - 2] + C[1]) % M[1];
            Y[i] = (A[2] * Y[i - 1] + B[2] * Y[i - 2] + C[2]) % M[2];
            Z[i] = (A[3] * Z[i - 1] + B[3] * Z[i - 2] + C[3]) % M[3];
        }
        
        rep(i, 1, n + 1) {
            L[i] = min (X[i], Y[i]) + 1;
            R[i] = max (X[i], Y[i]) + 1;
        }
        
        rep(i, 1, q + 1) {
            K[i] = Z[i] + 1;
        }
        
        ///
        map<int, ll> swp;
        rep(i, 1, n + 1) {
            swp[L[i]]++;
            swp[R[i] + 1]--;
        }
        
        // id, val, off
        #define piii pair<ll, pii> 
        set<piii> arr;
        
        int lst = swp.begin()->fi;
        ll tot = 0, off = 0;
        for (auto x : swp) {
            tot += (ll) (x.fi - lst) * off;
            ll id = tot, val = x.fi;
            off += x.se;
            
            lst = x.fi;
            arr.insert({id, {val, off}});
            // printf("id val off : %lld %lld %lld\n", id, val, off);
        }
        
        rep(i, 1, q + 1) {
            K[i] = tot - K[i] + 1;
            if (K[i] <= 0) K[i] = tot + 1;
        }
        ll ans_h = 0;
        
        
        // debug cuy
        // multiset<ll> bf;
        // rep(i, 1, n + 1) {
        //     printf("%lld %lld\n", X[i], Y[i]);
        //     rep(x, L[i], R[i] + 1) 
        //         bf.insert(x);
        // }
        // printf("arr : ");
        // for (auto x : bf) {
        //     printf("%lld ", x);
        // }
        // line;
        //
        rep(i, 1, q + 1) {
            ll k = K[i];
            auto it = arr.lower_bound({k, {-1, -1}});
            auto r_it = it;
            it--;
            auto l_it = it;
            
            ll ans = 0;
            if (r_it == arr.end()) {
                ans = 0;
            }
            else {
                piii l = *l_it;
                ll idL = l.fi;
                ll off = l.se.se;
                ll val = l.se.fi;
                ans = ceil(k - idL, off) + val - 1;
            }
            
            // printf("query K = %lld -> %lld\n", K[i], ans);
            ans_h += ans * i;
        }
        
        printf("Case #%d: %lld\n", tc, ans_h);
    }
}