#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;

const int MAX_N = 1010;
int dp[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
int dir[4][2] = {
	-1, 0, 
	0, 1,
	1, 0,
	0, -1
};

int n;
int gaodp(int x, int y){
	//if(x <= 0 || y <= 0 || x >= n + 1 || y >= n + 1) return 0;
	//cerr<<" x = "<<x<<" y = "<<y<<endl;
	if(dp[x][y] != -1) return dp[x][y];
	int ans = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if(nx <= 0 || ny <= 0 || nx >= n + 1 || ny >= n + 1) continue;
		if(a[nx][ny] == a[x][y] + 1)
			ans = max(ans, 1 + gaodp(nx, ny));
	}
	return dp[x][y] = ans;
}

int main() {
	int T, icase = 1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				scanf("%d", &a[i][j]);
				dp[i][j] = -1;
			}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				gaodp(i, j);
		int room = 1<<30, step = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				//cerr<<"dp[i][j] = "<<dp[i][j]<<endl;
				if(dp[i][j] > step || dp[i][j] == step && a[i][j] < room){
					room = a[i][j];
					step = dp[i][j];
				}
			}
		printf("Case #%d: %d %d\n", icase++, room, step);
	}
	return 0;
}
