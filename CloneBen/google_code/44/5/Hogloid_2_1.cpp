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
int h,w;
int con[205];
int buf[105][105];


int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void conv(int p,int& y,int& x,int& d){
  if(p<w){
    y=0;x=p;d=3;
  }else if((p-=w)<h){
    x=w-1;y=p;d=0;
  }else if((p-=h)<w){
    x=w-1-p;y=h-1;d=1;
  }else{
    p-=w;
    x=0;y=h-1-p;d=2;
  }
}

bool dfs(int y,int x,int d,int gy,int gx,int gd){
  dump(y);dump(x);dump(d);
  if(y<0 || x<0 || y>=h || x>=w){
    if(mp(x,y)==mp(gx,gy)) return true;
    return false;
  }
  if(buf[y][x]){
    int d2=(d^buf[y][x]);
    int d3=(d2+2)%4;
    return dfs(y+dy[d2],x+dx[d2],d3,gy,gx,gd);
  }else{
    if(d&1){
      buf[y][x]=3;
    }else{
      buf[y][x]=1;
    }
    return dfs(y,x,d,gy,gx,gd);
  }
}
int main(){
  int T;cin>>T;
  for(int setn=1;setn<=T;++setn){
    memset(buf,0,sizeof(buf));
    printf("Case #%d:\n",setn);

    cin>>h>>w;
    int n=2*(h+w);
    REP(i,n/2){
      int a,b;cin>>a>>b;
      --a;--b;
      con[a]=b;
      con[b]=a;
    }

    bool fail=false;
    REP(i,n) REP(j,i) if(i<con[i] && j<con[j]){
      if(con[j]<con[i] && i<con[j]){
        fail=1;
        dump(i);dump(con[i]);dump(j);dump(con[j]);
      }
    }
    dump(fail);
    if(!fail){
      REP(len,n) REP(i,n) if(con[i]-i==len){
        dump(i);dump(con[i]);
        int x,y,d,x2,y2,d2;
        conv(i,y,x,d);
        conv(con[i],y2,x2,d2);
        y2+=dy[d2];x2+=dx[d2];
        dump(y2);dump(x2);dump(d2);
        if(!dfs(y,x,d,y2,x2,d2)){
          fail=true;
          goto exi;
        }
      }
      exi:;
    }
    dump(fail);

    if(fail) puts("IMPOSSIBLE");
    else{
      REP(i,h){
        REP(j,w) putchar(buf[i][j]==3?'\\':'/');
        puts("");
      }
    }
  }
  return 0;
}



