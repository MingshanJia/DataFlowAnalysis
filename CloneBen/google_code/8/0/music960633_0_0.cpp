#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define max(x,y) (x>y?(x):(y))
#define min(x,y) (x<y?(x):(y))

char map[301][301];
int num[301][301];
bool visit[301][301];

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int calc(int x, int y, int n){
	int tx, ty, ret = 0;
	if(map[x][y] == '*') return -1;
	for(int i=0; i<8; ++i){
		tx = x + dx[i];
		ty = y + dy[i];
		if(tx >= 0 && tx < n && ty >= 0 && ty < n && map[tx][ty] == '*') ret++;
	}
	return ret;
}
void dfs(int x, int y, int n){
	visit[x][y] = true;
	if(num[x][y] > 0) return;
	int tx, ty;
	for(int i=0; i<8; ++i){
		tx = x + dx[i];
		ty = y + dy[i];
		if(tx >= 0 && tx < n && ty >= 0 && ty < n && num[tx][ty] >=0 && !visit[tx][ty]) dfs(tx, ty, n);
	}
}

int main(){
	int T, n;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%s", map[i]);
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j) num[i][j] = calc(i, j, n);
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j) visit[i][j] = false;
		}
		
		int ans = 0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(!visit[i][j] && num[i][j] == 0){
					dfs(i, j, n);
					ans++;
				}
			}
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(!visit[i][j] && num[i][j] > 0) ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

