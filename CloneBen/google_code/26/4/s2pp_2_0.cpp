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

char board[50][50];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","rt",stdin);
	freopen("c.txt","w",stdout);
#endif

	int test,r,c;

	scanf("%d", &test);

	for( int tt = 1 ; tt <= test ; tt++ )
	{
		scanf("%d%d", &c, &r);

		for( int i = 0 ; i < r ; i++ )
			for( int j = 0 ; j < c ; j++ )
				scanf(" %c",board[i]+j);

		int res = 0;

		for( int rs = 0 ; rs < r ; rs++ )
			for( int cs = 0 ; cs < c ; cs++ )
				for( int re = rs+1 ; re <= r ; re++ )
					for( int ce = cs+1 ; ce <= c ; ce++ )
					{
						bool flag = true;
						for( int i = rs ; i < re ; i++ )
							for( int j = cs ; j < ce ; j++ )
								if( tolower(board[i][j]) == 'w' || tolower(board[i][j]) == 'r' || tolower(board[i][j]) == 't' )
								{
									flag = false;
									goto sol;
								}

						sol:
						if( flag )
							res = max(res,(re-rs) * (ce-cs));
					}

		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}
