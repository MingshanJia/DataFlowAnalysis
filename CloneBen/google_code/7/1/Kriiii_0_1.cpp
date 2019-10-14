#include <stdio.h>
#include <algorithm>
using namespace std;

int x[1000001],y[1000001];
int N,c[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
	freopen ("1.in","r",stdin);
	freopen ("1.out","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);
		scanf ("%d",&N);
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				int p; scanf ("%d",&p);
				x[p] = i; y[p] = j;
				c[i][j] = 0;
			}
		}

		int room,cnt=0;
		for (int i=N*N;i>=1;i--){
			int r = 0;
			for (int k=0;k<4;k++){
				int px = x[i] + dx[k];
				int py = y[i] + dy[k];
				if (px < 0 || px >= N || py < 0 || py >= N) continue;
				if (r < c[px][py])
					r = c[px][py];
			}
			r++;
			c[x[i]][y[i]] = r;
			if (i < N*N){
				c[x[i+1]][y[i+1]] = 0;
			}
			if (cnt < r || (cnt == r && room > i)){
				cnt = r; room = i;
			}
		}

		printf ("%d %d\n",room,cnt);
	}

	return 0;
}