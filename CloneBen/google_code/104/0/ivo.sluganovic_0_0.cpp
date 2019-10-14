#include <cstdio>
#include <cstring>
using namespace std;

long long C[3][3];

long long C3( long long x )
{
  return ( x * ( x - 1 ) * ( x - 2 ) / 6 );
}

int main()
{
  int t; scanf( "%d", &t );
  
  for( int t_case = 0; t_case < t; ++t_case ) {
    int n; scanf( "%d", &n );
    long long A, B, CC, D, X, Y, M; 
    scanf( "%lld%lld%lld%lld%lld%lld%lld", &A, &B, &CC, &D, &X, &Y, &M );

    memset( C, 0, sizeof( C ) );

    ++C[X%3][Y%3];
    for( int i = 1; i < n; ++i ) {
      X = ( A * X + B ) % M;
      Y = ( CC * Y + D ) % M;
      ++C[X%3][Y%3];
    }
    
    long long sol = 0;
    
    sol += C3( C[0][0] ) + C[0][0] * C[0][1] * C[0][2] + C3( C[0][1] ) + C3( C[0][2] );
    sol += C[0][0] * C[1][0] * C[2][0] + C[0][1] * C[1][1] * C[2][1] + C[0][2] * C[1][2] * C[2][2];
    sol += C[0][0] * C[1][1] * C[2][2] + C[0][0] * C[1][2] * C[2][1] + C[0][1] * C[1][0] * C[2][2] +
      C[0][1] * C[1][2] * C[2][0] + C[0][2] * C[1][0] * C[2][1] + C[0][2] * C[1][1] * C[2][0];
    sol += C3( C[1][0] ) + C[1][0] * C[1][1] * C[1][2] + C3( C[1][1] ) + C3( C[1][2] );
    sol += C3( C[2][0] ) + C[2][0] * C[2][1] * C[2][2] + C3( C[2][1] ) + C3( C[2][2] );

    printf( "Case #%d: %lld\n", t_case + 1, sol );
  }
  return 0;
}
