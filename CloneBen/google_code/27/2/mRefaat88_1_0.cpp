/*
ID: mythic_1
PROG: b
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

int main()
{
	freopen("B-small-attempt0 (1).in","rt",stdin);
	freopen("b.out","wt",stdout);

	int tt;
	int t = 0;
	scanf("%d",&tt);
	while(tt--)
	{
		int n,tr,e,a,b;
		scanf("%d",&n);
		scanf("%d",&tr);
		scanf("%d",&e);
		int ts[101]={0};
		vector<int>cs[101] ;
		for(int i = 0 ; i < e ; i++)
		{
			scanf("%d%d",&a,&b);
			ts[a]++;
			cs[a].push_back(b);
		}
		for(int i = 1 ; i <= n ; i ++)
			sort(cs[i].rbegin(),cs[i].rend());
		vector<int> res;
		bool im = 0;
		for(int k = 1 ; k <= n ; k++)
		{

			int c = 0;
			if(k!=tr){
			while(ts[k]>0&&c<sz(cs[k]))
				ts[k]-=cs[k][c++];
			if(ts[k]>0){im = true;
			break;}
			}
			res.push_back(c);
		}
		printf("Case #%d:",++t);
		if(im)printf(" IMPOSSIBLE\n");
		else
		{
		for(int i = 0 ; i < sz(res) ; i++)
			printf(" %d",res[i]);
		printf("\n");
		}

	}

	return 0;
}
