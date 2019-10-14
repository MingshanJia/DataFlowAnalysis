#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define DEBUG_FLAG 0
#if DEBUG_FLAG
#define dbg(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define cdbg(...) cerr << __VA_ARGS__ << endl
#else
#define debug(r)
#define dbg(...)
#endif

int main() {
	string fname = "C-large";
	freopen((fname+".in").c_str(), "r", stdin);
	freopen((fname+".out").c_str(), "w", stdout);
	int K;
	scanf("%d", &K);
	for (int c = 1; c <= K; ++c) {
		int P, C;
		scanf("%d%d", &P, &C);
		vector<long long> arr(P);
		for (int i = 0; i < P; ++i){
			scanf("%lld", &arr[i]);
		}
		long long s = 0;
		sort(arr.begin(), arr.end());
		int u = arr.size() - C;
		for (int i = 0; i < u; ++i)
			s += arr[i];
		while (true) {
			int j;
			for (j = u; j < P; ++j) {
				if (arr[j] != arr[u]) break;
			}
			if (j == P) {
				arr[u] += s/(j-u);
				break;
			}
			long long toadd = min(arr[j]-arr[u], s/(j-u));
			dbg(toadd);
			for (int i = u; i < j; ++i) {
				s -= toadd;
				arr[i] += toadd;
				dbg(s);
			}
			if (s < j-u+1) break;
		}
		printf("Case #%d: %lld\n", c, arr[u]);
	}

	return 0;
}
