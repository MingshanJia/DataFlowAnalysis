#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
const int N = 310;
int maze[N][N];
char str[N][N];
bool visit[N][N];
int n;
int d[8][2] = {{-1,-1},{-1,0},{-1,1}, {0,-1},{0,1},{1,-1},{1,0},{1,1}};
int m = 0;
int getCount(int i, int j){
	if(str[i][j]=='*'){

		return -1;
	}
	int count = 0;
	for(int k = 0;k<8;k++){
		int ii = i+d[k][0];
		int jj = j+d[k][1];
		if(ii>=0 && ii<n && jj>=0 && jj<n && str[ii][jj]=='*'){
			count++;
		}
	}
	return count;
}
void bfs(int row, int col){
	queue<int>  qe;
	qe.push(row*n+col);
	while(!qe.empty()){
		int p = qe.front();
		qe.pop();
		int x = p/n;
		int y = p%n;
		for(int i = 0;i<8;i++){
			int xx = x+d[i][0];
			int yy = y+d[i][1];
			if(xx>=0 && xx<n && yy>=0 && yy<n && !visit[xx][yy]){
				visit[xx][yy] = true;
				if(maze[xx][yy]==0){
					qe.push(xx*n+yy);
				}
			}
		}
	}

}
int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t;
	
	scanf("%d", &t);
	for(int casenum =1;casenum<=t;casenum++){
		scanf("%d", &n);
		int ans = 0;
		for(int i = 0;i<n;i++)scanf("%s", str[i]);
		for(int i = 0;i<n;i++)
				for(int j = 0;j<n;j++){
					maze[i][j] = getCount(i,j);
				}
		//for(int i = 0;i<n;i++){
		//	printf("\n");
		//	for(int j = 0;j<n;j++){
		//		printf("%d ", maze[i][j]);
		//	}
		//}
		memset(visit, false, sizeof(visit));
		for(int i = 0;i<n;i++)
				for(int j = 0;j<n;j++){
					if(!visit[i][j] && maze[i][j]==0){
						ans++;
						visit[i][j] = true;
						bfs(i,j);
						
					}
				}
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)if(!visit[i][j] && maze[i][j]!=-1){
				ans++;
			}
		printf("Case #%d: %d\n", casenum, ans);
	}
	return 0;
}