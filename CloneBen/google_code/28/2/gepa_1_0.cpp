#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int n;
int k;
vector <int> x;
vector <int> y;

int res;

void parse() {
	cin >> n >> k;
	x = vector <int>(n, 0);
	y = vector <int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
}

int buf[70000][20];
int b2[70000];

int g(int bm) {
	if (b2[bm] >= 0) return b2[bm];
	if (bm == 0) return 0;
	int xmin = 100000;
	int ymin = 100000;
	int xmax = 0;
	int ymax = 0;
	for (int i = 0; i < n; i++) {
		if ((1 << i) & bm) {
			if (x[i] < xmin) xmin = x[i];
			if (x[i] > xmax) xmax = x[i];
			if (y[i] < ymin) ymin = y[i];
			if (y[i] > ymax) ymax = y[i];
		}
	}
	int dx = xmax - xmin;
	int dy = ymax - ymin;
	if (dx > dy) b2[bm] = dx;
	else b2[bm] = dy;
	return b2[bm];
}

int calc(int bm, int r) {
	if (buf[bm][r] >= 0) return buf[bm][r];
	if (bm == 0) {
		return 0;
	}
	if (r == 1) {
		buf[bm][r] = g(bm);
		return buf[bm][r];
	}
	int amin = -1;
	for (int i = 1; i < (1 << n); i++) {
		if ((i & bm) != i) continue;
		int a = max(g(i), calc(bm ^ i, r - 1));
		if (amin == -1 || a < amin) {
			amin = a;
		}
	}
	buf[bm][r] = amin;
	return amin;
}

void doit() {
	for (int i = 0; i < 70000; i++) {
		b2[i] = -1;
		for (int j = 0; j < 20; j++) {
			buf[i][j] = -1;
		}
	}
	res = calc((1 << n) - 1, k);
}

void printResult() {
	printf("%d\n", res);
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parse();
		doit();
		printf("Case #%d: ", i);
		printResult();
	}
	return 0;
}

