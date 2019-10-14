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

//end of template

ll C3(ll n) {
    return n * (n - 1) * (n - 2) / 6ll;
}

ll C2(ll n) {
    return n * (n - 1) / 2ll;
}

const int maxn = 2e5 + 5;

int main() {
    
    int t, n, tc = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<ll> cnt(maxn, 0), ori;
        ll rem = 0;
        rep(k, 0, n) {
            int a;
            cin >> a;
            
            cnt[a]++;
            if (a > 1) {
                rem++;
                ori.pb(a);
            }
        }
        
        ll ans = 0;
        sort(ALL(ori));
        // x x x
        rep(k, 0, ori.size()) rep(i, k + 1, ori.size()) {
            ll cur = ori[k] * ori[i];
            if (cur >= maxn) cur = maxn - 1;
            ans += cnt[cur];
        }
        
        // 1 x x
        rep(k, 2, maxn) 
            ans += cnt[1] * C2(cnt[k]);
        
        // 1 1 1
        ans += C3(cnt[1]);
        
        // 0 0 x
        ans += C2(cnt[0]) * (cnt[1] + rem);
        
        // 0 0 0
        ans += C3(cnt[0]);
        
        printf("Case #%d: %lld\n", ++tc, ans);
        // cout << ans << endl;
    }
}