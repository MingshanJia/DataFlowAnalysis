#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef long long  int ll;
typedef  long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
vll pos[200005];
ll n,a[7008],t;

ll get(ll v,ll val) {
    ll ps = upper_bound(pos[v].begin(),pos[v].end(),val) - pos[v].begin();
    return pos[v].size() - ps;
}
int main()
{

    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);

    cin>>t;
    rep(tt,1,t) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,0,200000) pos[i].clear();
        rep(i,1,n) pos[a[i]].pb(i);
        ll ans = 0;
        rep(px,1,n-2 ) rep(py,px + 1,n-1) {
            if(a[px] == 0 && a[py] == 0)  ans += n - py;
            else if(a[px] == 0 || a[py] == 0) ans += get(0,py);
            else {
                ll x = a[px],y = a[py];
                if(x*y <= 200000) {
                    ans += get(x*y,py);
                }
                if(x%y == 0 && (x/y) != (x*y)) ans += get(x/y,py);
                else if(y%x == 0 && (y/x) != (x*y)) ans += get(y/x,py);
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<'\n';
        cerr<<"CAR "<<tt<<endl;
    }

}

