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

int N , M , arr[ 20 ];

int profit( int a , int b ){
	int howa = M / arr[ a ]; 
	return arr[ b ] * howa - arr[ a ] * howa;
}   

int main(){
	int tes; scan( tes );
	for( int ttes = 1 ; ttes <= tes ; ttes++ ){
		scan( M );
		for( int q = 0 ; q < 12 ; q++ ){
			scan( arr[ q ] );
		}
		int ret = -1 , a , b;
		for( int q = 0 ; q < 12 ; q++ ){
			for( int w = q + 1 ; w < 12 ; w++ ){
				if( profit( q , w ) <= 0 ) continue;
				if( ret == -1 ){
					ret = profit( q , w );
					a = q; b = w;
				}
				if( profit( q , w ) > profit( a , b ) ){
					ret = profit( q , w );
					a = q; b = w;
				}
				else if( profit( q , w ) == profit( a , b ) ){
					if( arr[ a ] > arr[ q ] ){
						ret = profit( q , w );
						a = q; b = w;
					}
				}
			}
		}
		if( ret == -1 ) fprintf( out , "Case #%d: IMPOSSIBLE\n" ,ttes );
		else fprintf( out , "Case #%d: %d %d %d\n" ,ttes ,a + 1 ,b + 1 ,profit( a , b ) );
	}
	return 0;
}