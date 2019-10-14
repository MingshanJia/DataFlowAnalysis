#include<stdio.h>

#include<algorithm>
using namespace std;

typedef unsigned nat;

#define WALLSIZE (16*1024)
#define PATHSIZE (16*1024)
#define POSINF 1000000

#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3

char P[PATHSIZE], Q[PATHSIZE];
char M[WALLSIZE][WALLSIZE];

nat left, right, bottom, top, exitx, exity, exitd, entrx;

void walk(nat& x, nat& y, nat d) {
	switch (d) {
		case NORTH: --y; break;
		case WEST: --x; break;
		case SOUTH: ++y; break;
		case EAST: ++x; break;
	}
}

void turn_left(nat& d) {d = (d+1)&3;}
void turn_right(nat& d) {d = (d+3)&3;}

void examine(char *P, nat& x, nat& y, nat& d) {
	for (char *p = P; *p != '\0'; ++p) {
		switch (*p) {
			case 'W': {
				walk(x, y, d);
				if (p[1] != '\0') {
					if (x < left) left = x;
					if (x >= right) right = x+1;
					if (y >= bottom) bottom = y+1;
					if (y < top) top = y;
				}
			} break;
			
			case 'L': turn_left(d); break;
			case 'R': turn_right(d); break;
		}
	}
}

nat convert(nat d) {
	switch (d) {
		case NORTH: return 0;
		case SOUTH: return 1;
		case WEST: return 2;
		case EAST: return 3;
	}
}

void setbit(nat x, nat y, nat d) {
	d = convert(d);
	M[y][x]|= 1 << d;
}

bool inside(nat z, nat w) {
	return z < right && w < bottom;
}

void follow(char* P, nat x, nat y, nat d) {
	walk(x, y, d);
	setbit(x, y, (d+2)&3);
	for (char *p = P+1; *p != '\0'; ++p) {
		if (*p == 'W') {
			nat r = x, s = y;
			walk(r, s, d);
			setbit(x, y, d);
			if (inside(r, s)) setbit(r, s, (d+2)&3);
			walk(x, y, d);
		}
		else if (*p == 'L') {
			turn_left(d);
		}
		else {
			turn_right(d);
		}
	}
}

int main() {
	
	nat cases;
	scanf("%u", &cases);
	for (nat cs = 0; cs != cases; ++cs) {
		left = 4*POSINF;
		right = 2*POSINF;
		top = 0;
		bottom = 0;
		
		scanf("%s%s", P, Q);
		nat x = 3*POSINF, y = nat(-1), d = SOUTH;
		examine(P, x, y, d);
		exitx = x;
		exity = y;
		exitd = d = (d+2)&3;
		examine(Q, x, y, d);
		
		x = 3*POSINF - left;
		entrx = x;
		exitx-= left;
		right-= left;
		left = 0;
		
		for (nat i = 0; i != bottom; ++i) fill(M[i]+0, M[i]+right, 0);
		
		follow(P, entrx, nat(-1), SOUTH);
		follow(Q, exitx, exity, exitd);
		
		printf("Case #%u:\n", cs+1);
		for (nat i = 0; i != bottom; ++i) {
			for (nat j = 0; j != right; ++j) {
				if (M[i][j] < 10) M[i][j]+= '0';
				else M[i][j]+= 'a'-10;
			}
			M[i][right] = '\0';
			puts(M[i]);
		} 
	}
	
	return 0;
}
	
