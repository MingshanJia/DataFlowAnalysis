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
ll t,n,m,e,sx,sy,tx,ty;
ll cost[105][105];
ll dis[105][105];
bool  vis[105][105];
typedef pair<ll,pll>  node;
priority_queue<node,vector<node> , greater<node > > pq;
const ll nr = 100000LL;
const ll inf = 1e16;
int main()
{

    freopen("CS0.in", "r", stdin);
    freopen("CS0.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);

    cin>>t;
    rep(tt,1,t) {
        cin>>n>>m>>e>>sx>>sy>>tx>>ty;
        rep(i,1,n ) rep(j,1,m)  {
            cin>>cost[i][j];
            assert(cost[i][j] <= 0);
            cost[i][j] = abs(cost[i][j]);//small
            vis[i][j] = 0;
            dis[i][j] = inf;
        }
        pq.push({cost[sx][sy],{sx,sy}});
        while(!pq.empty()) {
            auto xp = pq.top();pq.pop();
            ll x = xp.S.F,y = xp.S.S,d = xp.F;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            dis[x][y] = d;

            rep(dx,-1,1) rep(dy,-1,1) {
                if(dx * dy) continue;
                if(x + dx > n || x + dx <= 0) continue;
                if(y + dy > m || y + dy <= 0) continue;
                if(vis[x+dx][y+dy]) continue;
                if(cost[x+dx][y+dy] == nr) continue;
                pq.push({d + cost[x+dx][y+dy],{x+dx,y+dy}});
            }
        }
        ll ans;
        if(dis[tx][ty] >= inf) ans = -1;
        else if(dis[tx][ty]  > e) ans = -1;
        else ans = e - dis[tx][ty];

        cout<<"Case #"<<tt<<": "<<ans<<'\n';
        cerr<<"DONE "<<tt<<endl;
    }

}

