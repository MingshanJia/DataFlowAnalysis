#include <cstdio>
#include <cstring>

const int inf = 1000000000;

int n, m, value;
int state[10000], can[10000];

int dp[10000][2];

int solve( int x, int value )
{
	int &cost = dp[x][value];
	if( cost != -1 ) return cost;

	if( x > m ) 
		return cost = state[x] == value ? 0 : -2;

	cost = inf;

	for( int nstate = 0; nstate <2 ; ++nstate ) {
		if( !can[x] && state[x] != nstate ) continue;

		for( int lv = 0; lv < 2; ++lv )
			for( int rv = 0; rv < 2; ++rv ) {
				if( nstate ) {
					if( value != (lv && rv) ) continue;
				} else {
					if( value != (lv || rv) ) continue;
				}

				int lCost = solve( x*2, lv );
				int rCost = solve( x*2+1, rv );

				if( lCost < 0 || rCost < 0 ) continue;

				cost <?= lCost + rCost + (state[x] != nstate ? 1 : 0);
			}
	}

	if( cost == inf ) cost = -2;
	return cost;
}

int main( void )
{
	freopen( "pA.in", "r", stdin );
	freopen( "Asmall.out", "w", stdout );

	int tc = 0, ntc; scanf( "%d", &ntc );

	while( ntc-- ) {
		scanf( "%d %d", &n, &value );
		m = (n - 1) / 2;

		for( int i = 1; i <= m; ++i )
			scanf( "%d %d", state + i, can + i );
		for( int i = m+1; i <= n; ++i )
			scanf( "%d", state + i );

		memset( dp, -1, sizeof dp );
		int cost = solve( 1, value );

		printf( "Case #%d: ", ++tc );
		if( cost < 0 ) printf( "IMPOSSIBLE\n" );
		else printf( "%d\n", cost );
	}

	return 0;
}
