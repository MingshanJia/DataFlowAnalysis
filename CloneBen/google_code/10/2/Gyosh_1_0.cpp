#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

#define EPS 1e-8
#define INF 1023123123
#define LL long long
#define __ puts("")

#define MAXN 25

using namespace std;

// U L D R

int N,T;
int dir;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int m[MAXN][MAXN];
bool freeze[MAXN][MAXN];

bool inside(int a){
	return (0 <= a) && (a < N);
}

void move(int i, int j, int di, int dj){
	int val = m[i][j];
	m[i][j] = 0;

//	printf("moving... %d %d [%d %d]\n", i, j, di, dj);

	i += di;
	j += dj;
	while ((m[i][j] == 0) && inside(i) && inside(j)) {
		i += di;
		j += dj;
	}

//	printf("stop in %d %d\n", i, j);

	if (inside(i) && inside(j)){
		// possibly colliding
		if ((m[i][j] == val) && !freeze[i][j]){
			// merged
			m[i][j] = 2*val;
			freeze[i][j] = 1;
//			printf("merged\n");
		}else{
			// don't collide
			i -= di;
			j -= dj;
			m[i][j] = val;
//			printf("collide\n");
		}
	}else{
		// must be out of bound
		i -= di;
		j -= dj;
		m[i][j] = val;
//		printf("bound\n");
	}
}

void slide(int stRow, int stCol, int dRow, int dCol){
//	printf("--> %d %d %d %d\n", stRow, stCol, dRow, dCol);
	RESET(freeze, 0);

	if (dir & 1){
		// horizontal
		int nowCol = stCol;
		while (inside(nowCol)){
			REP(i,N){
				if (m[i][nowCol] != 0){
					move(i, nowCol, 0, -dCol);
				}
			}

			nowCol += dCol;
		}
	}else{
		// vertical
		int nowRow = stRow;
		while (inside(nowRow)){
			REP(i,N){
				if (m[nowRow][i] != 0){
					move(nowRow, i, -dRow, 0);
				}
			}

			nowRow += dRow;
		}
	}
}

int main(){
	scanf("%d", &T);
	REP(jt,T){
		char command[10];
		scanf("%d %s", &N, command);

		REP(i,N){
			REP(j,N){
				scanf("%d", &m[i][j]);
			}
		}

		if (command[0] == 'u'){
			dir = 0;
			slide(0, 0, 1, 0);
		}else if (command[0] == 'l'){
			dir = 1;
			slide(0, 0, 0, 1);
		}else if (command[0] == 'd'){
			dir = 2;
			slide(N-1, 0, -1, 0);
		}else if (command[0] == 'r'){
			dir = 3;
			slide(0, N-1, 0, -1);
		}

		printf("Case #%d:\n", jt+1);
		REP(i,N){
			REP(j,N){
				printf("%d", m[i][j]);

				if (j+1 < N) printf(" ");
			}
			printf("\n");		
		}
	}	
}
