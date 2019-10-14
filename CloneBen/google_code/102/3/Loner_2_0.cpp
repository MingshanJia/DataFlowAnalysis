#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <algorithm>

using namespace std;

int n;
int X[1000], Y[1000], Z[1000], W[1000];

double getX( double X, double Y ) { return X + Y; }
double getY( double X, double Y ) { return X - Y; }

bool check( double D )
{
	for( int i = 0; i < n; ++i ) {
		bool ok = true;
		double Xmin = -1e10, Xmax = 1e10, Ymin = -1e10, Ymax = 1e10;

		for( int j = 0; j < n; ++j ) {
			double cD = D * W[j] - abs( Z[i] - Z[j] );
			if( cD < 0 ) { ok = false; break; }

			Xmin = max( Xmin, getX( X[j], Y[j] - cD ) );
			Xmax = min( Xmax, getX( X[j], Y[j] + cD ) );
			Ymin = max( Ymin, getY( X[j], Y[j] + cD ) );
			Ymax = min( Ymax, getY( X[j], Y[j] - cD ) );
		}

		if( !ok ) continue;
		if( Xmin <= Xmax && Ymin <= Ymax ) return true;
	}

	return false;
}

int main( void )
{
	freopen( "Csmall.in", "r", stdin );
    freopen( "Csmall.out", "w", stdout );

	int ntc; scanf( "%d", &ntc );

	for( int tc = 0; tc < ntc; ++tc ) {
		scanf( "%d", &n );
		for( int i = 0; i < n; ++i )
			scanf( "%d %d %d %d", X + i, Y + i, Z + i, W + i );

		double l = 0, r = 100000000;

		for( int iter = 0; iter < 100; ++iter ) {
			double m = (l + r) / 2;

			if( check( m ) )
				r = m;
			else
				l = m;
		}

		printf( "Case #%d: %.6lf\n", tc + 1, r );
	}

	return 0;
}
