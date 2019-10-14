#include <cstdio>
#include <cstring>

const int mod = 1000;

int n;
int X[2][2], W[2][2];

inline int normalize( int x ) { return (x%mod + mod) % mod; }

void matrixMult( int A[][2], int B[][2] )
{
	int C[2][2]; memset( C, 0, sizeof C );

	for( int k = 0; k < 2; ++k )
		for( int i = 0; i < 2; ++i )
			for( int j = 0; j < 2; ++j )
				C[i][j] = normalize( C[i][j] + A[i][k] * B[k][j] );

	for( int i = 0; i < 2; ++i )
		for( int j = 0; j < 2; ++j )
			A[i][j] = C[i][j];
}

int main( void )
{
	freopen( "C.in", "r", stdin );
	freopen( "C.out", "w", stdout );

	int round = 0, nround; scanf( "%d", &nround );

	while( nround-- ) {
		scanf( "%d", &n );

		printf( "Case #%d: ", ++round );
		if( n == 2 ) printf( "027\n" ); // special case
		else {
			X[0][0] = normalize( 6 ); X[0][1] = normalize( 28 );

			W[0][0] = normalize( 0 ); W[0][1] = normalize( -4 );
			W[1][0] = normalize( 1 ); W[1][1] = normalize( 6  );

			n -= 2;
			while( n ) {
				if( n & 1 )
					matrixMult( X, W );
				matrixMult( W, W );
				n /= 2;
			}

			if( X[0][1] < 10 ) putchar( '0' );
			if( X[0][1] < 100 ) putchar( '0' );
			printf( "%d\n", normalize( X[0][1] - 1 ) );
		}
	}

	return 0;
}
