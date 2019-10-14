/*
ID: mythic_1
PROG: c
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
#define rall(x) x.rbegin(),x.rend()
#define pb(x) push_back(x)
typedef long long ll;
bool check(vector<int>&r,int c)
{
	int s = 0;
	for(int i = 0 ; i < sz(r) ; i++)
		if(r[i]>0)s++;
	return s>=c;
}
int main()
{
	freopen("C-small-attempt1.in","rt",stdin);
	freopen("c.out","wt",stdout);
	int tt;
	scanf("%d",&tt);
	int t = 0;
	int c,p,x;
	while(tt--)
	{
		scanf("%d%d",&p,&c);
		vector<int> r;
		for(int i = 0 ; i < p ; i++)
		{
			scanf("%d",&x);
			r.push_back(x);
		}

		int res = 0;
		sort(rall(r));
		while(check(r,c))
		{
			res++;
			for(int j = 0 ; j < c ; j++)
				r[j]-=1;
			sort(rall(r));
		}
		printf("Case #%d: ",++t);
		printf("%d\n",res);

	}

	return 0;
}
