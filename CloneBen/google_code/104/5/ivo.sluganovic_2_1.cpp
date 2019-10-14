#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1000000;
const int MAXQ = 100;

int Q[MAXQ];
int SOL[MAXN];

struct population {
  vector< int > V;
  int offset;

  population( int n ) {
    for( offset = 1; offset < n; offset *= 2 );
    V.resize( 2 * offset, 0 );
    for( int i = 0; i < n; ++i )
      V[offset+i] = 1;

    for( int i = offset - 1; i > 0; --i )
      V[i] = V[2*i] + V[2*i+1];
  }
  
  int daj( int k ) {
    for( int i = 1; ; ) {
      --V[i];
      if ( i >= offset ) return i - offset;
      if ( V[2*i] > k )
	i = 2 * i;
      else {
	k -= V[2*i];
	i = 2 * i + 1;
      }
    }
  }
};
  
int main()
{
  int t; scanf( "%d", &t );
  for( int t_case = 0; t_case < t; ++t_case ) {
    int n, q; scanf( "%d%d", &n, &q );

    population P( n );

    for( int i = 0; i < q; ++i ) {
      scanf( "%d", &Q[i] );
      --Q[i];
    }

    int z = 0;
    for( int i = 0; i < n; ++i ) {
      z = ( z + i ) % ( n - i );
      SOL[P.daj(z)] = i;
    }

    printf( "Case #%d:", t_case + 1 );
    for( int i = 0; i < q; ++i )
      printf( " %d", SOL[Q[i]] + 1 );
    putchar( '\n' );
  }
  return 0;
}
