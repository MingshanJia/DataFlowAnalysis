#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

const int INF=5e8;

struct uf{
  static const int MAXN=1005;
  int par[MAXN];
  int size[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN) size[i]=1;
  }
  int root(int a){
    if(par[a]==-1) return a;
    return par[a]=root(par[a]);
  }
  void unite(int a,int b){
    a=root(a);b=root(b);
    if(a==b) return;
    if(size[a]<size[b]) swap(a,b);

    par[b]=a;
    size[a]+=size[b];
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};

uf u;
int n,m;
vector<pair<pi,pi> > g[1005];//((to,flow),(rev,id))
pi es[2005];

bool bridge(){
  int comp=0;
  u.init();
  REP(i,m) u.unite(es[i].fr,es[i].sc);
  REP(i,n) if(u.root(i)==i) ++comp;

  REP(i,m){
    u.init();
    REP(j,m) if(i!=j) u.unite(es[j].fr,es[j].sc);
    int comp2=0;
    REP(j,n) if(u.root(j)==j) ++comp2;
    if(comp2!=comp) return true;
  }
  return false;
}

map<int,int> ever;
int value;

bool vis[1005];
bool dfs(int v,int id,int p,int R){
  if(R==v && p!=-1){
    value=INF;
    for(int i=1;;++i){
      for(int sign=-1;sign<=1;sign+=2){
        int va=sign*i;
        if(ever[va]==0){
          value=-va;
          goto exi;
        }
      }
    }
    exi:;
    return true;
  }
  vis[v]=1;

  for(auto& e:g[v]){
    if(p==-1){
      if(e.sc.sc!=id) continue;
    }
    if(p==e.sc.sc) continue;
    if(vis[e.fr.fr] && e.fr.fr!=R) continue;
    ever[e.fr.sc]++;
    if(dfs(e.fr.fr,id,e.sc.sc,R)){
      e.fr.sc+=value;
      g[e.fr.fr][e.sc.fr].fr.sc-=value;
      return true;
    }
    ever[e.fr.sc]--;
  }
  return false;
}

int main(){
  int T;cin>>T;
  for(int setn=1;setn<=T;++setn){
    printf("Case #%d:",setn);
    cin>>n>>m;
    REP(i,n) g[i].clear();
    REP(i,m){
      int a,b;cin>>a>>b;--a;--b;
      es[i]={a,b};
      g[a].pb({{b,0},{g[b].size(),i}});
      g[b].pb({{a,0},{g[a].size()-1,i}});
    }
    if(bridge()){
      puts(" IMPOSSIBLE");
      continue;
    }
    REP(i,n) for(auto e:g[i]) if(e.fr.sc==0){
      ever.clear();
      CLR(vis);
      bool tmp=dfs(i,e.sc.sc,-1,i);
      assert(tmp);
    }
    vector<int> res;
    REP(i,m){
      for(auto e:g[es[i].fr]) if(e.sc.sc==i){
        res.pb(e.fr.sc);
      }
    }
    for(auto e:res) printf(" %d",e);
    puts("");
  }
  return 0;
}



