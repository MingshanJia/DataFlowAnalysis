#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef long long int64;

#define forit(a,b) for(typeof((b).end()) a=(b).begin();a!=(b).end();a++)
#define clr(a,b) memset(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define sorta(a) sort(all(a))
#define scan(a) fscanf(in,"%d",&a)

FILE *in = fopen( "f.in" , "r" );
FILE *out = fopen( "f.out" , "w" );

vector< int > adj[ 1111 ];
int N , R , deg[ 1111 ];
bool vis[ 1111 ];
int Q[ 1111 ] , sq , eq;
vector< int > comp;

int main(){
	int tes; scan( tes );
	
	for( int ttes = 1 ; ttes <= tes ; ttes++ ){
		clr( deg , 0 );
		scan( N ); scan( R );
		for( int q = 0 ; q < N ; q++ ){
			adj[ q ].clear();
		}
		for( int q = 0 ; q < R ; q++ ){
			int A , B;
			scan( A ); scan( B );
			deg[ A ] ++; 
			deg[ B ] ++;
			adj[ A ].push_back( B );
			adj[ B ].push_back( A );
		}
		memset( vis , 0 , sizeof vis );
		comp.clear();
		for( int q = 0 ; q < N ; q++ ){
			if( vis[ q ] == 0 && adj[ q ].size() ){
				sq = eq = 0;
				Q[ eq ++ ] = q;
				int cnt = 0;
				vis[ q ] = 1;
				while( sq < eq ){
					int cur = Q[ sq ++ ];
					if( deg[ cur ] % 2 ) cnt ++;
					for( int w = 0 ; w < (int)adj[ cur ].size() ; w++ ){
						int i = adj[ cur ][ w ];
						if( vis[ i ] ) continue;
						vis[ i ] = 1;
						Q[ eq ++ ] = i;
					}
				}
				comp.push_back( cnt );
			}
		}
		int ret = comp.size();
		if( comp.size() == 1 && comp[ 0 ] == 0 ) ret = 0;
		for( int q = 0 ; q < (int)comp.size() ; q++ ){
			if( comp[ q ] != 0 ){
				ret += comp[ q ] / 2 - 1;
			}
		}
		fprintf( out , "Case #%d: %d\n" ,ttes ,ret );
	}
	
	return 0;
}