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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
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

//const int INF=5e8;

int n;
int m;
int R,P,S;
typedef vector<int> vi;
vector<int> rec(int n,int top){
  if(n==0){
    vi res;
    res.pb(top);
    return res;
  }
  vi a=rec(n-1,top),b=rec(n-1,(top+1)%3);
  if(a>b) a.swap(b);
  for(auto e:b) a.pb(e);
  return a;
}


int main(){
  int T;cin>>T;
  for(int setn=1;setn<=T;++setn){
    cin>>n>>R>>P>>S;
    m=(1<<n);

    int ar[3]={P,R,S};
    vi res;
    REP(i,3){
      vi tmp=rec(n,i);
      int cnt[3]={0};
      for(auto e:tmp) cnt[e]++;
      if(cnt[0]==ar[0] && cnt[1]==ar[1] && cnt[2]==ar[2]){
        if(res.empty()) res=tmp;
        else chmin(res,tmp);
      }
    }
    printf("Case #%d: ",setn);
    char conv[4]="PRS";
    if(res.empty()) puts("IMPOSSIBLE");
    else{
      for(auto e:res) putchar(conv[e]);
      puts("");
    }
  }
  return 0;
}



