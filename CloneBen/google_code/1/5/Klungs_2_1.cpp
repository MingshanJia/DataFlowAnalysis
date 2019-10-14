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

const int maxn = 105;
int t;

int n, m, e, sr, sc, tr, tc;
int v[maxn][maxn];

int ch(pii a) {return a.fi * 103 + a.se;}
int par[maxn*maxn], pval[maxn*maxn];
int rt(int a) {
    if (par[a] == a) return a;
    return par[a]= rt(par[a]);
}

int rt(pii a) {
    return rt(ch(a));
}

void join(int a, int  b) {
    a = rt(a), b = rt(b);
    if (a != b) {
        pval[b] += pval[a];
        par[a] = b;
    }
}
void join(pii a, pii b) {
    return join(ch(a), ch(b));
}

bool connect(int a, int b ) {
    return rt(a) == rt(b);
}

bool connect(pii a, pii b) {
    return connect(ch(a), ch(b));
}

int rval(int a) {
    return pval[rt(a)];
}
int rval(pii a) {
    return rval(ch(a));
}

int flag[1 << 15];
int id[maxn][maxn];
int main() {
    cin >> t;
    rep(TC, 1, t+1) {
        cin >> n >> m >> e >> sr >> sc >> tr >> tc;
        
        vector<pii> trap;
        
        rep(k, 0, maxn) rep(i, 0, maxn) v[k][i] = -INF;
        
        memset(id, -1, sizeof id);
        memset(pval, 0, sizeof pval);
        rep(k, 1, n + 1) rep(i, 1, m + 1) {
            scanf("%d", &v[k][i]);
            if (v[k][i] == -100000) v[k][i] = -INF;
            
            if (v[k][i] >= 0)
                pval[ch({k, i})] = v[k][i];
                
            if (-INF < v[k][i] && v[k][i] < 0) {
                id[k][i] = trap.size();
                trap.pb({k, i});
            }
        }
        
        
        iota(par, par + maxn * maxn, 0);
        rep(k, 1, n + 1) rep(i, 1, m + 1) if (v[k][i] >= 0) {
            rep(j, 0, 4) {
                int kk = k + dirx[j];
                int ii = i + diry[j];
                if (v[kk][ii] >= 0) 
                    join({kk, ii}, {k, i});
            }
        }
        // printf("connect %d\n", connect({sr, sc}, {tr, tc}));
        
        memset(flag, 0, sizeof flag);
        queue<int> q;
        int N = trap.size();
        
        q.push(0);
        
        int ans = -1;
        while(q.size()) {
            int a = q.front();
            q.pop();
            
            if (flag[a]) continue;
            flag[a] = 1;
            
            set<int> scc;
            // compute E
            int E = e;
            scc.insert(rt({sr, sc}));
            rep(i, 0, N) if ((1<<i) & a) {
                int x = trap[i].fi;
                int y = trap[i].se;
                
                E += v[x][y];
                rep(j, 0, 4) {
                    int xx = x + dirx[j];
                    int yy = y + diry[j];
                    
                    if (v[xx][yy] >= 0)
                        scc.insert(rt({xx, yy}));
                }
            } 
            
            for (auto x : scc) {
                E += rval(x);
            }
            
            // check available trap
            // printf("cek root %d, E = %d\n", rt({sr, sc}), E);
            rep(i, 0, N) if (((1<<i) & a) == 0) {
                int x = trap[i].fi;
                int y = trap[i].se;
                
                if (v[x][y] + E < 0) continue;
                int can = 0;
                rep(j, 0, 4) {
                    int xx = x + dirx[j];
                    int yy = y + diry[j];
                    
                    if (v[xx][yy] < 0) {
                        int id_trap = id[xx][yy];
                        if (id_trap != -1) {
                            if ((1<<id_trap) & a)
                                can = 1;
                        }
                    }
                    else {
                        // printf("cek %d %d\n", i, rt({xx, yy}));
                        if (scc.count(rt({xx, yy})))
                            can = 1;
                    }
                }
                
                if (can) 
                    q.push(a ^ (1<<i));
            }
            
            // printf("mask %d\n", a);
            
            // check can escape
            if (scc.count(rt({tr, tc})))
                ans = max(ans, E);
        }
        
        printf("Case #%d: %d\n", TC, ans);
    }
}