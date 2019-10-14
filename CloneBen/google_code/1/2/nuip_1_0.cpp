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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int kase_;
  cin>>kase_;
	rep(kase,kase_){
		int n,q;
		cin>>n>>q;
		vector<pii> ints(n);
		vector<ll> qs(q);
		{
			vector<ll> a(3),b(3),c(3),m(3),O0(3),O1(3);
			rep(i,3) cin>>O0[i]>>O1[i]>>a[i]>>b[i]>>c[i]>>m[i];
			vector<int> len{n,n,q};
			vv<ll> gen;
			rep(i,3){
				const int N=len[i];
				gen.eb(N+2);
				gen.back()[0]=O0[i];
				gen.back()[1]=O1[i];
				reps(j,2,N){
					auto tmp=((a[i]*gen.back()[j-1]+b[i]*gen.back()[j-2]+c[i])%m[i]);
					gen.back()[j]=tmp;
				}
			out(gen,1);
			}
			out(gen,1);
			auto &xs=gen[0];
			auto &ys=gen[1];
			auto &zs=gen[2];
			rep(i,n) ints[i]=pii(min(xs[i],ys[i])+1,max(xs[i],ys[i])+2);
			qs=zs;
			qs.resize(q);
		}
		out(ints,qs,1);
		map<ll,ll> imo;
		for(pll p:ints){
			++imo[p.X];
			--imo[p.Y];
		}
		vector<ll> sum,xs,val;
		{
			ll prv=-1,v=0,s=0;
			for(auto p:imo){
				ll prd=(p.X-prv)*v+s;
				s=prd;
				sum.pb(prd);
				prv=p.X;
				xs.pb(prv);
				v+=p.Y;
				val.pb(v);
			}
		}
		out(sum,xs,val,1);
		ll ans=0;
		rep(i,q){
			ll x=qs[i];
			if(x>=sum.back()) continue;
			x=sum.back()-x-1;
			int l=0,r=sum.size()-1;
			while(r-l>1){
				int m=(l+r)/2;
				(sum[m]>x?r:l)=m;
			}
			ll rem=x-sum[l];
			ll re=xs[l]+rem/val[l];
			out(x,l,r,rem,1);
			ans+=re*(i+1);
			out(i,re,1);
			// cout<<i<<":"<<re<<endl;
		}
  	cout<<"Case #"<<kase+1<<": "<<ans<<endl;
  }
  return 0;
}
