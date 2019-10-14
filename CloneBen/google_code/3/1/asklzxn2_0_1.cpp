#include <cstdio>
#include <cstring>

int T, n;
char s[305];
int f[305];
int fail[305];
int g[305];
int h[305];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int Cas = 1; Cas <= T; ++Cas) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 0; i <= n; ++i)
			f[i] = i;
		for (int i = 0; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j)
				if (f[i] + j - i < f[j])
					f[j] = f[i] + j - i;
			fail[i + 1] = i;
			for (int j = i + 2; j <= n; ++j) {
				int k;
				for (k = fail[j - 1]; k != i && s[k + 1] != s[j]; k = fail[k]);
				if (s[k + 1] == s[j]) fail[j] = k + 1;
				else fail[j] = i;
			}
			int maxk = i;
			for (int j = 1, k = i; j <= i; ++j) {
				for (; k != i && s[k + 1] != s[j]; k = fail[k]);
				if (s[k + 1] == s[j]) ++k;
				else k = i;
				if (k > maxk) maxk = k;
			}
			for (int j = i + 1; j <= maxk; ++j) {
				for (int k = i;	k <= n; ++k)
					g[k] = 0, h[k] = 0;
				for (int k = i + 1, l = i; k <= n; ++k) {
					for (; l != i && s[l + 1] != s[k]; l = fail[l]);
					if (s[l + 1] == s[k]) ++l;
					else l = i;
					if (l == j) {
						g[k] = 1;
						l = fail[l];
					}
				}
				for (int k = i + 1; k <= n; ++k) {
					if (h[k - 1] > h[k]) h[k] = h[k - 1];
					if (g[k] && k >= j) {	
						if (h[k - (j - i)] + 1 > h[k])
							h[k] = h[k - (j - i)] + 1;
					}
					if (h[k] + 1 + (k - i - h[k] * (j - i)) + f[i] < f[k])
						f[k] = h[k] + 1 + (k - i - h[k] * (j - i)) + f[i];
				}
			}
		}
		printf("Case #%d: %d\n", Cas, f[n]);
	}
	return 0;
}
