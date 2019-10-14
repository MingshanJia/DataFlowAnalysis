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

#define DEBUG_FLAG 1
#if DEBUG_FLAG
#define dbg(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define cdbg(...) cerr << __VA_ARGS__ << endl
#else
#define debug(r)
#define dbg(...)
#endif

typedef pair<int, int> pii;
pii e[1024];
int arr[1024];
int ans[1024];

int main() {
	string fname = "B-small-attempt0";
	freopen((fname+".in").c_str(), "r", stdin);
	freopen((fname+".out").c_str(), "w", stdout);
	int K;
	scanf("%d", &K);
	for (int u = 1; u <= K; ++u) {
		int N, T, E;
		scanf("%d%d%d", &N, &T, &E);
		int h, c;
		for (int i = 0; i < E; ++i){
			scanf("%d%d", &h, &c);
			--h;
			e[i] = make_pair(h, -c);
		}
		--T;
		sort(e, e+E);
		memset(arr, 0, sizeof(arr));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < E; ++i) {
			if (e[i].first != T)
				++arr[e[i].first];
		}
		for (int i = 0; i < E; ++i) {
			if (arr[e[i].first] > 0) {
				arr[e[i].first] += e[i].second;
				++ans[e[i].first];
			}
		}
		bool can = true;
		for (int i = 0; i < E; ++i) {
			if (arr[e[i].first] > 0) can = false;
		}
		if (can) {
			printf("Case #%d:", u);
			for (int i = 0; i < N; ++i)
				printf(" %d", ans[i]);
			printf("\n");
		} else {
			printf("Case #%d: IMPOSSIBLE\n", u);
		}
	}

	return 0;
}
