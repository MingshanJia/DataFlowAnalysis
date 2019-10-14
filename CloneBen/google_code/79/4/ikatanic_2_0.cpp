#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

llint a[10005];

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( int c = 1; c <= t; ++c ) {
    int n;
    llint lo, hi;
    scanf( "%d %lld %lld", &n, &lo, &hi );
    for( int i = 0; i < n; ++i )
      scanf( "%lld", a+i );
    sort( a, a + n );

    llint ans = -1;
    for( int i = lo; i <= hi; ++i ) {
      int ok = 1;
      for( int j = 0; j < n; ++j )
	if( (i%a[j]) && (a[j]%i) ) { ok = 0; break; }
      if( ok ) { ans = i; break; }
    }

    printf( "Case #%d: ", c );
    if( ans == -1 ) puts( "NO" ); else
      printf( "%lld\n", ans );
  }
  return 0;
}

