#include <bits/stdc++.h>
using namespace std;
const int maxn = 301;
set<string> Hash;
int t, n, f[maxn];
char buf[maxn + 2];
inline string getSub(int L, int R) {
	char ch = buf[R];
	buf[R] = '\0';
	string ret = buf + L;
	buf[R] = ch;
	return ret;
}
int main() {
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s", buf);
		n = strlen(buf);
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		set<string>().swap(Hash);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < i; ++j)
				Hash.insert(getSub(j, i));
			f[i + 1] = min(f[i + 1], f[i] + 1);
			for(int j = 1; j <= i && j <= n - i; ++j) {
				int L = i, R = L + j;
				string cur = getSub(L, R);
				if(!Hash.count(cur))
					continue;
				for(int c = 2; R <= n; L += j, R += j, ++c) {
					string nxt = getSub(L, R);
					if(cur == nxt)
						f[R] = min(f[R], f[i] + c);
					else
						break;
				}
			}
		}
		printf("Case #%d: %d\n", Case, f[n]);
	}
	return 0;
}
