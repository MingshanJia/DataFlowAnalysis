#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

typedef vector<int> VI;

int n, m;
int like[2000][2000];
int left[2000], done[2000];

VI impact[2000];
int state[2000];

int main( void )
{
	int round = 0, nround; scanf( "%d", &nround );

	while( nround-- ) {
		scanf( "%d %d", &n, &m );

		for( int i = 0; i < n; ++i )
			impact[i].clear();

		memset( like, -1, sizeof like );
		memset( state, -1, sizeof state );

		for( int i = 0; i < m; ++i ) {
			scanf( "%d", left + i );

			for( int j = 0; j < left[i]; ++j ) {
				int k, l; scanf( "%d %d", &k, &l ); --k;

				like[i][k] = l;
				impact[k].push_back( i );
			}
		}

		memset( done, 0, sizeof done );
		memset( state, -1, sizeof state );

		bool fail = false;

		for( int i = 0; i < m; ++i ) {
			int k = -1;

			for( int j = 0; j < m; ++j )
				if( !done[j] && !left[j] ) { fail = true; break; }
			if( fail ) break;
			for( int j = 0; j < m; ++j )
				if( !done[j] && left[j] == 1 ) { k = j; break; }
			if( k < 0 ) break;

			for( int j = 0; j < n; ++j )
				if( like[k][j] >= 0 && state[j] < 0 ) {
					state[j] = like[k][j];
					for( VI::iterator it = impact[j].begin(); it != impact[j].end(); ++it ) {
						if( like[k][j] == like[*it][j] ) done[*it] = 1;
						else --left[*it];
					}
					break;
				}
		}

		printf( "Case #%d:", ++round );
		if( fail ) printf( " IMPOSSIBLE\n" );
		else {
			for( int i = 0; i < n; ++i )
				printf( " %d", state[i] >? 0 );
			putchar( '\n' );
		}
	}

	return 0;
}
