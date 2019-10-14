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

//const int INF=5e8;

int len;

int getlen(int n){
  int res=0;
  while(n){
    n/=10;
    ++res;
  }
  return res;
}
int pw10[10];
int nxt(int a){
  int res=0;
  int cnt[10]={0};
  int tmp=a;
  REP(i,len){
    ++cnt[tmp%10];
    tmp/=10;
  }
  for(int i=1;i<=len;++i){
    res+=pw10[len-i]*cnt[i];
  }
  return res;
}

set<string> done;
int solve(string s){
  int tot=0;
  REP(i,len) tot+=s[i]-'0';
  if(tot>len) return 1;
  if(done.count(s)) return 0;
  done.insert(s);
  int res=1;

  string perm;
  REP(i,len){
    REP(t,s[i]-'0') perm+='1'+i;
  }
  REP(t,len-tot) perm+='0';
  sort(ALL(perm));
  do{
    res+=solve(perm);
  }while(next_permutation(ALL(perm)));
  return res;
}
int main(){
  pw10[0]=1;
  REP(i,9) pw10[i+1]=pw10[i]*10;

  int T;cin>>T;
  for(int setn=1;setn<=T;++setn){
    done.clear();
    printf("Case #%d: ",setn);
    string s;
    cin>>s;
    len=s.size();

    int res=solve(s);
    cout<<res<<endl;
  }
  return 0;
}



