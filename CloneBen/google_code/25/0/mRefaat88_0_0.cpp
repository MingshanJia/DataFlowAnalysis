/*
ID: mythic_1
PROG: A
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <valarray>
#include <set>
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

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;
#define SMALL
//#define LARGE
int rem = 0;
int n;
long double eps = 1e-12;
/*int calc(long double d)
{
	int cnt = 0;
	while(d>tlten||d<tlt)
	{
		if(d>tlten)
			d-=tlt,d*=3;
		else d*=3;
		cnt++;
	}
	return cnt;
}*/
vector<pair< pair<int,long double>, string >  > v;

int calc(long double st,long double en,long double r)
{
	int cnt = 0;
	while(1){

		double strt = st+(en-st)/3;
		double end = en-(en-st)/3;
		if(r>=strt&&r<=end||end-strt<eps)
			return cnt;
		if(r<strt)
			en = strt-eps;
		else st= end+eps;
		cnt++;
	}
	return cnt;
}

int main()
{
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	int tt = 0;
	cin>>tt;
	long double temp;
	for(int t = 1 ; t <= tt ; t++)
	{
		//int res;
		cin>>n;
		v.clear();
		string str;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>str;
			stringstream ss;
			ss<<str;
			ss>>temp;

			v.push_back(make_pair(make_pair(calc(0.0,1.0,temp),temp),str));
		}
		sort(all(v));

		cout<<"Case #"<<t<<":\n";
		for(int i = 0  ; i < sz(v) ; i++)
			cout<<v[i].second<<endl;
	}

	return 0;
}
