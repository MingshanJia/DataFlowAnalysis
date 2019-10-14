#include <cstdio>

int N, M, A;

int main( void )
{
	freopen( "Bsmall.in", "r", stdin );
	freopen( "Bsmall.out", "w", stdout );

	int nround; scanf( "%d", &nround );

	for( int round = 0; round < nround; ) {
		scanf( "%d %d %d", &N, &M, &A );

		printf( "Case #%d: ", ++round );

		for( int i = 0; i <= N; ++i )
			for( int j = 0; j <= M; ++j )
				for( int k = 0; k <= N; ++k ) {
					//i * l - j * k = A

					int x = A + j * k;

					if( !i ) {
						if( !x ) {
							printf( "0 0 %d %d %d %d\n", i, j, k, M );
							goto finish;
						}
					} else {
						if( x % i == 0 ) {
							int l = x / i;
							if( l >= 0 && l <= M ) {
								printf( "0 0 %d %d %d %d\n", i, j, k, l );
								goto finish;
							}
						}
					}
				}
		
		printf( "IMPOSSIBLE\n" );
finish: ;
	}

	return 0;
}
