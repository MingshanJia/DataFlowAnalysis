#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct EDGE{
	EDGE(){x = y = f = 0;}
	EDGE(int x_, int y_, int f_){x = x_; y = y_; f = f_;}
	int x,y,f;
};
EDGE EG[20000]; int E;
vector<EDGE*> FOR[20000],REV[20000];

int T,C,N,M,K,V,ST,ED; bool CHK[20000],F;
int BL,WI; char map[55][22][22]; int num[55][22][22];
queue<int> Q;

void add(int x, int y)
{
	EG[E] = EDGE(x,y,0);
	FOR[x].push_back(&EG[E]);
	REV[y].push_back(&EG[E]);
	E++;
}

void DFS(int x)
{
	if (x == ED){
		F = true; return;
	}
	
	int i,y; CHK[x] = true;
	
	for (i=0;i<FOR[x].size();i++){
		y = FOR[x][i]->y;
		if (!CHK[y] && FOR[x][i]->f == 0){
			DFS(y);
			if (F){
				FOR[x][i]->f = 1; return;
			}
		}
	}
	
	for (i=0;i<REV[x].size();i++){
		y = REV[x][i]->x;
		if (!CHK[y] && REV[x][i]->f == 1){
			DFS(y);
			if (F){
				REV[x][i]->f = 0; return;
			}
		}
	}
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i,j,k,l,x,y,u,px,py;
	
	scanf ("%d",&T); while (T--){
		scanf ("%d %d %d",&N,&M,&K);
		
		for (k=0;k<K;k++){
			for (i=0;i<N;i++) scanf ("%s",map[k][i]);
		}

		for (k=0;k<K;k++){
			for (i=0;i<N;i++) for (j=0;j<M;j++){
				if (num[k][i][j] == 0 && map[k][i][j] == '.'){
					if (k % 2 == 0) u = ++BL;
					else u = ++WI;

					Q.push(i * M + j); num[k][i][j] = u;
					while (!Q.empty()){
						x = Q.front() / M; y = Q.front() % M; Q.pop();
						for (l=0;l<4;l++){
							px = x + dx[l];
							py = y + dy[l];
							if (px < 0 || px >= N || py < 0 || py >= M) continue;
							if (num[k][px][py] == 0 && map[k][px][py] == '.'){
								Q.push(px * M + py); num[k][px][py] = u;
							}
						}
					}
				}
			}
		}

		for (k=1;k<K;k+=2) for (i=0;i<N;i++) for (j=0;j<M;j++) if (num[k][i][j]) num[k][i][j] += BL;

		for (k=0;k<K-1;k++){
			for (i=0;i<N;i++) for (j=0;j<M;j++){
				if (num[k][i][j] && num[k+1][i][j]){
					if (num[k][i][j] < num[k+1][i][j]) x = num[k][i][j], y = num[k+1][i][j];
					else x = num[k+1][i][j], y = num[k][i][j];
					for (l=0;l<FOR[x].size();l++) if (FOR[x][l]->y == y) break;
					if (l == FOR[x].size()) add(x,y);
				}
			}
		}

		V = BL + WI + 1; ST = 0; ED = V;
		for (i=1;i<=BL;i++) add(0,i);
		for (i=1;i<=WI;i++) add(i+BL,ED);
		while (1){
			for (i=0;i<=V;i++) CHK[i] = false;
			F = false; DFS(ST);
			if (!F) break;
		}
		
		int R = 0;
		for (i=0;i<REV[ED].size();i++)
			R += REV[ED][i]->f;
		
		printf ("Case #%d: %d\n",++C,BL+WI-R);

		for (k=0;k<K;k++) for (i=0;i<N;i++) for (j=0;j<M;j++) num[k][i][j] = 0;
		for (i=0;i<=V;i++){
			FOR[i].clear();
			REV[i].clear();
		}

		BL = WI = E = 0;
	}
	
	return 0;
}
