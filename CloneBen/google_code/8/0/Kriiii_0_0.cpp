#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N,P[90009];
char S[303][303]; int C[303][303];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int find(int x)
{
	if (P[x] != x) P[x] = find(P[x]);
	return P[x];
}

int main()
{
	freopen ("1.in","r",stdin);
	freopen ("1.out","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		int click = 0;
		scanf ("%d",&N);
		for (int i=0;i<N;i++){
			scanf ("%s",S[i]);
			for (int j=0;j<N;j++){
				P[i*N+j] = i*N+j;
			}
		}

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++) if (S[i][j] == '.'){
				int cnt = 0;
				for (int k=0;k<8;k++){
					int x = i + dx[k], y = j + dy[k];
					if (x < 0 || x >= N || y < 0 || y >= N) continue;
					if (S[x][y] == '*') cnt++;
				}
				C[i][j] = cnt;
			}
		}

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++) if (S[i][j] == '.' && C[i][j] == 0){
				queue<pair<int, int> > Q;
				click++;
				Q.push(make_pair(i,j)); S[i][j] = '*';
				while (!Q.empty()){
					int i = Q.front().first, j = Q.front().second; Q.pop();

					if (C[i][j]) continue;
					for (int k=0;k<8;k++){
						int x = i + dx[k], y = j + dy[k];
						if (x < 0 || x >= N || y < 0 || y >= N) continue;
						if (S[x][y] == '.'){
							Q.push(make_pair(x,y)); S[x][y] = '*';
						}
					}
				}
			}
		}
		for (int i=0;i<N;i++) for (int j=0;j<N;j++) if (S[i][j] == '.') click++;

		printf ("%d\n",click);
	}

	return 0;
}