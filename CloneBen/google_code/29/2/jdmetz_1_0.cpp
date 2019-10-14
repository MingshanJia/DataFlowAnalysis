#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void mark(vector<string> &m, int x, int y, int d) {
	m[y][x] &= ~(1<<d);

//printf("mark %d,%d -> %d\n", x, y, (int)m[y][x]);

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int xp = x+dx[d], yp = y+dy[d];
	m[yp][xp] &= ~(1<<((d+2)%4));
}

void writeMaze(int cn, string no, string on) {
	printf("Case #%d:\n", cn);
	if (no.size() == 2 && on.size() == 2) {
		printf("3\n");
		return;
	}
	vector<string> m(10003, string(20005, (char)15));

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int mxy = 1, mnx = 10002, mxx = 10002;
	int x = 10002, y = 1, d = 0;

	char pd = 'W';
	for (int i = 1; i < no.size(); i++) {
		int iy = y, ix = x;
		switch (no[i]) {
		case 'L': d = (d+1)%4; break;
		case 'W':
			if (pd != 'L') mark(m, x, y, (d+1)%4);
			y += dy[d]; x += dx[d]; break;
		case 'R':
			mark(m, x, y, (d+1)%4);
			mark(m, x, y, d);
			d = (d+3)%4; break;
		}
		if (i+1 == no.size()) {
			x = ix; y = iy;
			break;
		}
		pd = no[i];
//printf("At %d,%d facing %d (%d, %d -> %d)\n", x, y, d, ix, iy, (int)m[iy][ix]);
		if (y > mxy) mxy = y;
		if (x < mnx) mnx = x;
		if (x > mxx) mxx = x;
	}
//printf("Left maze\n");

	d = (d+2)%4;
	pd = 'W';
	for (int i = 1; i < on.size(); i++) {
		int iy = y, ix = x;
		switch (on[i]) {
		case 'L': d = (d+1)%4; break;
		case 'W':
			if (pd != 'L') mark(m, x, y, (d+1)%4);
			y += dy[d]; x += dx[d]; break;
		case 'R':
			mark(m, x, y, (d+1)%4);
			mark(m, x, y, d);
			d = (d+3)%4; break;
		}
		if (i+1 == on.size()) {
			x = ix; y = iy;
			break;
		}
		pd = on[i];
//printf("At %d,%d facing %d (%d, %d -> %d)\n", x, y, d, ix, iy, (int)m[iy][ix]);
		if (y > mxy) mxy = y;
		if (x < mnx) mnx = x;
		if (x > mxx) mxx = x;
	}

/*		SENW
	0	0000	0000
	1	1000	0100
		0100	0001
		1100	0101
		0010	1000
		1010	1100
		0110	1001
		1110	1101
		0001	0010
*/
	char dig[17] = "028a139b46ce57df";
/*	for (int y = 1; y <= mxy; y++) {
for (int j = mnx; j <= mxx; j++) printf("+%c+", m[y][j]&4 ? ' ' : '-'); printf("\n");
for (int j = mnx; j <= mxx; j++) printf("%c %c", m[y][j]&8 ? ' ' : '|', m[y][j]&2 ? ' ' : '|'); printf("\n");
for (int j = mnx; j <= mxx; j++) printf("+%c+", m[y][j]&1 ? ' ' : '-'); printf("\n");
	}*/
	for (int y = 1; y <= mxy; y++) {
		for (int x = mnx; x <= mxx; x++) m[y][x] = dig[m[y][x]];
		m[y].resize(mxx+1);
		printf("%s\n", m[y].c_str()+mnx);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char sz[10001], sz2[10001];
		scanf(" %10000s %10000s", sz, sz2);
		writeMaze(i+1, sz, sz2);
	}
	return 0;
}

