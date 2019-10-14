#include <bits/stdc++.h>
using namespace std;

int rk[666];

bool cmp(string s1, string s2) {
	int len = min(s1.size(), s2.size());
	for (int i = 0; i < len; ++i) {
		if (s1[i] != s2[i]) {
			return s1[i] < s2[i];
		}
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out_small.txt", "w", stdout);
#endif // LOCAL
	int t, n, cas = 0;
	string str;
	scanf("%d", &t);
	rk[' '] = 0;
	for (char c = 'a'; c <= 'z'; ++c) {
		rk[c] = 233 + c - 'a';
		rk[c + 'A' - 'a'] = 66 + c - 'A';
	}
	while (t-- && scanf("%d", &n)) {
		getchar();
		vector<string> vs;
		int cot = 0;
		for (int i = 0; i < n; ++i) {
			getline(cin, str);
			if (i && cmp(str, vs[vs.size() - 1])) {
				++cot;
			}
			vs.push_back(str);
			sort(vs.begin(), vs.end(), cmp);
		}
		printf("Case #%d: %d\n", ++cas, cot);
	}
	return 0;
}
