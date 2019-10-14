#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1000000;
const int MAXQ = 100;

int Q[MAXQ];
int SOL[MAXN];

struct population {
  vector< int > V;

  population( int n ) {
    V.resize( n );
    for( int i = 0; i < n; ++i )
      V[i] = i;
  }
  
  int daj( int k ) {
    int sol = V[k];
    V.erase( V.begin() + k );
    return sol;
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
