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
	freopen("b.in","rt",stdin);
	freopen("b.txt","w",stdout);
#endif

	int test,m;
	int p[12];

	scanf("%d",&test);

	for( int tt = 1 ; tt <= test ; tt++ )
	{
		scanf("%d",&m);

		for( int i = 0 ; i < 12 ; i++ )
			scanf("%d",p+i);

		int res = 0,s = -1,e = -1;

		for( int i = 0 ; i < 12 ; i++ )
		{
			for( int j = i+1 ; j < 12 ; j++ )
			{
				int cnt = m/p[i];

				if( cnt > 0 && cnt*(p[j]-p[i]) > res)
				{
					res = cnt*(p[j]-p[i]);
					s = i+1;
					e = j+1;
				}

				if( cnt > 0 && cnt*(p[j]-p[i]) == res && s != -1 )
				{
					if( p[i] < p[s-1] )
						s = i+1,e = j+1;
				}
			}
		}

		printf("Case #%d: ",tt);

		if( s == -1 )
			printf("IMPOSSIBLE\n");

		else
			printf("%d %d %d\n",s,e,res);
	}
	return 0;
}
