#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define max(x,y) (x>y?(x):(y))
#define min(x,y) (x<y?(x):(y))
#define ADD_Y 5

int mino_x[7][4][4] =
{
	{{0, 0, 1, 1}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}},
	{{0, 0, 1, 1}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}},
	{{0, 0, 0, 1}, {0, 1, 2, 2}, {0, 1, 1, 1}, {0, 0, 1, 2}},
	{{0, 1, 1, 1}, {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}},
	{{0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}},
	{{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 2, 3}},
	{{0, 1, 1, 2}, {0, 1, 1, 1}, {0, 1, 1, 2}, {0, 0, 0, 1}}
};
int mino_y[7][4][4] =
{
	{{1, 2, 0, 1}, {0, 0, 1, 1}, {1, 2, 0, 1}, {0, 0, 1, 1}},
	{{0, 1, 1, 2}, {1, 0, 1, 0}, {0, 1, 1, 2}, {1, 0, 1, 0}},
	{{0, 1, 2, 0}, {0, 0, 0, 1}, {2, 0, 1, 2}, {0, 1, 1, 1}},
	{{0, 0, 1, 2}, {1, 1, 0, 1}, {0, 1, 2, 2}, {0, 1, 0, 0}},
	{{0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}},
	{{0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 0, 0}},
	{{0, 0, 1, 0}, {1, 0, 1, 2}, {1, 0, 1, 1}, {0, 1, 2, 1}}
};


bool map[101][101+ADD_Y];

bool check(int* x, int* y, int h){
	for(int i=0; i<4; ++i){
		if(y[i] == 0 || (y[i]-1 < h && map[x[i]][y[i]-1])) return false;
	}
	return true;
}
/*
bool outside(int w, int h){
	for(int j=h; j<h+ADD_Y; ++j){
		for(int i=0; i<w; ++i){
			if(map[i][j]) return true;
		}
	}
	return false;
}*/
bool outside(int* x, int* y, int h){
	for(int i=0; i<4; ++i){
		if(y[i] >= h) return true;
	}
	return false;
}
void lineClear(int w, int h){
	int move = 0, cnt;
	for(int j=0; j<h+ADD_Y; ++j){
		cnt = 0;
		for(int i=0; i<w; ++i){
			if(map[i][j]) cnt++;
		}
		if(cnt == w) move++;
		else{
			for(int i=0; i<w; ++i) map[i][j-move] = map[i][j];
		}
	}
	for(int j=h+ADD_Y-move; j<h+ADD_Y; ++j){
		for(int i=0; i<w; ++i) map[i][j] = false;
	}
}
void printMap(int w, int h){
	for(int j=h-1; j>=0; --j){
		for(int i=0; i<w; ++i) printf("%c", map[i][j]? 'x' : '.');
		printf("\n");
	}
}

int main(){
	int T;
	int w, h, n;
	int t, r, x;
	int now_x[4], now_y[4];
	bool over;
	scanf("%d", &T);
	for(int tt=1; tt<=T; ++tt){
		scanf("%d%d%d", &w, &h, &n);
		for(int i=0; i<w; ++i){
			for(int j=0; j<h+ADD_Y; ++j) map[i][j] = false;
		}
		over = false;
		for(int i=0; i<n; ++i){
			scanf("%d%d%d", &t, &r, &x);
			if(over) continue;
			for(int j=0; j<4; ++j){
				now_x[j] = mino_x[t-1][r][j] + x;
				now_y[j] = mino_y[t-1][r][j] + h;
			}
			while(check(now_x, now_y, h)){
				for(int j=0; j<4; ++j) now_y[j]--;
			}
			// for(int j=0; j<4; ++j) printf("(%d %d)\n", now_x[j], now_y[j]);

			if(outside(now_x, now_y, h)) over = true;
			else{
				for(int j=0; j<4; ++j){
					map[now_x[j]][now_y[j]] = true;
				}
				lineClear(w, h);
			}
			// if(outside(w, h)) over = true;
			
			// printMap(w, h);
			// printf("=======\n");
		}
		printf("Case #%d:\n", tt);
		if(over) printf("Game Over!\n");
		else printMap(w, h);
	}
	return 0;
}

