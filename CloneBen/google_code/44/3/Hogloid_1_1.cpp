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

double prob[205],sel[205];
int n,k;

double dp[205][205];
double calc(double p[205],int n){
  CLR(dp);
  dp[0][0]=1;
  REP(i,n){
    REP(j,i+1){
      dp[i+1][j]+=dp[i][j]*(1-p[i]);
      dp[i+1][j+1]+=dp[i][j]*p[i];
    }
  }
  return dp[n][n/2];
}
int main(){
  int T;cin>>T;
  for(int setn=1;setn<=T;++setn){
    printf("Case #%d: ",setn);
    cin>>n>>k;
    REP(i,n) cin>>prob[i];
    sort(prob,prob+n);
    double res=0;
    REP(i,k+1){
      int m=0;
      REP(j,i) sel[m++]=prob[j];
      REP(j,k-i) sel[m++]=prob[n-1-j];

      double tmp=calc(sel,k);
      chmax(res,tmp);
    }
    printf("%.10f\n",res);
  }
  return 0;
}



