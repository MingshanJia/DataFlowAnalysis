#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1000;

int gcd( int a, int b )
{
  if ( b == 0 ) return a;
  return gcd( b, a % b );
}

int dad[MAXN];
int level[MAXN];

int find( int sad )
{
  if ( dad[sad] != sad ) dad[sad] = find( dad[sad] );
  return dad[sad];
}

bool merge( int a, int b ) 
{
  a = find( a );
  b = find( b );
  if ( a == b ) return false;
  if ( level[a] > level[b] )
    dad[b] = a;
  else {
    dad[a] = b;
    if ( level[a] == level[b] )
      ++level[b];
  }
  return true;
}

vector< int > P;
int PP;

bool ok( int a, int b )
{
  int G = gcd( a, b );
  for( int i = 0; i < ( int )P.size() && P[i] >= PP; ++i )
    if ( G % P[i] == 0 ) return true;
  return false;
}

bool prime( int x ) 
{
  for( int i = 2; i * i <= x; ++i )
    if ( x % i == 0 ) return false;

  return true;
}

int main()
{
  for( int i = 1000000; i > 1; --i )
    if ( prime( i ) )
      P.push_back( i );

  int t; scanf( "%d", &t );
  for( int t_case = 0; t_case < t; ++t_case ) {
    int A, B; scanf( "%d%d%d", &A, &B, &PP );
    
    for( int i = A; i <= B; ++i ) {
      dad[i-A] = i - A;
      level[i-A] = 0;
    }

    int sol = B - A + 1;
    for( int i = 0; i < ( int )P.size() && P[i] >= PP; ++i ) {
      if ( P[i] > B - A + 1 ) continue;

      int prvi = A;
      int x = A % P[i];
      if ( x > 0 )
	prvi += ( P[i] - x );

      for( int j = 1; prvi + j * P[i] <= B; ++j )
	sol -= merge( prvi - A, prvi + j * P[i] - A );
    }
    printf( "Case #%d: %d\n", t_case + 1, sol );
  }
  return 0;
}
