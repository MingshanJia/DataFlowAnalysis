#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 300
int n, m;
char s[100];
int mat[N][N], a[N][N];

void rot(int x){
	if (x != 1) rot(x - 1);
	int b[N][N];
	FOR(i,0,n) FOR(j,0,n) b[i][j] = mat[j][n - 1 - i];
	FOR(i,0,n) FOR(j,0,n) mat[i][j] = b[i][j];
}

void move(){	
	FOR(i,0,n) FOR(j,0,n){
		if (!mat[i][j]) continue;
		for (int k = i - 1; k >= 0; k--){
			if (mat[k][j] == 0) swap(mat[k][j], mat[k + 1][j]);
			if (a[k][j]) break;
			if (mat[k][j] == mat[k + 1][j]){
				a[k][j] = 1;
				mat[k][j] <<= 1;
				mat[k + 1][j] = 0;
				break;
			}
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		memset(a, 0, sizeof(a));
		printf("Case #%d:\n", cc);
		scanf("%d%s", &n, s);
		FOR(i,0,n) FOR(j,0,n) scanf("%d", &mat[i][j]);
		if (s[0] == 'u') move();
		else if (s[0] == 'r'){
			rot(1);
			move();
			rot(3);
		}
		else if (s[0] == 'd'){
			rot(2);
			move();
			rot(2);
		}
		else if (s[0] == 'l'){
			rot(3);
			move();
			rot(1);
		}
		FOR(i,0,n) FOR(j,0,n)
			printf("%d%c", mat[i][j], j == n - 1 ? '\n' : ' ');
	}
	return 0;
}
