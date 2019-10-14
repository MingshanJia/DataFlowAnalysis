#include <cstdio>

const char digits[][8] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char tuples[][16] = {"", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};

int T, cur, off, x, t;
char s[256], format[256];

void out(int p, int n) {
	char pre = 0;
	int cnt = 0;
	for (int i = p; i < p + n; ++i)
		if (s[i] == pre) ++cnt;
		else {
			if (cnt) {
				if (cnt == 1) printf(" %s", digits[pre - '0']);
				else if (2 <= cnt && cnt <= 10) printf(" %s %s", tuples[cnt], digits[pre - '0']);
				else for (int j = 0; j < cnt; ++j) printf(" %s", digits[pre - '0']);
			}
			pre = s[i];
			cnt = 1;
		}
	if (cnt) {
		if (cnt == 1) printf(" %s", digits[pre - '0']);
		else if (2 <= cnt && cnt <= 10) printf(" %s %s", tuples[cnt], digits[pre - '0']);
		else for (int j = 0; j < cnt; ++j) printf(" %s", digits[pre - '0']);
	}
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%s%s", &s, &format);
		printf("Case #%d:", r);
		cur = 0; off = -1;
		do {
			++off;
			sscanf(format + off, "%d%n", &x, &t);
			off += t;
			out(cur, x);
			cur += x;
		} while (format[off] == '-');
		puts("");
	}
	return 0;
}
