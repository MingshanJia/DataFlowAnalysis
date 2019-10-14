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
  static const int MAXN=2005;
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

int n;
vector<pair<int,pi> >g[1005],rg[1005];

pair<int,pi> es[2005];
int main(){
  int T;cin>>T;
  for(int setn=1;setn<=T;++setn){
    printf("Case #%d: ",setn);
    cin>>n;
    REP(i,n){
      g[i].clear();
      rg[i].clear();
    }
    int res=0;
    REP(i,n*2){
      int to,s,dur;
      cin>>to>>s>>dur;
      --to;
      int from=i/2;
      g[from].pb({to,{s,i}});
      rg[to].pb({from,{(s+dur)%24,i}});
      res+=dur;
    }
    int add=INF;
    REP(tz,2) REP(tz2,2){
      u.init();
      int tmp=0;
      int m=0;
      REP(i,n){
        int s[2]={g[i][0].sc.fr,g[i][1].sc.fr};
        int t[2]={rg[i][0].sc.fr,rg[i][1].sc.fr};
        auto doit=[&](int a,int b){
          if(a<=b) return b-a;
          return b-a+24;
        };
        if(i==0){
          tmp+=doit(t[tz2],s[tz]);
          tmp+=s[tz^1];
        }
        int cost[2]={0};
        REP(t2,2){
          REP(j,2){
            cost[t2]+=doit(t[j],s[j^t2]);
          }
        }
        if(i) tmp+=min(cost[0],cost[1]);
        int dif=max(cost[0],cost[1])-min(cost[0],cost[1]);
        int sm=(cost[0]<cost[1]?0:1);
        if(i==0) sm=(tz!=tz2?1:0);

        REP(j,2){
          u.unite(rg[i][j].sc.sc,g[i][j^sm].sc.sc);
        }
        if(i){
          es[m++]={dif,{rg[i][0].sc.sc,rg[i][1].sc.sc}};
        }
      }
      sort(es,es+m);
      REP(i,m){
        if(!u.same(es[i].sc.fr,es[i].sc.sc)){
          tmp+=es[i].fr;
          u.unite(es[i].sc.fr,es[i].sc.sc);
        }
      }
      bool fail=false;
      REP(i,n*2) if(!u.same(i,0)) fail=true;
      if(!fail) chmin(add,tmp);
    }
    res+=add;
    cout<<res<<endl;
  }
  return 0;
}



