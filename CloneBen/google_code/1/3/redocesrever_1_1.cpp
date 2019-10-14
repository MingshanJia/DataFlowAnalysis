#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef long long int ll;
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
ll t,n,q;
ll x[500005],y[500005],z[500005];
ll a1,b1,c1,m1;
ll a2,b2,c2,m2;
ll a3,b3,c3,m3;
pll qr[500005];
pll lr[500005];
pll pts[900005];
int main()
{

    freopen("BL.in", "r", stdin);
    freopen("BL.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);

    cin>>t;
    rep(tt,1,t) {
        cin>>n>>q;
        cin>>x[1]>>x[2]>>a1>>b1>>c1>>m1;
        cin>>y[1]>>y[2]>>a2>>b2>>c2>>m2;
        cin>>z[1]>>z[2]>>a3>>b3>>c3>>m3;
        ll st = 0;
        rep(i,1,n) {
            if(i > 2) {
                x[i] = ((a1*x[i-1])%m1 + (b1*x[i-2])%m1 + c1) %m1;
                y[i] = ((a2*y[i-1])%m2 + (b2*y[i-2])%m2 + c2) %m2;
            }
            lr[i].F = min(x[i],y[i]) + 1;
            lr[i].S = max(x[i],y[i]) + 1;
            pts[++st] = mp(lr[i].F,0);
            pts[++st] = mp(lr[i].S,1);
        }
        rep(i,1,q) {
            if(i > 2) {
                z[i] = ((a3*z[i-1])%m3 + (b3*z[i-2])%m3 + c3) %m3;
            }
            qr[i] = mp(z[i] + 1,i);
        }

        assert(st == 2*n);
        n *= 2;
        sort(pts+1,pts+n+1);
        sort(qr+1,qr+q+1);

        st = n;
        ll op = 0,len = 0,csum = 0,cpos = pts[n].F;
        while(st >= 1 && pts[st].S == 1 && pts[st].F == cpos) {
            op++;
            st--;
        }
        assert(st > 0);
        len = cpos - pts[st].F + 1;
        if(pts[st].S == 1) len--;

        ll ans = 0;
        rep(i,1,q) {
            ll ind = qr[i].S,k = qr[i].F;
            assert(csum < k);
            while(st >= 1 && csum + op*len < k) {
                csum += op*len;
                if(pts[st].S == 0) {
                    cpos = pts[st].F;
                    while(st >= 1 && pts[st].F == cpos && !pts[st].S) {
                        op--;
                        st--;
                    }
                    if(st == 0) {
                        op = len = 0;
                        break;
                    }
                    len = cpos - pts[st].F;
                    cpos--;
                    if(pts[st].S == 1) len--;
                } else {
                    cpos = pts[st].F;
                    while(st >= 1 && pts[st].F == cpos && pts[st].S == 1) {
                        op++;
                        st--;
                    }
                    assert(st > 0);
                    len = cpos - pts[st].F + 1;
                    if(pts[st].S == 1) len--;
                }
            }
            if(csum  + op*len < k) break;
            assert(csum < k);
            ll rem = k - csum;

            assert(len > 0 && op > 0);
            ll divi = (rem + op - 1)/op;
            assert(divi <= len);

            ll val = cpos - divi + 1;
            ans += val * ind;
        }
        cout<<"Case #"<<tt<<": "<<ans<<'\n';
        cerr<<"DONE "<<tt<<endl;
    }

}

