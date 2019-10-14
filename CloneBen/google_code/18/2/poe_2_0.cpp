#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int DR[] = { 0, 0, 1, -1 };
const int DC[] = { 1, -1, 0, 0 };

int KK, N, M;
int KN[5+10];
char map[5+10][5+10][5+10];

void DFS( int K, int R, int C ) {
	if( R < 0 || R >= N ) return;
	if( C < 0 || C >= M ) return;
	if( map[K][R][C] != '.' ) return;
	map[K][R][C] = KN[K];
	for( int i=0; i<4; i++ )
		DFS( K, R+DR[i], C+DC[i] );
}


bool neigh[5+10][13+10][13+10];
vector< pair<int,int> > neigh2[5+10];
int d[5+10][(1<<14)+10];

inline bool CanIt( int P, int TST, int PST ) {
	for( int i=0; i<KN[P-1]; i++ ) {
		for( int j=0; j<KN[P]; j++ ) {
			if( ( (PST>>i) & 1 ) && ( (TST>>j) & 1 ) ) {
				if( neigh[P-1][i][j] )
					return false;
			}
		}
	}
	return true;
}

inline bool CanIt2( int P, int TST, int PST ) {
	for( int i=0; i<neigh2[P-1].size(); i++ ) {
		if( ( (PST>>neigh2[P-1][i].first) & 1 ) && (TST>>neigh2[P-1][i].second & 1 ) )
			return false;
	}
	return true;
}

int Dynamic( int P, int ST ) {
	if( P == KK ) {
		return 0;
	}

	int& ret = d[P][ST];
	if( ret != -1 ) return ret;
	ret = 0;

	if( P > 0 ) {
		int sub_ret;
		for( int i=0; i<(1<<KN[P]); i++ ) {
			if( neigh2[P].size() >= 6 ) {
				if( !CanIt( P, i, ST ) ) continue;
			}
			else {
				if( !CanIt2( P, i, ST ) ) continue;
			}

			sub_ret = 0;
			for( int j=0; j<KN[P]; j++ )
				if( (i>>j) & 1 ) sub_ret++;
			ret = max( ret, sub_ret+Dynamic( P+1, i ) );
		}
	}
	else {
		int sub_ret;
		for( int i=0; i<(1<<KN[P]); i++ ) {
			sub_ret = 0;
			for( int j=0; j<KN[P]; j++ )
				if( (i>>j) & 1 ) sub_ret++;
			ret = max( ret, sub_ret+Dynamic( P+1, i ) );
		}
	}

	return ret;
}

int main() {
	freopen( "C_Small.in", "r", stdin );
	freopen( "C_Small.out", "w", stdout );

	int TC;
	cin >> TC;

	for( int TCC=1; TCC<=TC; TCC++ ) {
		int K;
		cin >> N >> M >> K;
		KK = K;
		memset( KN, 0, sizeof KN );
		for( int k=0; k<K; k++ ) {
			for( int i=0; i<N; i++ )
				cin >> map[k][i];

			for( int i=0; i<N; i++ ) {
				for( int j=0; j<M; j++ ) {
					if( map[k][i][j] == '.' ) {
						DFS( k, i, j );
						KN[k]++;
					}
				}
			}
		}

		memset( neigh, false, sizeof neigh );
		for( int i=0; i<5; i++ )
			neigh2[i].clear();
		for( int k=0; k<K-1; k++ ) {
			for( int i=0; i<N; i++ ) {
				for( int j=0; j<M; j++ ) {
					if( map[k][i][j] != '#' && map[k+1][i][j] != '#' ) {
						neigh[k][ map[k][i][j] ][ map[k+1][i][j] ] = true;
						neigh2[k].push_back( make_pair( map[k][i][j], map[k+1][i][j] ) );
					}
				}
			}
		}

		for( int k=0; k<K-1; k++ ) {
			//cout << neigh2[k].size() << ' ';
			sort( neigh2[k].begin(), neigh2[k].end() );
			neigh2[k].erase( unique( neigh2[k].begin(), neigh2[k].end() ), neigh2[k].end() );
			//cout << neigh2[k].size() << endl;
		}
		memset( d, -1, sizeof d );
		printf( "Case #%d: %d\n", TCC, Dynamic( 0, 0 ) );
	}
}