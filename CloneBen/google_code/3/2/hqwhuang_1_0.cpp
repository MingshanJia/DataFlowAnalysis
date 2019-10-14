#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
//#include <unordered_set>
//#include <unordered_map>
//#include <sstream>
#include <set>
#include <map>
//#include <climits>
//#include <random>
//#include <deque>

using namespace std;

#define INF 2139062143
#define LINF 9187201950435737471
#define mem(a,v) memset(a,v,sizeof(a))
#define maxn 1005
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define eps 1e-7
#define ll long long
#define mp make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int,int> pp;
const ll md = 1e9+7;
const int MX = 400111;

ll fac[MX], facinv[MX],inv[MX];
inline ll C(ll x, ll y){
    return fac[x]*facinv[y]%md*facinv[x-y]%md;
}
void ini(){
    fac[0] = 1LL, facinv[0] = 1LL;
    inv[1] = 1LL;
    for(ll i=2;i<=400000;i++) inv[i]=(md-md/i)*inv[md%i]%md;
    for(ll i=1;i<=400000;i++) fac[i] = fac[i-1]*i%md;
    for(ll i=1;i<=400000;i++) facinv[i]=facinv[i-1]*inv[i]%md;
}
map<ll,ll> s;
int main() {
    ios::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(20);
//    freopen("/Users/huangqingwei/Documents/C++ workspace/codeforces/input.txt", "r",stdin);
    freopen("/Users/huangqingwei/Downloads/B-small-attempt1.in-2.txt", "r",stdin);
    freopen("/Users/huangqingwei/Documents/C++ workspace/codeforces/output.txt", "w",stdout);
    int T;
    cin>>T;
    ini();
    rep(t,1,T)
    {
        s.clear();
        int N,L;
        cin>>N;
        rep(i,1,N)
        {
            cin>>L;
            s[L]++;
        }
        ll ans = 0;
        for(auto i:s)
        {
            if(i.second>1)
            {
                for(auto j:s)
                    for(auto k:s)
                        if(i.first!=k.first && i.first!=j.first && k.first<j.first && j.first-k.first<2*i.first)
                        {
                            ans+=C(i.second,2)*j.second*k.second;
                        }
            }
            if(i.second>2)
            {
                for(auto j:s)
                    if(j.first!=i.first && j.first<3*i.first)
                    {
                        ans+=C(i.second,3)*j.second;
                    }
            }
        }

        cout<<"Case #"<<t<<": "<<ans<<'\n';
    }

    return 0;
}





















