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

int main()
{
	freopen("A-small-attempt0 (1).in","rt",stdin);
	freopen("a.out","wt",stdout);
	int tt,k,n;
	cin>>tt;
	int t = 0;
	while(tt--)
	{
		set<int> ss;

		cin>>n;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>k;
			if(ss.find(k)!=ss.end())
				ss.erase(k);
			else
				ss.insert(k);
		}
		cout<<"Case #"<<++t<<": ";
		cout<<*ss.begin()<<endl;


	}

	return 0;
}
