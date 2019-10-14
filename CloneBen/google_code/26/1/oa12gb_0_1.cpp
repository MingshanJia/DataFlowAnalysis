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
#include <bitset>
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
FILE *out = fopen( "output.txt" , "w" );

int N , A[ 2 ][ 1111 ] , cA[ 2 ];

int main(){
	
	int tes; scan( tes );
	
	for( int ttes = 1 ; ttes <= tes ; ttes ++ ){
		scan( N );
		cA[ 0 ] = cA[ 1 ] = 0;
		for( int q = 0 ; q < N ; q++ ){
			char inp[ 111 ];
			fscanf( in , "%s" ,inp );
			string q = inp; char col = q[ q.size() - 1 ];
			q = q.substr( 0 , q.size() - 1 );
			stringstream is( q ); int k; is >> k;
			if( col == 'R' ){
				A[ 0 ][ cA[ 0 ] ++ ] = k;
			}
			else{
				A[ 1 ][ cA[ 1 ] ++ ] = k;
			}
		}
		sort( A[ 0 ] , A[ 0 ] + cA[ 0 ] );
		sort( A[ 1 ] , A[ 1 ] + cA[ 1 ] );
		
		int ret = 0;
		for( int q = 0 ; q < min( cA[ 0 ] , cA[ 1 ] ) ; q++ ){
			ret += A[ 0 ][ cA[ 0 ] - q - 1 ] - 1;
			ret += A[ 1 ][ cA[ 1 ] - q - 1 ] - 1;
		}
		fprintf( out , "Case #%d: %d\n" ,ttes ,ret );
	}
	
	return 0;
}