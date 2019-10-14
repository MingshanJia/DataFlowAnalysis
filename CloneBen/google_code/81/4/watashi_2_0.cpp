#include <list>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Card {
	int c, s, t;
};

bool operator<(const Card& lhs, const Card& rhs) {
	return lhs.s > rhs.s;
}

bool cmp(const Card& lhs, const Card& rhs) {
	return lhs.c != rhs.c ? lhs.c > rhs.c : lhs.s > rhs.s;
}

int gao(list<Card> a, int n, Card b[], int t) {
	if (a.empty() || t == 0) {
		return 0;
	} else {
		int ret = 0;
		for (list<Card>::iterator it = a.begin(); it != a.end(); ) {
			if (it->t >= 1) {
				for (int i = 1; i <= it->c && i <= n; ++i) {
					a.push_back(b[n - i]);
					n -= i;
				}
				ret += it->s;
				t += it->t - 1;
				it = a.erase(it);
			} else {
				++it;
			}
		}
	//	printf("ret = %d\n", ret);

		int sum = 0;
		a.sort();
		list<Card>::iterator it = a.begin();
		for (int i = 0; i < t && it != a.end(); ++i) {
			sum += it->s;
			++it;
		}

		// int tmp = 0;
		if (!a.empty()) {
			it = min_element(a.begin(), a.end(), cmp);
			if (it->c != 0) {
				for (int i = 1; i <= it->c && i <= n; ++i) {
					a.push_back(b[n - i]);
					n -= i;
				}
				int tmp = it->s;
				a.erase(it);
				sum = max(sum, tmp + gao(a, n, b, t - 1));
				//	tmp += it->s;
				//	t += it->t;
			}
		}
	//	printf("sum = %d\n", sum);

		return ret + sum;
	}
}

int main() {
	int re, n;
	list<Card> lst;
	Card h[100], d[100];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		lst.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &h[i].c, &h[i].s, &h[i].t);
			lst.push_back(h[i]);
		}
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &d[i].c, &d[i].s, &d[i].t);
		}
		reverse(d, d + n);
		printf("Case #%d: %d\n", ri, gao(lst, n, d, 1));
	}

	return 0;
}

