#include <cstdio>
#include <vector>

using namespace std;

long long mem[101][101];

long long go(int D, int B) {
	long long &res = mem[D][B];
	if (res >= -1) return res;
	if (D == 0 || B == 0) return res = 0;

	long long nb = go(D-1, B), b = go(D-1, B-1);
	if (nb < 0 || b < 0) return res = -1;
	res = 1 + nb + b;
	if (res >= 4294967296LL) res = -1;
	return res;
}

void doCase(int cn, int f, int d, int b) {
	go(d, b);

	//for (int D = 0; D <= 100; D++) for (int B = 0; B <= 100; B++)
	//	printf("mem[%d][%d] = %lld\n", D, B, mem[D][B]);

	printf("Case #%d: ", cn);

	int nb = 0, nd = 0;
	while (mem[d][nb] < f) nb++;
	while (mem[nd][b] < f) nd++;

	printf("%lld %d %d\n", mem[d][b], nd, nb);
}

int main() {
	int N;
	scanf("%d", &N);

	memset(mem, 0x80, sizeof(mem));
	for (int D = 100; D >= 1; D--) for (int B = 100; B >= 1; B--)
		go(D, B);

	for (int i = 0; i < N; i++) {
		int f, d, b;
		scanf(" %d %d %d", &f, &d, &b);
		doCase(i+1, f, d, b);
	}
	return 0;
}

