#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAX_NODE 10000
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int num_room;
vector < set < int > > Overlap;
bool is_left[MAX_NODE];
char Room[50][20][22];
int Room_idx[50][20][20];

int Pair[MAX_NODE];

int b_match(int x) {
	for (set < int >::iterator it = Overlap[x].begin(); it != Overlap[x].end(); it++) {
		if (Pair[*it] == -1) {
			Pair[*it] = x;
			Pair[x] = *it;
			return 1;
		}
	}
	for (set < int >::iterator it = Overlap[x].begin(); it != Overlap[x].end(); it++) {
		if (Pair[*it] != x && b_match(Pair[*it])) {
			Pair[x] = *it;
			Pair[*it] = x;
			return 1;
		}
	}	
	return 0;
}

int match(void) {
	for (int i = 0; i < num_room; i++) {
		Pair[i] = -1;
	}
	
	int ret = 0;
	for (int i = 0; i < num_room; i++) {
		if (is_left[i] && Pair[i] == -1) {
			ret += b_match(i);
		}
	}
	return ret;
}

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	
	for (int testcase = 1; testcase <= testnum; testcase++) {
		int ans = 0;
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		
		num_room = 0;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%s", Room[i][j]);
				for (int k = 0; k < M; k++) {
					if (Room[i][j][k] == '#')
						Room_idx[i][j][k] = -1;
					else
						Room_idx[i][j][k] = 0;
				}
			}
		}
		
		// Extract nodes
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (Room_idx[i][j][k]) 
						continue;
						
					queue < pair <int, int> > Q;
					Q.push(make_pair(j, k));
					num_room++;
					Room_idx[i][j][k] = num_room;
					
					while(!Q.empty()) {
						pair <int, int> x = Q.front();
						Q.pop();
						
						for (int w = 0; w < 4; w++) {
							int wy = x.first + dy[w];
							int wx = x.second + dx[w];
							if (0 <= wy && wy < N && 0 <= wx && wx < M && Room_idx[i][wy][wx] == 0) {
								Room_idx[i][wy][wx] = num_room;
								Q.push(make_pair(wy, wx));
							}
						}						
					}
				}
			}
		}

/*		
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < N; j++) {
				for ( int k = 0; k < M; k++) {
					printf("%d ", Room_idx[i][j][k] - 1);
				}
				printf("\n");
			}
			printf("\n");
		}
*/

		// Build a graph
		
		Overlap.resize(num_room);
		for (int i = 0; i < num_room; i++) {
			Overlap[i].clear();
			is_left[i] = false;
		}
		
		for (int i = 0; i < K - 1; i++) {			
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (Room_idx[i][j][k] != Room_idx[i + 1][j][k] && Room_idx[i][j][k] > 0 && Room_idx[i + 1][j][k] > 0) {
						Overlap[Room_idx[i][j][k] - 1].insert(Room_idx[i + 1][j][k] - 1);
						Overlap[Room_idx[i + 1][j][k] - 1].insert(Room_idx[i][j][k] - 1);
					}
					if (Room_idx[i][j][k] > 0 && i % 2 == 0) {
						is_left[Room_idx[i][j][k] - 1] = true;
					}
				}
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (Room_idx[K - 1][j][k] > 0 && (K - 1) % 2 == 0) {
					is_left[Room_idx[K - 1][j][k] - 1] = true;
				}
			}
		}
		
		
/*
		for (int i = 0; i < num_room; i++) {
			printf("#%d: is_left? %d\n", i, is_left[i]);
			for (set < int >::iterator it = Overlap[i].begin(); it != Overlap[i].end(); it++) {
				printf("%d ", *it);
			}
			printf("\n");
		}
*/
		ans = match();
		printf("Case #%d: %d\n", testcase, num_room - ans);
	}
	return 0;
}