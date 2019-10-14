#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define	sz(c) ll((c).size())
#define	all(c) begin(c),end(c)
#define	mp make_pair
#define mt make_tuple
#define	pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define	has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define	FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)

int main(){
	ios::sync_with_stdio(false);
    ll TC;
    cin >> TC;
    FOR(tc,1,TC+1){
        ll n;
        cin >> n;
        vector<double> p(2*n);
        FOR(i,0,2*n){
          cin >> p[i];
        }
        sort(all(p));
        double result = 1;
        FOR(i,0,n){
          result *= (1.0 - p[i]*p[2*n-i-1]);
        }
        cout << "Case #" << tc << ": ";
        cout << setprecision(7) << fixed << result << endl;
    }
}
