#include <stdio.h>
#include <string.h>

int state[100][100], info[100][100], temp[100];
void combineRight( int row, int n ) {
	int i, tos=-1, j;
	for( j=0; j<n; j++ ) {
		if( info[row][j] != 0 ) {
			temp[++tos] = info[row][j];
		}
	}
	for(j=n-1;tos>=0;j--) {
		info[row][j] = temp[tos--];
	}
	while(j>=0) {
		info[row][j] = 0;
		j--;
	}
}

void combineLeft( int row, int n ) {
	int i, tos=-1, j;
	for( j=0; j<n; j++ ) {
		if( info[row][j] != 0 ) {
			temp[++tos] = info[row][j];
		}
	}
	for(j=0;j<=tos;j++) {
		info[row][j] = temp[j];
	}
	while( j<n ) {
		info[row][j] = 0;
		j++;
	}
}

void combineUp( int col, int n ) {
	int i, tos=-1, j;
	for( i=0; i<n; i++ ) {
		if( info[i][col] != 0 ) {
			temp[++tos] = info[i][col];
		}
	}
	for(i=0;i<=tos;i++) {
		info[i][col] = temp[i];
	}
	while(i<n) {
		info[i][col] = 0;
		i++;
	}
}

void combineDown( int col, int n ) {
	int i, tos=-1, j;
	for( i=0; i<n; i++ ) {
		if( info[i][col] != 0 ) {
			temp[++tos] = info[i][col];
		}
	}
	for(i=n-1;tos>=0;i--) {
		info[i][col] = temp[tos--];
	}
	while(i>=0) {
		info[i][col] = 0;
		i--;
	}
}

int main() {
	int t, n, i, j, k, count = 0;
	char string[100];
	scanf( "%d", &t );
	while( t-- ) {
		count++;
		scanf( "%d %s", &n, string );
		for( i=0; i<n; i++) {
			for( j=0; j<n; j++) {
				scanf( "%d", &info[i][j] );
				state[i][j] = 0;
			}
		}
		if( strcmp(string, "right" ) == 0 ) {
			for( i=0; i<n; i++ ) {
				combineRight(i ,n);
			}
			for( i=0; i<n; i++ ) {
				for(j=n-1;j>0;j--){
					if( state[i][j] == 0 && state[i][j-1] == 0 ) {
						if( info[i][j] == info[i][j-1] ) {
							info[i][j] += info[i][j-1];
							info[i][j-1] = 0;
							state[i][j] = 1;
						}
					}
				}
			}
			for( i=0; i<n; i++ ) {
				combineRight(i ,n);
			}
		}
		else if( strcmp(string, "left" ) == 0 ) {
			for( i=0; i<n; i++ ) {
				combineLeft(i ,n);
			}
			for( i=0; i<n; i++ ) {
				for(j=0;j<n-1;j++){
					if( state[i][j] == 0 && state[i][j+1] == 0 ) {
						if( info[i][j] == info[i][j+1] ) {
							info[i][j] += info[i][j+1];
							info[i][j+1] = 0;
							state[i][j] = 1;
						}
					}
				}
			}
			for( i=0; i<n; i++ ) {
				combineLeft(i ,n);
			}
		}
		else if( strcmp(string, "up" ) == 0 ) {
			for( i=0; i<n; i++ ) {
				combineUp(i ,n);
			}
			for( j=0; j<n; j++ ) {
				for(i=0;i<n-1;i++){
					if( state[i][j] == 0 && state[i+1][j] == 0 && info[i][j] != 0) {
						if( info[i][j] == info[i+1][j] ) {
							info[i][j] += info[i+1][j];
							info[i+1][j] = 0;
							state[i][j] = 1;
						}
					}
				}
			}
			for( i=0; i<n; i++ ) {
				combineUp(i ,n);
			}
		}
		else {
			for( i=0; i<n; i++ ) {
				combineDown(i ,n);
			}
			for( j=0; j<n; j++ ) {
				for(i=n-1;i>0;i--){
					if( state[i][j] == 0 && state[i-1][j] == 0 ) {
						if( info[i][j] == info[i-1][j] ) {
							info[i][j] += info[i-1][j];
							info[i-1][j] = 0;
							state[i][j] = 1;
						}
					}
				}
			}
			for( i=0; i<n; i++ ) {
				combineDown(i ,n);
			}
		}
		printf( "Case #%d:\n", count );
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				printf( "%d ", info[i][j] );
			}
			printf( "\n" );
		}
	}
	return 0;
}
