/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include "ttmath/ttmath.h"
#include <bits/stdc++.h>

using namespace ttmath;

#define fore(x,n) for(auto x : n)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((i64)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<27)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<i64> vi;
typedef vector<st> vs;
typedef map<i64,i64> mii;
typedef map<i64,i64> mii;
typedef map<st,i64> msi;
typedef set<i64> si;
typedef set<st> ss;
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;
typedef pair<i64,i64> pll;
typedef vector<pll> vpll;
typedef Int<10> BigInt;


template <class T> void dijkstra(i64 s,i64 t,i64 n,T *d,vpll edge[],T INF=1<<29){
    //source, target, numberof nodes, distance array,weighted graph,value of infinite
    //0 based
    rep(i,n) d[i]=INF;
    d[s]=0;
    priority_queue< pair<T,i64> > pq;
    pq.push( pair<T,i64>(0,s) );
    while(!pq.empty()){
        i64 u=pq.top().yy;
        if(u==t) return ;
        pq.pop();
        rep(i,sz(edge[u])){
            i64 v=edge[u][i].xx;
            T w=edge[u][i].yy;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push( pair<T,i64>(-d[v],v) );
            }
        }
    }
}


i64 test, kas=0;

vector< i64 > w;
vector< vi > id, id_2;

vpll edge[1000000];

i64 d[1000000];

int main() {
    read("in.txt");
    rite("BLARGE____1.txt");
    ios_base::sync_with_stdio(0);
    cin>>test;
    while( test-- ){
        cout<<"Case #"<<++kas<<": "<<endl;
        w.clr;
        //Time.clr;
        id.clr;
        id_2.clr;
        i64 N;
        i64 kkkk = 0;
        cin >> N;
        //cout << "N=" << N << endl;
        rep( i , N ) {
            i64 len, W;
            cin >> len >> W;
            w.pb(W);
            vi ttt, iii;
            rep( i , len-1 ) {
                i64 temp;
                cin >> temp;
                ttt.pb( temp ); /// time
                edge[kkkk].clr; /// clearing the vector b4 assigning
                iii.pb( kkkk++ ); /// id
            }
            edge[kkkk].clr;
            iii.pb(kkkk++);

            vi bidhan;
            for( auto x : iii ) {
                edge[kkkk].clr;
                bidhan.pb(kkkk++);
            }

            id_2.pb( bidhan );

            rep( i , len-1 ) {
                i64 u = iii[i]; int tu = bidhan[i];
                i64 v = iii[i+1]; int tv = bidhan[i+1];
                i64 w = ttt[i];
                edge[u].pb( {v,w} );
                edge[v].pb( {u,w} );

                edge[u].pb( {tv,w} );
                edge[v].pb( {tu,w} );
            }
            //Time.pb( ttt );
            id.pb( iii );
        }

        i64 M;
        cin >> M;

        rep( stp , M ) {
            i64 m1, s1;
            i64 m2, s2;
            cin >> m1 >> s1;
            cin >> m2 >> s2;

            m1--, s1--;
            m2--, s2--;

            i64 u = id[m1][s1]; int tu = id_2[m1][s1];
            i64 v = id[m2][s2]; int tv = id_2[m2][s2];
            i64 ww;
            cin >> ww;

            edge[u].pb({v,ww+w[m2]});
            edge[v].pb({u,ww+w[m1]});

            edge[tu].pb({v,ww+w[m2]});
            edge[tv].pb({u,ww+w[m1]});

            edge[u].pb( {tv,ww} );
            edge[v].pb( {tu,ww} );

            edge[tu].pb( {tv,ww} );
            edge[tv].pb( {tu,ww} );
        }

        i64 Q;

        cin >> Q;

        while( Q-- ) {
            i64 x1, y1;
            i64 x2, y2;

            cin >> x1 >> y1;
            cin >> x2 >> y2;

            x1--, y1--;
            x2--, y2--;

            i64 u = id[x1][y1];
            i64 v = id_2[x2][y2];

            dijkstra( u , v , kkkk , d , edge , 1ll << 55 );

            i64 ans = d[v] + w[x1];

            u = id_2[x1][y1];

            dijkstra( u , v , kkkk , d , edge , 1ll << 55 );

            ans = min( ans , d[v] );

            if( ans >= (1ll<<55) ) ans = -1;

            cout << ans << endl;
        }
    }
    return 0;
}
