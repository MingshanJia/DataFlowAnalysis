#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(i=a;i<=b;i++)
#define FD(i,a, b) for(i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 100000000
#define MAXN ?
#include<map>
#define MAXE ?
#define pb push_back
#define ll long long
#include<vector>
#define mod 1000000007LL
using namespace std;
int i, j, k, N, M, K, a[1000][1000], v[1000][1000];
char str[10], t[10][10] = {"right", "left", "up", "down"};
void nextpos(int x, int y, int t){
	int i, j, k, fg = 0;
	//printf("%d %d\n", x, y);
	if(t == 0){
		FI(i, y + 1, N){
			if(a[x][i]){
				if(v[x][i] == 0){
					if(a[x][i] == a[x][y]) a[x][i] *= 2, a[x][y] = 0, v[x][i] = 1, fg = 1;
				}
				break;
			}
			//printf("i = %d\n", i);
		}
		if(!fg){
			//printf("fg (%d, %d)\n", x, i - 1);
			a[x][i - 1] = a[x][y];
			if(i - 1 != y) a[x][y] = 0;
		}
	}else if(t == 1){
		FD(i, y - 1, 1){
			if(a[x][i]){
				if(v[x][i] == 0){
					if(a[x][i] == a[x][y]) a[x][i] *= 2, a[x][y] = 0, v[x][i] = 1, fg = 1;
				}
				break;
			}
			//printf("i = %d\n", i);
		}
		if(!fg){
			//printf("fg (%d, %d)\n", x, i - 1);
			a[x][i + 1] = a[x][y];
			if(i + 1 != y) a[x][y] = 0;
		}
	
	}else if(t == 2){
		FD(i, x - 1, 1){
			if(a[i][y]){
				if(v[i][y] == 0){
					if(a[i][y] == a[x][y]) a[i][y] *= 2, a[x][y] = 0, v[i][y] = 1, fg = 1;
				}
				break;
			}
		}
		if(!fg){
			//printf("%d %d\n", i + 1, y);
			a[i + 1][y] = a[x][y];
			if(i + 1 != x) a[x][y] = 0;
		}
	
	}else if(t == 3){
		FI(i, x + 1, N){
			if(a[i][y]){
				if(v[i][y] == 0){
					if(a[i][y] == a[x][y]) a[i][y] *= 2, a[x][y] = 0, v[i][y] = 1, fg = 1;
				}
				break;
			}
		}
		if(!fg){
			//printf("%d %d\n", i + 1, y);
			a[i - 1][y] = a[x][y];
			if(i - 1 != x) a[x][y] = 0;
		}
	
	}
}
int main(){
	scanf("%d", &K);
	FI(k, 1, K){
		CL(v, 0);
		scanf("%d%s", &N, str);
		FI(i, 0, 3) if(strcmp(str, t[i]) == 0) M = i;
		FI(i, 1, N) FI(j, 1, N) scanf("%d", &a[i][j]);
		if(M == 0){
			FI(i, 1, N){
				FD(j, N, 1){
					nextpos(i, j, M);
				}
			}
		}else if(M == 1){
			FI(i, 1, N){
				FI(j, 1, N){
					nextpos(i, j, M);
				}
			}
		
		}else if(M == 2){
			FI(i, 1, N){
				FI(j, 1, N){
					nextpos(i, j, M);
				}
			}
		
		}else{
			FD(i, N, 1){
				FI(j, 1, N){
					nextpos(i, j, M);
				}
			}
		
		}
		printf("Case #%d: \n", k);
		FI(i, 1, N) FI(j, 1, N) printf("%d%c", a[i][j], j == N ? '\n' : ' ');
		//printf("%d\n", M);
	}	
}
