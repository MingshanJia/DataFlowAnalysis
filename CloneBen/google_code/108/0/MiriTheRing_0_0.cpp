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
    ll f, s;
    cin >> f >> s;
    vl a(f), b(f);
    FOR(i,0,f){
      cin >> a[i] >> b[i];
      a[i]--;
      b[i]--;
    }
    ll res = 0;
    FOR(i,0,s){
      ll num = 0;
      vector<bool> done(s,false);
      FOR(j,0,f){
        if(a[j] == i && !done[b[j]]){
          done[b[j]] = true;
          num++;
        }
        else if(b[j] == i && !done[a[j]]){
          done[a[j]] = true;
          num++;
        }
      }
      res = max(num, res);
    }
    cout << "Case #" << tc << ": " << res << endl;
  }
}
