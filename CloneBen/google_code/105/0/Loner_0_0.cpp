#include <cstdio>

#include <algorithm>

using namespace std;

int n;
int A[800], B[800];

int main( void )
{
	freopen( "A.in", "r", stdin );
	freopen( "A.out", "w", stdout );

	int round = 0, nround; scanf( "%d", &nround );

	while( nround-- ) {
		scanf( "%d", &n );
		for( int i = 0; i < n; ++i )
			scanf( "%d", A + i );
		for( int i = 0; i < n; ++i )
			scanf( "%d", B + i );

		sort( A, A + n );
		sort( B, B + n ); reverse( B, B + n );

		int ret = 0;
		for( int i = 0; i < n; ++i )
			ret += A[i] * B[i];

		printf( "Case #%d: %d\n", ++round, ret );
	}

	return 0;
}
