/*
TASK:
LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <valarray>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

template<class key>
struct hashtemp
{

	enum
	{
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)



typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef unsigned long long i64;  typedef unsigned long long u64;
vector<pair<int,int> > t,l;
vector<pair<int,pair<int,int> > > s,d;
vector<set<int> > sol;
bool isvalid(int x)
{
	rep(i,sz(t))
	{
		int a=t[i].first;
		int b=t[i].second;
		if((x>>a)&1)
		{
			if(((x>>b)&1)==0)
				return false;
		}
		else
		{
			if(((x>>b)&1)==1)
				return false;
		}
	}
	rep(i,sz(l))
	{
		int a=l[i].first;
		int b=l[i].second;
		if((x>>a)&1)
		{
			if(((x>>b)&1)==1)
				return false;
		}
		else
		{
			if(((x>>b)&1)==0)
				return false;
		}
	}
	rep(i,sz(s))
	{
		int a=s[i].first;
		int b=s[i].second.first;
		int c=s[i].second.second;
		if((x>>a)&1)
		{
			if(((x>>b)&1)!=((x>>c)&1))
				return false;
		}
		else
		{
			if(((x>>b)&1)==((x>>c)&1))
				return false;
		}
	}
	rep(i,sz(d))
	{
		int a=d[i].first;
		int b=d[i].second.first;
		int c=d[i].second.second;
		if((x>>a)&1)
		{
			if(((x>>b)&1)==((x>>c)&1))
				return false;
		}
		else
		{
			if(((x>>b)&1)!=((x>>c)&1))
				return false;
		}
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	//freopen("D-large.in","rt",stdin);
	freopen("D-small-attempt1.in","rt",stdin);
	//freopen("1.in","rt",stdin);
	freopen("1.out","wt",stdout);
#endif
	int T;
	cin>>T;
	rep(tt,T)
	{
		printf("Case #%d:",tt+1);
		s.clear();
		t.clear();
		l.clear();
		d.clear();
		sol.clear();
		int n,m,x,y,z;
		cin>>n>>m;
		sol.resize(n);
		rep(i,m)
		{
			char c;
			cin>>x>>c>>y;
			switch(c)
			{
			case 'T':
				t.push_back(make_pair(x-1,y-1));
				break;
			case 'L':
				l.push_back(make_pair(x-1,y-1));
				break;
			case 'S':
				cin>>z;
				s.push_back(make_pair(x-1,make_pair(y-1,z-1)));
				break;
			case 'D':
				cin>>z;
				d.push_back(make_pair(x-1,make_pair(y-1,z-1)));
				break;
			}
		}
		rep(i,1<<n)
		{
			if(isvalid(i))
			{
				rep(j,n)
					sol[j].insert((i>>j)&1);
			}
		}
		rep(i,n)
			if(sol[i].size()==1)
				cout<<" "<<((*sol[i].begin())?"T":"L");
			else
				cout<<" "<<"-";
		cout<<endl;
	}
	return 0;
}
