#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N, DD, EE, FF;
int S[100+10];
int d[100+10][100+10][100+10];
int PP[3][3];

int Dynamic( int P, int D, int E ) {
	int F = FF - ( P - (DD-D) - (EE-E) );
	if( D < 0 || E < 0 || F < 0 ) return -1000000007;
	if( P == N ) return 0;
	
	int& ret = d[P][D][E];
	if( ret != -1000000007 ) return ret;
	
	ret = max( ret, PP[S[P]][0]+Dynamic( P+1, D-1, E ) );
	ret = max( ret, PP[S[P]][1]+Dynamic( P+1, D, E-1 ) );
	ret = max( ret, PP[S[P]][2]+Dynamic( P+1, D, E ) );
	
	return ret;
}

int main() {
	freopen( "A_Small.in", "r", stdin );
	freopen( "A_Small.out", "w", stdout );
	
	int TC;
	scanf( "%d", &TC );

	for( int TCC=1; TCC<=TC; TCC++ ) {
		int A, B, C, D, E, F;
		scanf( "%d %d %d %d %d %d %d", &N, &A, &B, &C, &D, &E, &F );
		for( int i=0; i<3; i++ ) {
			for( int j=0; j<3; j++ ) {
				scanf( "%d", &PP[i][j] );
			}
		}
		for( int i=0; i<A; i++ ) S[i] = 0;
		for( int i=A; i<A+B; i++ ) S[i] = 1;
		for( int i=A+B; i<A+B+C; i++ ) S[i] = 2;
		
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<=N; j++ ) {
				for( int k=0; k<=N; k++ ) {
					d[i][j][k] = -1000000007;
				}
			}
		}

		DD = D;
		EE = E;
		FF = F;
		printf( "Case #%d: %d\n", TCC, Dynamic( 0, D, E ) );
	}
}