#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(-data[y]>-data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
};

const int INF=100000;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int kase_;
  cin>>kase_;
	rep(kase,kase_){
		int n,m,e,sy,sx,ty,tx;
		cin>>n>>m>>e>>sy>>sx>>ty>>tx; --sy; --sx; --ty; --tx;
		vv<int> mp(n,vector<int>(m));
		rep(i,n)rep(j,m) cin>>mp[i][j];
		auto fun=[&](int x,int y){ return y*m+x;};
		vector<pii> ts;
		rep(i,n)rep(j,m)if(mp[i][j]<0 && mp[i][j]!=-INF) ts.eb(j,i);
		out(ts,1);
		int t=ts.size();
		vector<ll> val(1<<t);
		vector<ll> ok(1<<t);
		vv<int> usd(n,vector<int>(m));
		rep(i,1<<t){
			rep(j,t)if(i>>j&1){
				int x,y; tie(x,y)=ts[j];
				// if(x && (mp[y][x-1]>=0 || usd[y][x-1])) uf1.unite(fun(x,y),fun(x-1,y));
				// if(y && (mp[y-1][x]>=0 || usd[y-1][x])) uf1.unite(fun(x,y),fun(x,y-1));
				// if(x+1<m && (mp[y][x+1]>=0 || usd[y][x+1])) uf1.unite(fun(x,y),fun(x+1,y));
				// if(y+1<n && (mp[y+1][x]>=0 || usd[y+1][x])) uf1.unite(fun(x,y),fun(x,y+1));
				usd[y][x]=1;
			}
			UF uf(n*m);
			rep(i,n)rep(j,m)if(mp[i][j]>=0 || usd[i][j]){
				if(i && (mp[i-1][j]>=0 || usd[i-1][j])) uf.unite(fun(j,i),fun(j,i-1));
				if(j && (mp[i][j-1]>=0 || usd[i][j-1])) uf.unite(fun(j,i),fun(j-1,i));
			}
			rep(j,n*m)if(uf.findSet(fun(sx,sy),j)) val[i]+=mp[j/m][j%m];
			if(uf.findSet(fun(sx,sy),fun(tx,ty))) ok[i]|=1<<t;
			rep(j,t)if(!(i>>j&1)){
				int x,y; tie(x,y)=ts[j];
				if(x && uf.findSet(fun(sx,sy),fun(x-1,y))) ok[i]|=1<<j;
				if(y && uf.findSet(fun(sx,sy),fun(x,y-1))) ok[i]|=1<<j;
				if(x+1<m && uf.findSet(fun(sx,sy),fun(x+1,y))) ok[i]|=1<<j;
				if(y+1<n && uf.findSet(fun(sx,sy),fun(x,y+1))) ok[i]|=1<<j;
			}
			// if(!i) rep(j,n*m){if(j%m==0) cout<<endl; cout<<uf.findSet(fun(sx,sy),j);}
			// if(!i) rep(j,n*m){if(j%m==0) cout<<endl; cout<<mp[j/m][j%m]<<" ";}
			rep(j,t)if(i>>j&1){
				int x,y; tie(x,y)=ts[j];
				usd[y][x]=0;
			}
		}
		out(val,1);
		vector<int> vst(1<<t); vst[0]=1;
		queue<int> que; que.emplace(0);
		while(que.size()){
			int i=que.front(); que.pop();
			rep(j,t)if(ok[i]>>j&1){
				int ii=(i|(1<<j));
				if(e+val[i]>=-mp[ts[j].Y][ts[j].X] && MX(vst[ii],1)) que.emplace(ii);
			}
		}
		ll re=-1;
		rep(i,1<<t)if(vst[i] && (ok[i]>>t&1)) MX(re,e+val[i]);
		cout<<"Case #"<<kase+1<<": "<<re<<endl;
  }
  return 0;
}
