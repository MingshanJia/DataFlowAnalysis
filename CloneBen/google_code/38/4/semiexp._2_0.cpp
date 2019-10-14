#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int C;
int E[1010][2], L[1010][2], D[1010][2];

int trans(int t, int l, int d)
{
	if (t % 24 <= l) {
		return t / 24 * 24 + l + d;
	}
	return (t / 24 + 1) * 24 + l + d;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d", &C);

		for (int i = 0; i < 2 * C; ++i) {
			scanf("%d%d%d", &(E[i / 2][i % 2]), &(L[i / 2][i % 2]), &(D[i / 2][i % 2]));
			--E[i / 2][i % 2];
		}

		int ret = 2100000000;
		for (int m = 0; m < (1 << C); ++m) {
			int nvis[16];
			for (int i = 0; i < C; ++i) nvis[i] = 0;
			int loc = 0, t = 0;
			for (int i = 0; i < 2 * C; ++i) {
				if (nvis[loc] >= 2) goto fail;
				int mode = nvis[loc] ^ ((m >> loc) & 1);
				++nvis[loc];
				t = trans(t, L[loc][mode], D[loc][mode]);
				loc = E[loc][mode];
			//	printf("%d ", loc);
			}
			ret = min(ret, t);
		fail:
			//puts("");
			continue;
		}
		printf("Case #%d: %d\n", t, ret);
	}

	return 0;
}
