#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define MOD 9901

int n, k;
vector <int> efrom;
vector <int> eto;

void parse() {
	cin >> n >> k;
	efrom = vector <int>(k, 0);
	eto = vector <int>(k, 0);
	for (int i = 0; i < k; i++) {
		cin >> efrom[i] >> eto[i];
	}
}

int res;

int fak2(int x) {
	int r = 1;
	for (int i = 3; i <= x; i++) {
		r = (r * i) % MOD;
	}
	return r;
}

int cmp(int bm) {
	vector <int> a;
	vector <int> b;
	vector <int> c;
	for (int i = 0; i < k; i++) {
		if (bm & (1 << i)) {
			a.push_back(efrom[i]);
			b.push_back(eto[i]);
			c.push_back(1);
		}
	}
	int p = a.size();
	int s = (p % 2 == 0) ? 1 : -1;
	for (int i = 0; i < p; i++) {
		int q = 0;
		int w = 0;
		for (int j = 0; j < p; j++) {
			if (a[j] == a[i]) q++;
			if (b[j] == a[i]) q++;
			if (a[j] == b[i]) w++;
			if (b[j] == b[i]) w++;
		}
		if (q > 2 || w > 2) return 0;
	}
	int done = 0;
	while (!done) {
		done = 1;
		for (int i = 0; i < p; i++) {
			if (!c[i]) continue;
			for (int j = i + 1; j < p; j++) {
				if (!c[j]) continue;
				if (a[i] == a[j]) {
					a[i] = b[j];
					c[i] += c[j];
					c[j] = 0;
					done = 0;
				} else if (b[i] == b[j]) {
					b[i] = a[j];
					c[i] += c[j];
					c[j] = 0;
					done = 0;
				} else if (a[i] == b[j]) {
					a[i] = a[j];
					c[i] += c[j];
					c[j] = 0;
					done = 0;
				} else if (b[i] == a[j]) {
					b[i] = b[j];
					c[i] += c[j];
					c[j] = 0;
					done = 0;
				}
			}
		}
	}
	int num = 0;
	for (int i = 0; i < p; i++) {
		if (!c[i]) continue;
		if (a[i] == b[i]) {
			if (c[i] == n) {
				return s;
			} else return 0;
		}
		num++;
	}
	if (n - p == 1) {
		assert(num == 1);
		return s;
	} else if (n - p == 2) {
		if (num < 2) return s;
		else return 2 * s;
	} else {
		assert (n - p > 2);
		if (num == 0) {
			assert(p == 0);
			return s * fak2(n - 1);
		} else {
			int r = fak2(n - p - 1);
			for (int t = 0; t < num; t++) {
				r = (r * 2) % MOD;
			}
			return s * r;
		}
	}
	assert(0);
}

void doit() {
	res = 0;
	for (int i = 0; i < (1 << k); i++) {
		int bits = 0;
		for (int j = 1; j < (1 << k); j *= 2) {
			if (i & j) bits++;
		}
		res += cmp(i);
		res = ((res % MOD) + MOD) % MOD;
	}
	res = res % MOD;
	while (res < 0) res += MOD;
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

