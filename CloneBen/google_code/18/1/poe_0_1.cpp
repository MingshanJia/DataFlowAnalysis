#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

long long N, PP[3][3];
map < vector<long long>, long long > M;

long long Dynamic( vector<long long>& P ) {
	long long SN = 0;
	for( int i=0; i<6; i++ ) SN += P[i];
	if( SN == 0 ) {
		return 0LL;
	}

	if( M.find( P ) != M.end() ) return M[P];
	long long ret = -987654321987654321LL;

	long long mini;
	for( int i=0; i<3; i++ ) {
		for( int j=3; j<6; j++ ) {
			mini = min( P[i], P[j] );
			if( mini == 0 ) continue;
			P[i] -= mini;
			P[j] -= mini;
			ret = max( ret, mini*PP[i][j-3]+Dynamic( P ) );
			P[i] += mini;
			P[j] += mini;
		}
	}

	return M[P]=ret;
}
int main() {
	freopen( "A_Large.in", "r", stdin );
	freopen( "A_Large.out", "w", stdout );
	
	long long TC;
	cin >> TC;

	
	for( long long TCC=1; TCC<=TC; TCC++ ) {
		vector<long long> ST( 6 );
		cin >> N;
		for( int i=0; i<6; i++ )
			cin >> ST[i];
		for( int i=0; i<3; i++ ) {
			for( int j=0; j<3; j++ ) {
				cin >> PP[i][j];
			}
		}

		M.clear();
		long long ret = Dynamic( ST );
		cout << "Case #" << TCC << ": " << ret << endl;
	}
}

/*
1
10000000000000 10000000000000 0 0 10000000000000 0 0
100000 100000 100000
100000 100000 100000
100000 100000 100000
*/