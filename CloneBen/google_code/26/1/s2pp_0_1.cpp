#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
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

using namespace std;

#define eps 1e-12
#define oo (int)1e9
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin() ; i != (c).end() ; i++)

typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","rt",stdin);
	freopen("a.txt","w",stdout);
#endif

	int test,s,l;
	char c;

	scanf("%d",&test);

	for( int tt = 1 ; tt <= test ; tt++ )
	{
		scanf("%d",&s);
		vector<int> b,r;

		for( int i = 0 ; i < s ; i++ )
		{
			scanf("%d %c",&l,&c);

			if( c == 'B' || c == 'b' )
				b.push_back(l);
			else
				r.push_back(l);
		}

		sort(b.rbegin(),b.rend());
		sort(r.rbegin(),r.rend());

		int res = 0;
		int mn = min(r.size(),b.size());

		for( int i = 0 ; i < mn ; i++ )
			res += r[i] + b[i] - 2;

		printf("Case #%d: %d\n",tt,res);
	}

	return 0;
}
